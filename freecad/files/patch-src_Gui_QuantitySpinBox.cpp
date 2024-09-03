--- src/Gui/QuantitySpinBox.cpp.orig	2024-09-01 17:20:00 UTC
+++ src/Gui/QuantitySpinBox.cpp
@@ -35,6 +35,8 @@
 # include <QToolTip>
 #endif
 
+// Debug with cerr
+#include <iostream>
 #include <sstream>
 
 #include <App/Application.h>
@@ -441,7 +443,14 @@ void QuantitySpinBox::updateEdit(const QString& text)
 
     edit->setText(text);
 
-    cursor = qBound(0, cursor, edit->displayText().size() - d->unitStr.size());
+    // Debug issue #16116
+    Base::Console().Message("QLineEdit, size=%i\n", edit->displayText().size());
+    Base::Console().Message("QLineEdit, text=%s\n", edit->displayText().toStdString().c_str());
+    Base::Console().Message("d mystery variable, size=%i\n", d->unitStr.size());
+    Base::Console().Message("d mystery variable, text=%s\n", d->unitStr.toStdString().c_str());
+
+    int size = edit->displayText().size() - d->unitStr.size();
+    cursor = qBound(0, cursor, size < 0 ? 0 : size);
     if (selsize > 0) {
         edit->setSelection(0, cursor);
     }
@@ -494,6 +503,8 @@ void QuantitySpinBox::setValue(double value)
 
 void QuantitySpinBox::setValue(double value)
 {
+    std::cerr << "setValue(): value = " << value << '\n';
+
     Q_D(QuantitySpinBox);
 
     Base::QuantityFormat currentformat = d->quantity.getFormat();
