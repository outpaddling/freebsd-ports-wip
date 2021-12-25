--- lumina-config/pages/page_fluxbox_settings.cpp.orig	2021-10-02 19:05:49 UTC
+++ lumina-config/pages/page_fluxbox_settings.cpp
@@ -33,6 +33,8 @@ page_fluxbox_settings::~page_fluxbox_settings(){
 //================
 void page_fluxbox_settings::SaveSettings(){
   QStringList FB;
+  QStringList FBNS;
+    FBNS = readFile(QString(getenv("XDG_CONFIG_HOME"))+"/lumina-desktop/fluxbox-init -no-slit");
   if(ui->radio_simple->isChecked()){
     FB = readFile(QString(getenv("XDG_CONFIG_HOME"))+"/lumina-desktop/fluxbox-init");
     // - window placement
@@ -46,6 +48,11 @@ void page_fluxbox_settings::SaveSettings(){
     if(index < 0){ FB << line; } //add line to the end of the file
     else{ FB[index] = line; } //replace the current setting with the new one
     // - window theme
+    index = FBNS.indexOf( FBNS.filter("session.styleFile:").join("") );
+    line = "session.styleFile:\t"+ui->combo_session_wtheme->itemData( ui->combo_session_wtheme->currentIndex() ).toString();
+    if(index < 0){ FBNS << line; } //add line to the end of the file
+    else{ FBNS[index] = line; } //replace the current setting with the new one
+    // - window theme lumina-config
     index = FB.indexOf( FB.filter("session.styleFile:").join("") );
     line = "session.styleFile:\t"+ui->combo_session_wtheme->itemData( ui->combo_session_wtheme->currentIndex() ).toString();
     if(index < 0){ FB << line; } //add line to the end of the file
@@ -61,6 +68,7 @@ void page_fluxbox_settings::SaveSettings(){
   }
   //Save the fluxbox settings
   bool ok = overwriteFile(QString(getenv("XDG_CONFIG_HOME"))+"/lumina-desktop/fluxbox-init", FB);
+  overwriteFile(QString(getenv("XDG_CONFIG_HOME"))+"/lumina-desktop/fluxbox-init -no-slit", FBNS);
   if(!ok){ qDebug() << "Warning: Could not save fluxbox-init"; }
   emit HasPendingChanges(false);
 }
