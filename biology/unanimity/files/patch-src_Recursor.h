--- src/Recursor.h.orig	2016-10-02 07:48:21.000000000 -0500
+++ src/Recursor.h	2016-10-02 07:52:52.000000000 -0500
@@ -728,7 +728,7 @@ size_t Recursor<Derived>::FillAlphaBeta(
     size_t J = tpl_->Length();
     int flipflops = 0;
     size_t maxSize =
-        std::max(100ul, static_cast<size_t>(0.5 + REBANDING_THRESHOLD * (I + 1) * (J + 1)));
+        std::max(100u, static_cast<size_t>(0.5 + REBANDING_THRESHOLD * (I + 1) * (J + 1)));
 
     // if we use too much space, do at least one more round
     // to take advantage of rebanding
