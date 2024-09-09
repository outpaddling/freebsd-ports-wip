--- src/Mod/Start/Gui/StartView.cpp.orig	2024-09-09 12:22:07 UTC
+++ src/Mod/Start/Gui/StartView.cpp
@@ -123,7 +123,8 @@ StartView::StartView(QWidget* parent)
     connect(firstStartWidget,
             &FirstStartWidget::dismissed,
             this,
-            &StartView::firstStartWidgetDismissed);
+            &StartView::firstStartWidgetDismissed,
+            Qt::QueuedConnection);
     firstStartRegion->addWidget(firstStartWidget);
     firstStartRegion->addStretch();
     _contents->addWidget(firstStartScrollArea);
