--- pysam/TabProxies.pyx.orig	2015-04-29 09:32:28 UTC
+++ pysam/TabProxies.pyx
@@ -177,6 +177,7 @@ cdef class TupleProxy:
         cdef char * old_pos
         cdef int field
         cdef int max_fields, min_fields, x
+        cdef long signed_nbytes
 
         assert strlen(buffer) == nbytes, \
             "length of buffer (%i) != number of bytes (%i)" % (
@@ -239,8 +240,9 @@ cdef class TupleProxy:
             pos += 1
             self.fields[field] = pos
             field += 1
-            nbytes -= pos - old_pos
-            if nbytes < 0:
+            signed_nbytes -= pos - old_pos
+            nbytes = signed_nbytes
+            if signed_nbytes < 0:
                 break
             old_pos = pos
         self.nfields = field
