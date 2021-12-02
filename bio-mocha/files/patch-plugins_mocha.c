--- plugins/mocha.c.orig	2021-10-15 02:37:57 UTC
+++ plugins/mocha.c
@@ -705,6 +705,44 @@ static double baf_phase_lod(const float *baf_arr, cons
     return (double)ret * M_LOG10E;
 }
 
+typedef struct
+{
+    const float *baf;
+    const int8_t *gt_phase;
+    int n;
+    const int *imap;
+    int8_t *path;
+    float err_log_prb;
+    float baf_sd;
+}   f1_data_t;
+
+double f1(double x, void *data)
+{
+    f1_data_t	*d = data;
+
+    return -baf_phase_lod(d->baf, d->gt_phase, d->n, d->imap, d->path,
+                          d->err_log_prb, d->baf_sd, x);
+}
+
+f1_data_t *f1_pack(const float *baf, const int8_t *gt_phase, int n,
+		   const int *imap, int8_t *path, float err_log_prb,
+		   float baf_sd)
+{
+    // Switch to malloc() and free() if more than one object must exist at
+    // any given time
+    static f1_data_t	d;
+
+    d.baf = baf;
+    d.gt_phase = gt_phase;
+    d.n = n;
+    d.imap = imap;
+    d.path = path;
+    d.err_log_prb = err_log_prb;
+    d.baf_sd = baf_sd;
+
+    return &d;
+}
+
 // TODO find a better title for this function
 static float compare_models(const float *baf, const int8_t *gt_phase, int n, const int *imap, float xy_log_prb,
                             float err_log_prb, float flip_log_prb, float tel_log_prb, float baf_sd, const float *bdev,
@@ -716,8 +754,10 @@ static float compare_models(const float *baf, const in
     int n_flips = 0;
     for (int i = 1; i < n; i++)
         if (path[i - 1] && path[i] && path[i - 1] != path[i]) n_flips++;
-    double f(double x, void *data) { return -baf_phase_lod(baf, gt_phase, n, imap, path, err_log_prb, baf_sd, x); }
-    double x, fx = kmin_brent(f, 0.1, 0.2, NULL, KMIN_EPS, &x);
+    double x;
+    f1_data_t *f1_data = f1_pack(baf, gt_phase, n, imap, path, err_log_prb,
+				 baf_sd);
+    double fx = kmin_brent(f1, 0.1, 0.2, f1_data, KMIN_EPS, &x);
     free(path);
     return -(float)fx + (float)n_flips * flip_log_prb * (float)M_LOG10E;
 }
@@ -1923,6 +1963,32 @@ static float get_lrr_cutoff(const float *v, int n) {
     return cutoff;
 }
 
+typedef struct
+{
+    int16_t *ad0;
+    int16_t *ad1;
+    int n;
+}   f2_data_t;
+
+double f2(double x, void *data)
+{
+    f2_data_t *d = data;
+
+    return -lod_lkl_beta_binomial(d->ad0, d->ad1, d->n, NULL, x);
+}
+
+f2_data_t *f2_pack(int16_t *ad0, int16_t *ad1, int n)
+
+{
+    static f2_data_t d;
+
+    d.ad0 = ad0;
+    d.ad1 = ad1;
+    d.n = n;
+
+    return &d;
+}
+
 // this function computes several contig stats and then clears the contig data from the sample
 static void sample_stats(sample_t *self, const model_t *model) {
     int n = self->n;
@@ -1995,9 +2061,8 @@ static void sample_stats(sample_t *self, const model_t
         hts_expand(stats_t, self->n_stats, self->m_stats, self->stats_arr);
 
         if (model->flags & WGS_DATA) {
-            double f(double x, void *data) { return -lod_lkl_beta_binomial(ad0, ad1, n, NULL, x); }
             double x;
-            kmin_brent(f, 0.1, 0.2, NULL, KMIN_EPS, &x); // dispersions above 0.5 are not allowed
+            kmin_brent(f2, 0.1, 0.2, f2_pack(ad0, ad1, n), KMIN_EPS, &x); // dispersions above 0.5 are not allowed
             self->stats_arr[self->n_stats - 1].dispersion = (float)x;
         } else {
             self->stats_arr[self->n_stats - 1].dispersion = get_sample_sd(baf, n, NULL);
