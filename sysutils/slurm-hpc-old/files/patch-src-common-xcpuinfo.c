--- src/common/xcpuinfo.c.orig	2013-11-04 15:19:15.000000000 -0600
+++ src/common/xcpuinfo.c	2013-11-26 14:08:12.000000000 -0600
@@ -237,7 +237,19 @@
 	}
 	nobj[SOCKET] = hwloc_get_nbobjs_by_type(topology, objtype[SOCKET]);
 	nobj[CORE]   = hwloc_get_nbobjs_by_type(topology, objtype[CORE]);
+	/*
+	 * Workaround for hwloc 1.3.1:
+	 * hwloc_get_nbobjs_by_type() returns 0 on some architectures.
+	 */
+	if ( nobj[CORE] == 0 )
+	    nobj[CORE] = 1;
 	actual_cpus  = hwloc_get_nbobjs_by_type(topology, objtype[PU]);
+	/* Used to find workaround above
+        fprintf(stderr, 
+		"CORE = %d SOCKET = %d actual_cpus = %d nobj[CORE] = %d\n",
+		CORE, SOCKET, actual_cpus, nobj[CORE]);
+	fflush(stderr);
+	*/
 	nobj[PU]     = actual_cpus/nobj[CORE];  /* threads per core */
 	nobj[CORE]  /= nobj[SOCKET];            /* cores per socket */
 
