--- alignment/ipc/SharedMemoryAllocator.hpp.orig	2016-09-08 16:06:59 UTC
+++ alignment/ipc/SharedMemoryAllocator.hpp
@@ -7,6 +7,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/mman.h>
+#include <sys/stat.h>
 
 template<typename T_Data>
 int AllocateMappedShare(std::string &handle, int dataLength, T_Data *&dataPtr, int &shmId) {
