# Type mismatch on 11.0 i386
--- src/Recursor.h.orig	2016-09-12 19:55:43 UTC
+++ src/Recursor.h
@@ -728,7 +728,7 @@ size_t Recursor<Derived>::FillAlphaBeta(
     size_t J = tpl_->Length();
     int flipflops = 0;
     size_t maxSize =
-        std::max(100ul, static_cast<size_t>(0.5 + REBANDING_THRESHOLD * (I + 1) * (J + 1)));
+        std::max(100ul, static_cast<unsigned long>(0.5 + REBANDING_THRESHOLD * (I + 1) * (J + 1)));
 
     // if we use too much space, do at least one more round
     // to take advantage of rebanding
