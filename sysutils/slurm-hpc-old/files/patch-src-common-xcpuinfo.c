--- src/common/xcpuinfo.c.orig	2013-11-04 15:19:15.000000000 -0600
+++ src/common/xcpuinfo.c	2013-12-06 13:05:05.000000000 -0600
@@ -237,7 +237,37 @@
 	}
 	nobj[SOCKET] = hwloc_get_nbobjs_by_type(topology, objtype[SOCKET]);
 	nobj[CORE]   = hwloc_get_nbobjs_by_type(topology, objtype[CORE]);
+	/*
+	 * Workaround for hwloc
+	 * hwloc_get_nbobjs_by_type() returns 0 on some architectures.
+	 */
+	if ( nobj[SOCKET] == 0 )
+	{
+	    debug("Warning: get_cpuinfo() fudging nobj[SOCKET] from 0 to 1.");
+	    nobj[CORE] = 1;
+	}
+	if ( nobj[CORE] == 0 )
+	{
+	    debug("Warning: get_cpuinfi() udging nobj[CORE] from 0 to 1.");
+	    nobj[CORE] = 1;
+	}
+        if ( nobj[SOCKET] == -1 )
+	{
+	    fprintf(stderr,"Uh, oh... get_cpuinfo() doesn't know how to handle nobj[SOCKET]=-1.\n"
+	    exit(EX_SOFTWARE);
+	}
+        if ( nobj[CORE] == -1 )
+	{
+	    fprintf(stderr,"Uh, oh... get_cpuinfo() doesn't know how to handle nobj[CORE]=-1.\n"
+	    exit(EX_SOFTWARE);
+	}
 	actual_cpus  = hwloc_get_nbobjs_by_type(topology, objtype[PU]);
+	/* Used to find workaround above
+        fprintf(stderr, 
+		"CORE = %d SOCKET = %d actual_cpus = %d nobj[CORE] = %d\n",
+		CORE, SOCKET, actual_cpus, nobj[CORE]);
+	fflush(stderr);
+	*/
 	nobj[PU]     = actual_cpus/nobj[CORE];  /* threads per core */
 	nobj[CORE]  /= nobj[SOCKET];            /* cores per socket */
 
