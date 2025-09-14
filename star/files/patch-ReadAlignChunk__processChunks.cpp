--- ReadAlignChunk_processChunks.cpp.orig	2025-07-27 22:19:17 UTC
+++ ReadAlignChunk_processChunks.cpp
@@ -190,6 +190,8 @@ void ReadAlignChunk::processChunks() {//read-map-write
                         chunkInSizeBytesTotal[imate] ++;
                     };
                 } else if (nextChar==' ' || nextChar=='\n' || !P.inOut->readIn[0].good()) {//end of stream
+		    // Debug clang 0 reads
+		    P.inOut->logMain << "P.inOut->readIn[0].good() = " << P.inOut->readIn[0].good() << endl;
                     P.inOut->logMain << "Thread #" <<iThread <<" end of input stream, nextChar="<<int(nextChar) <<endl;
                     break;
                 } else {
