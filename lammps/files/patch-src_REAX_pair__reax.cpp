--- src/REAX/pair_reax.cpp.orig	2016-12-12 13:14:29.406491595 -0600
+++ src/REAX/pair_reax.cpp	2016-12-12 13:14:40.235487811 -0600
@@ -269,7 +269,7 @@ void PairREAX::write_reax_positions()
   double **x = atom->x;
   double *q = atom->q;
   int *type = atom->type;
-  int *tag = atom->tag;
+  tagint *tag = atom->tag;
   int nlocal = atom->nlocal;
   int nghost = atom->nghost;
 
@@ -312,7 +312,7 @@ void PairREAX::write_reax_vlist()
   double delx, dely, delz;
 
   double **x = atom->x;
-  int *tag = atom->tag;
+  tagint *tag = atom->tag;
   int nlocal = atom->nlocal;
   int nghost = atom->nghost;
 
@@ -759,7 +759,7 @@ void PairREAX::compute_charge(double &en
   double **x = atom->x;
   double *q = atom->q;
   int *type = atom->type;
-  int *tag = atom->tag;
+  tagint *tag = atom->tag;
 
   int nlocal = atom->nlocal;
   int nghost = atom->nghost;
