--- src/common/xcpuinfo.c.orig	2013-11-04 15:19:15.000000000 -0600
+++ src/common/xcpuinfo.c	2013-11-26 13:17:09.000000000 -0600
@@ -236,8 +236,12 @@
 				    1);
 	}
 	nobj[SOCKET] = hwloc_get_nbobjs_by_type(topology, objtype[SOCKET]);
-	nobj[CORE]   = hwloc_get_nbobjs_by_type(topology, objtype[CORE]);
+	/* hwloc_get_nbobjs_by_type returns 0 on some architectures */
+	nobj[CORE]   = MAX(1,hwloc_get_nbobjs_by_type(topology, objtype[CORE]));
 	actual_cpus  = hwloc_get_nbobjs_by_type(topology, objtype[PU]);
+        fprintf(stderr, "CORE = %d SOCKET = %d actual_cpus = %d nobj[CORE] = %d\n",
+		CORE, SOCKET, actual_cpus, nobj[CORE]);
+	fflush(stderr);
 	nobj[PU]     = actual_cpus/nobj[CORE];  /* threads per core */
 	nobj[CORE]  /= nobj[SOCKET];            /* cores per socket */
 
