--- lumina-checkpass/main.c.orig	2022-03-03 15:51:53 UTC
+++ lumina-checkpass/main.c
@@ -42,6 +42,7 @@ void showUsage(){
     puts("  lumina-checkpass -fd <file descriptor>");
     puts("  lumina-checkpass -f <file path>");
     puts("Returns: 0 for a valid password, 1 for invalid");
+    exit(1);	// FIXME: Switch to EX_USAGE, or do callers depend on 1?
 }
 
 int main(int argc, char** argv){
@@ -49,10 +50,16 @@ int main(int argc, char** argv){
   if(argc!=3){
     //Invalid inputs - show the help text
     showUsage();
-    return 1;
   }
   char*pass = 0;
   if(argc==3 && 0==strcmp(argv[1],"-fd") ){
+    char *end;
+    int fd = strtol(argv[2], &end, 10);
+    if ( *end != '\0' )
+    {
+      fprintf(stderr, "Invalid file descriptor: %s\n", argv[2]);
+      showUsage();
+    }
     FILE *fp = fdopen(atoi(argv[2]), "r");
     size_t len;
     if(fp!=0){
@@ -70,7 +77,6 @@ int main(int argc, char** argv){
       puts("[ERROR] Unknown option provided");
       puts("----------------");
       showUsage();
-      return 1;
     }
     fclose(fp);
   }
