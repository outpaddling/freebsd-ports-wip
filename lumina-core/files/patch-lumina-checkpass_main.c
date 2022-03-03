--- lumina-checkpass/main.c.orig	2022-03-03 15:51:53 UTC
+++ lumina-checkpass/main.c
@@ -30,7 +30,7 @@ static int PAM_conv(
 	struct pam_response **resp,
 	void *ctx)
 {
-	return 0;
+	return PAM_SUCCESS;
 }
 //-----
 
@@ -42,6 +42,7 @@ void showUsage(){
     puts("  lumina-checkpass -fd <file descriptor>");
     puts("  lumina-checkpass -f <file path>");
     puts("Returns: 0 for a valid password, 1 for invalid");
+    exit(1);	// FIXME: Switch to EX_USAGE, or do callers depend on 1?
 }
 
 int main(int argc, char** argv){
@@ -49,13 +50,20 @@ int main(int argc, char** argv){
   if(argc!=3){
     //Invalid inputs - show the help text
     showUsage();
-    return 1;
   }
-  char*pass = 0;
+  char *pass = NULL;
   if(argc==3 && 0==strcmp(argv[1],"-fd") ){
+    // This replaces dangerous atoi(), which does no validation
+    char *end;
+    int fd = strtol(argv[2], &end, 10);
+    if ( *end != '\0' )
+    {
+      fprintf(stderr, "Invalid file descriptor: %s\n", argv[2]);
+      showUsage();
+    }
     FILE *fp = fdopen(atoi(argv[2]), "r");
     size_t len;
-    if(fp!=0){
+    if(fp!=NULL){
       ssize_t slen = getline(&pass, &len, fp);
       if(pass[slen-1]=='\n'){ pass[slen-1] = '\0'; }
     }
@@ -63,25 +71,24 @@ int main(int argc, char** argv){
   }else if(argc==3 && 0==strcmp(argv[1],"-f") ){
     FILE *fp = fopen(argv[2], "r");
     size_t len;
-    if(fp!=0){
+    if(fp!=NULL){
       ssize_t slen = getline(&pass, &len, fp);
       if(pass[slen-1]=='\n'){ pass[slen-1] = '\0'; }
     }else{
       puts("[ERROR] Unknown option provided");
       puts("----------------");
       showUsage();
-      return 1;
     }
     fclose(fp);
   }
-  if(pass == 0){ puts("Could not read password!!"); return 1; } //error in reading password
+  if(pass == NULL){ puts("Could not read password!!"); return 1; } //error in reading password
   //puts("Read Password:");
   //puts(pass);
   //Validate current user (make sure current UID matches the logged-in user,
   char* cUser = getlogin();
-  struct passwd *pwd = 0;
+  struct passwd *pwd = NULL;
   pwd = getpwnam(cUser);
-  if(pwd==0){ return 1; } //Login user could not be found in the database? (should never happen)
+  if(pwd==NULL){ return 1; } //Login user could not be found in the database? (should never happen)
   if( getuid() != pwd->pw_uid ){ return 1; } //Current UID does not match currently logged-in user UID
   //Create the non-interactive PAM structures
   pam_handle_t *pamh;
@@ -102,5 +109,5 @@ int main(int argc, char** argv){
     //Stop the PAM instance
     pam_end(pamh,ret);
   //return verification result
-  return ((ret==PAM_SUCCESS) ? 0 : 1);
+  return ret == PAM_SUCCESS ? 0 : 1;	// 0 exit status = success
 }
