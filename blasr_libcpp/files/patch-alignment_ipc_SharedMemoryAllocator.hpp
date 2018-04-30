--- alignment/ipc/SharedMemoryAllocator.hpp.orig	2018-04-30 02:47:55 UTC
+++ alignment/ipc/SharedMemoryAllocator.hpp
@@ -4,6 +4,7 @@
 #include <cerrno>
 #include <fcntl.h>
 #include <sys/mman.h>
+#include <sys/stat.h>
 #include <unistd.h>
 #include <iostream>
 #include <string>
