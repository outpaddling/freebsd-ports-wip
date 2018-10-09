--- GEMTools/src/gt_mm.c.orig	2018-10-09 01:20:46 UTC
+++ GEMTools/src/gt_mm.c
@@ -142,14 +142,14 @@ GT_INLINE gt_mm* gt_mm_bulk_mmalloc(cons
    *   - MAP_PRIVATE => Fits in RAM+SWAP
    *   - MAP_ANONYMOUS => The mapping is not backed by any file; its contents are initialized to zero.
    *       Map against /dev/zero (Allocate anonymous memory segment, without open)
-   *   - MAP_NORESERVE to explicitly enable swap space overcommitting. (echo 1 > /proc/sys/vm/overcommit_memory)
+   *   - MAP_NOCORE to explicitly enable swap space overcommitting. (echo 1 > /proc/sys/vm/overcommit_memory)
    *     Useful when you wish to map a file larger than the amount of free memory
    *     available on your system (RAM+SWAP).
    *       In this case, the lazy swap space reservation may cause the program
    *       to consume all the free RAM and swap on the system, eventually
    *       triggering the OOM killer (Linux) or causing a SIGSEGV.
    */
-  int flags = MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE;
+  int flags = MAP_PRIVATE | MAP_ANONYMOUS | MAP_NOCORE;
   if (use_huge_pages) flags |= MAP_HUGETLB;
   mm->memory = mmap(0,num_bytes,PROT_READ|PROT_WRITE,flags,-1,0);
   gt_cond_fatal_error__perror(mm->memory==MAP_FAILED,MEM_ALLOC_MMAP_FAIL,num_bytes);
@@ -215,14 +215,14 @@ GT_INLINE gt_mm* gt_mm_bulk_mmalloc_temp
    * Mmap file.
    *   - MAP_SHARED as we the mapping will be reflected on disk (no copy-on-write)
    *     As such, the kernel knows it can always free up memory by doing writeback.
-   *   - MAP_NORESERVE to explicitly enable swap space overcommitting. (echo 1 > /proc/sys/vm/overcommit_memory)
+   *   - MAP_NOCORE to explicitly enable swap space overcommitting. (echo 1 > /proc/sys/vm/overcommit_memory)
    *     Useful when you wish to map a file larger than the amount of free memory
    *     available on your system (RAM+SWAP).
    *       In this case, the lazy swap space reservation may cause the program
    *       to consume all the free RAM and swap on the system, eventually
    *       triggering the OOM killer (Linux) or causing a SIGSEGV.
    */
-  mm->memory = mmap(NULL,num_bytes,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_NORESERVE,mm->fd,0);
+  mm->memory = mmap(NULL,num_bytes,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_NOCORE,mm->fd,0);
   gt_cond_fatal_error__perror(mm->memory==MAP_FAILED,MEM_ALLOC_MMAP_DISK_FAIL,num_bytes,mm->file_name);
   mm->cursor = mm->memory;
   // Set MM
