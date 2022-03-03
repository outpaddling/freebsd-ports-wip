--- lumina-desktop/src-screensaver/LLockScreen.cpp.orig	2022-03-03 00:00:21 UTC
+++ lumina-desktop/src-screensaver/LLockScreen.cpp
@@ -80,6 +80,7 @@ void LLockScreen::TryUnlock(){
   QString pass = ui->line_password->text();
     ui->line_password->clear();
   //Create a temporary file for the password, then pass that file descriptor to lumina-checkpass
+  // Might seem wacky to shell this out, but we need SUID to authenticate the pw with PAM
   QTemporaryFile *TF = new QTemporaryFile(".XXXXXXXXXX");
   TF->setAutoRemove(true);
   bool ok = false;
