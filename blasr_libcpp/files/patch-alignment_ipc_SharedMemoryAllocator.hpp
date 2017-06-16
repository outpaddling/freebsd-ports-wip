--- alignment/ipc/SharedMemoryAllocator.hpp.orig	2015-08-12 17:41:23 UTC
+++ alignment/ipc/SharedMemoryAllocator.hpp
@@ -7,6 +7,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/mman.h>
+#include <sys/stat.h>
 
 template<typename T_Data>
 int AllocateMappedShare(std::string &handle, int dataLength, T_Data *&dataPtr, int &shmId) {
