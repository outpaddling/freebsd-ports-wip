--- lumina-desktop/LDesktop.cpp.orig	2021-12-26 02:33:45 UTC
+++ lumina-desktop/LDesktop.cpp
@@ -208,7 +208,7 @@ void LDesktop::InitDesktop(){
   //This is called *once* during the main initialization routines
   checkResolution(); //Adjust the desktop config file first (if necessary)
   if(DEBUG){ qDebug() << "Init Desktop:" << Screen(); }
-    //connect(desktop, SIGNAL(resized(int)), this, SLOT(UpdateGeometry(int)));
+    //connect(bgDesktop, SIGNAL(resized(int)), this, SLOT(UpdateGeometry(int)));
   if(DEBUG){ qDebug() << "Desktop #"<<Screen()<<" -> "<< QGuiApplication::screens().at(Screen())->availableGeometry() << LSession::handle()->screenGeom(Screen()); }
   deskMenu = new QMenu(0);
     connect(deskMenu, SIGNAL(triggered(QAction*)), this, SLOT(SystemApplication(QAction*)) );
@@ -223,6 +223,12 @@ void LDesktop::InitDesktop(){
   bgtimer = new QTimer(this);
     bgtimer->setSingleShot(true);
     connect(bgtimer, SIGNAL(timeout()), this, SLOT(UpdateBackground()) );
+    // This doesn't work.  Can we connect multiple handlers to the same signal?
+    // 'Cuz resized() is handled by LPanel
+    // In case the screen resolution changes
+    // Maybe use bgDesktop like above?
+    // QDesktopWidget *screen = LSession::desktop();
+    // connect(screen, SIGNAL(resized(int)), this, SLOT(UpdateBackground()) );
 
     connect(QApplication::instance(), SIGNAL(DesktopConfigChanged()), this, SLOT(SettingsChanged()) );
     connect(QApplication::instance(), SIGNAL(DesktopFilesChanged()), this, SLOT(UpdateDesktop()) );
