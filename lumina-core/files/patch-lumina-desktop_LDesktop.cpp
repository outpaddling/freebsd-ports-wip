--- lumina-desktop/LDesktop.cpp.orig	2022-02-24 14:41:38 UTC
+++ lumina-desktop/LDesktop.cpp
@@ -35,7 +35,7 @@ LDesktop::LDesktop(int deskNum, bool setdefault) : QOb
   //bgWindow = 0;
   bgDesktop = 0;
   QTimer::singleShot(1,this, SLOT(InitDesktop()) );
-
+  screen = LSession::desktop();
 }
 
 LDesktop::~LDesktop(){
@@ -208,7 +208,7 @@ void LDesktop::InitDesktop(){
   //This is called *once* during the main initialization routines
   checkResolution(); //Adjust the desktop config file first (if necessary)
   if(DEBUG){ qDebug() << "Init Desktop:" << Screen(); }
-    //connect(desktop, SIGNAL(resized(int)), this, SLOT(UpdateGeometry(int)));
+    connect(screen, SIGNAL(resized(int)), this, SLOT(UpdateGeometry(int)));
   if(DEBUG){ qDebug() << "Desktop #"<<Screen()<<" -> "<< QGuiApplication::screens().at(Screen())->availableGeometry() << LSession::handle()->screenGeom(Screen()); }
   deskMenu = new QMenu(0);
     connect(deskMenu, SIGNAL(triggered(QAction*)), this, SLOT(SystemApplication(QAction*)) );
