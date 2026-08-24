--- src/OpenFOAM/primitives/Scalar/longDoubleScalar/longDoubleScalar.H.orig	2026-08-24 18:14:15 UTC
+++ src/OpenFOAM/primitives/Scalar/longDoubleScalar/longDoubleScalar.H
@@ -151,12 +151,26 @@ inline Scalar jn(const int n, const Scalar s)
 
 inline Scalar jn(const int n, const Scalar s)
 {
+#ifdef __FreeBSD__
+    return static_cast<Scalar>
+    (
+        ::jn(n, static_cast<double>(s))
+    );
+#else
     return ::jnl(n, s);
+#endif
 }
 
 inline Scalar yn(const int n, const Scalar s)
 {
+#ifdef __FreeBSD__
+    return static_cast<Scalar>
+    (
+        ::yn(n, static_cast<double>(s))
+    );
+#else
     return ::ynl(n, s);
+#endif
 }
 
 #undef Scalar
