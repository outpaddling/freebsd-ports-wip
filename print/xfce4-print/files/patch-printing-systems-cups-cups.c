--- printing-systems/cups/cups.c.orig	2014-04-19 12:20:18.000000000 -0500
+++ printing-systems/cups/cups.c	2014-04-19 12:27:02.000000000 -0500
@@ -133,8 +133,10 @@
 
   language = cupsLangDefault ();
   request = ippNew ();
-  request->request.op.operation_id = operation_id;
-  request->request.op.request_id = 1;
+  //request->request.op.operation_id = operation_id;
+  ippSetOperation(request,operation_id);
+  //request->request.op.request_id = 1;
+  ippSetRequestId(request,1);
 
   ippAddString (request, IPP_TAG_OPERATION, IPP_TAG_CHARSET, "attributes-charset", NULL, "utf-8");
 
@@ -242,7 +244,7 @@
 
       if (!request)
         continue;
-      if (request->state == IPP_ERROR || request->state == IPP_IDLE) {
+      if (ippGetState(request) == IPP_ERROR || request->state == IPP_IDLE) {
         ippDelete (request);
         continue;
       }
