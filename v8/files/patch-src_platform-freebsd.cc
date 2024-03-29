--- src/platform-freebsd.cc.orig	2020-06-09 19:11:42 UTC
+++ src/platform-freebsd.cc
@@ -343,7 +343,7 @@ VirtualMemory::VirtualMemory(size_t size, size_t align
   void* reservation = mmap(OS::GetRandomMmapAddr(),
                            request_size,
                            PROT_NONE,
-                           MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                           MAP_PRIVATE | MAP_ANON | MAP_RESERVED0040,
                            kMmapFd,
                            kMmapFdOffset);
   if (reservation == MAP_FAILED) return;
@@ -415,7 +415,7 @@ void* VirtualMemory::ReserveRegion(size_t size) {
   void* result = mmap(OS::GetRandomMmapAddr(),
                       size,
                       PROT_NONE,
-                      MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                      MAP_PRIVATE | MAP_ANON | MAP_RESERVED0040,
                       kMmapFd,
                       kMmapFdOffset);
 
@@ -445,7 +445,7 @@ bool VirtualMemory::UncommitRegion(void* base, size_t 
   return mmap(base,
               size,
               PROT_NONE,
-              MAP_PRIVATE | MAP_ANON | MAP_NORESERVE | MAP_FIXED,
+              MAP_PRIVATE | MAP_ANON | MAP_RESERVED0040 | MAP_FIXED,
               kMmapFd,
               kMmapFdOffset) != MAP_FAILED;
 }
