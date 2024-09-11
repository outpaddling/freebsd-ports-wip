--- src/Mod/Start/Gui/StartView.cpp.orig	2024-09-11 12:24:39 UTC
+++ src/Mod/Start/Gui/StartView.cpp
@@ -117,7 +117,11 @@ StartView::StartView(QWidget* parent)
 
     // First start page
     auto firstStartScrollArea = gsl::owner<QScrollArea*>(new QScrollArea());
-    auto firstStartRegion = gsl::owner<QHBoxLayout*>(new QHBoxLayout(firstStartScrollArea));
+    auto firstStartScrollWidget = gsl::owner<QWidget*>(new QWidget(firstStartScrollArea));
+    firstStartScrollArea->setWidget(firstStartScrollWidget);
+    firstStartScrollArea->setWidgetResizable(true);
+
+    auto firstStartRegion = gsl::owner<QHBoxLayout*>(new QHBoxLayout(firstStartScrollWidget));
     firstStartRegion->addStretch();
     auto firstStartWidget = gsl::owner<FirstStartWidget*>(new FirstStartWidget(this));
     connect(firstStartWidget,
