--- libcpp/alignment/ipc/SharedMemoryAllocator.hpp.orig	2015-08-17 13:05:57.000000000 -0500
+++ libcpp/alignment/ipc/SharedMemoryAllocator.hpp	2015-08-17 13:06:07.000000000 -0500
@@ -7,6 +7,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/mman.h>
+#include <sys/stat.h>
 
 template<typename T_Data>
 int AllocateMappedShare(std::string &handle, int dataLength, T_Data *&dataPtr, int &shmId) {
