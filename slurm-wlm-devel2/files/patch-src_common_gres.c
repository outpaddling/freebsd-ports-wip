--- src/common/gres.c.orig	2021-09-21 13:39:26 UTC
+++ src/common/gres.c
@@ -76,7 +76,9 @@ typedef cpuset_t cpu_set_t;
 #include "slurm/slurm_errno.h"
 #include "src/common/assoc_mgr.h"
 #include "src/common/bitstring.h"
+#ifdef __linux__
 #include "src/common/cgroup.h"
+#endif
 #include "src/common/gres.h"
 #include "src/common/job_resources.h"
 #include "src/common/list.h"
@@ -406,9 +408,11 @@ extern bool gres_use_local_device_index(void)
 	if (!use_cgroup)
 		return use_local_index;
 
+#ifdef __linux__
 	cgroup_conf_init();
 	if (slurm_cgroup_conf.constrain_devices)
 		use_local_index = true;
+#endif
 
 	return use_local_index;
 }
