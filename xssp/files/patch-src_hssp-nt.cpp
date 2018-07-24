--- src/hssp-nt.cpp.orig	2018-07-24 16:46:11 UTC
+++ src/hssp-nt.cpp
@@ -474,7 +474,7 @@ void MProfile::AdjustXGapCosts(std::vect
     {
       if (ix + d >= m_residues.size() or
         m_residues[ix + d].m_dist[22] > 0 or
-        ix - d < 0 or
+        (long)(ix - d) < 0 or
         m_residues[ix - d].m_dist[22] > 0)
       {
         gop[ix] *= (2 + ((8 - d) * 2)) / 8.f;
