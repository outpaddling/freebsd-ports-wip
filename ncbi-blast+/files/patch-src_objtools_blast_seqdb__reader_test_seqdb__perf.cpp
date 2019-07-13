--- src/objtools/blast/seqdb_reader/test/seqdb_perf.cpp.orig	2018-10-23 19:28:52 UTC
+++ src/objtools/blast/seqdb_reader/test/seqdb_perf.cpp
@@ -130,7 +130,11 @@ CSeqDBPerfApp::x_ScanDatabase()
     CStopWatch sw;
     sw.Start();
     Uint8 num_letters = m_BlastDb->GetTotalLength();
-    const bool kScanUncompressed = GetArgs()["scan_uncompressed"];
+    // Should be const, but GCC 8 & 9 are incompatible in how they treat
+    // data sharing attributes for const variables.  8 errors out if the
+    // variable is explicitly defined as shared, while 9 requires an
+    // explicit definition.
+    bool kScanUncompressed = GetArgs()["scan_uncompressed"];
     vector<int> oids2iterate;
     for (int oid = 0; m_DbHandles.front()->CheckOrFindOID(oid); oid++) {
         oids2iterate.push_back(oid);
@@ -138,7 +142,7 @@ CSeqDBPerfApp::x_ScanDatabase()
     LOG_POST(Info << "Will go over " << oids2iterate.size() << " sequences");
 
     #pragma omp parallel default(none) num_threads(m_DbHandles.size()) \
-                         shared(oids2iterate) if(m_DbHandles.size() > 1)
+                         shared(oids2iterate,kScanUncompressed) if(m_DbHandles.size() > 1)
     {
         int thread_id = 0;
 #ifdef _OPENMP
