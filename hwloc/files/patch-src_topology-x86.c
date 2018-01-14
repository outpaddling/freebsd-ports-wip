--- src/topology-x86.c.orig	2017-04-19 10:19:38.000000000 -0500
+++ src/topology-x86.c	2018-01-14 11:19:18.712933000 -0600
@@ -248,6 +248,9 @@ static void look_proc(struct hwloc_backe
   if (cpuid_type != intel && has_topoext(features)) {
     unsigned apic_id, node_id, nodes_per_proc;
 
+    /* the code below doesn't want any other cache yet */
+    assert(!infos->numcaches);
+
     eax = 0x8000001e;
     hwloc_x86_cpuid(&eax, &ebx, &ecx, &edx);
     infos->apicid = apic_id = eax;
@@ -355,6 +358,9 @@ static void look_proc(struct hwloc_backe
    */
   if (cpuid_type != amd && highest_cpuid >= 0x04) {
     unsigned level;
+
+    unsigned oldnumcaches = infos->numcaches; /* in case we got caches above */
+
     for (cachenum = 0; ; cachenum++) {
       unsigned type;
       eax = 0x04;
@@ -384,7 +390,8 @@ static void look_proc(struct hwloc_backe
       }
     }
 
-    cache = infos->cache = malloc(infos->numcaches * sizeof(*infos->cache));
+    infos->cache = realloc(infos->cache, infos->numcaches * sizeof(*infos->cache));
+    cache = &infos->cache[oldnumcaches];
 
     for (cachenum = 0; ; cachenum++) {
       unsigned long linesize, linepart, ways, sets;
@@ -1040,6 +1047,10 @@ int hwloc_look_x86(struct hwloc_backend 
   eax = 0x00;
   hwloc_x86_cpuid(&eax, &ebx, &ecx, &edx);
   highest_cpuid = eax;
+  /* printf("got vendor %c%c%c%c%c%c%c%c%c%c%c%c\n",
+	 ebx&0xff, (ebx>>8)&0xff, (ebx>>16)&0xff, (ebx>>24)&0xff,
+	 edx&0xff, (edx>>8)&0xff, (edx>>16)&0xff, (edx>>24)&0xff,
+	 ecx&0xff, (ecx>>8)&0xff, (ecx>>16)&0xff, (ecx>>24)&0xff); */
   if (ebx == INTEL_EBX && ecx == INTEL_ECX && edx == INTEL_EDX)
     cpuid_type = intel;
   if (ebx == AMD_EBX && ecx == AMD_ECX && edx == AMD_EDX)
