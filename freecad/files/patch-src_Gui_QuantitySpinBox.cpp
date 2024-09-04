--- src/Gui/QuantitySpinBox.cpp.orig	2024-09-03 10:34:24 UTC
+++ src/Gui/QuantitySpinBox.cpp
@@ -35,6 +35,8 @@
 # include <QToolTip>
 #endif
 
+// Debug with cerr
+#include <iostream>
 #include <sstream>
 
 #include <App/Application.h>
@@ -431,6 +433,8 @@ void QuantitySpinBox::updateEdit(const QString& text)
 
 void QuantitySpinBox::updateEdit(const QString& text)
 {
+    Base::Console().Message("text argument=%s\n", text.toStdString().c_str());
+
     Q_D(QuantitySpinBox);
 
     QLineEdit* edit = lineEdit();
@@ -441,7 +445,14 @@ void QuantitySpinBox::updateEdit(const QString& text)
 
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
@@ -494,6 +505,8 @@ void QuantitySpinBox::setValue(double value)
 
 void QuantitySpinBox::setValue(double value)
 {
+    std::cerr << "setValue(): value = " << value << '\n';
+
     Q_D(QuantitySpinBox);
 
     Base::QuantityFormat currentformat = d->quantity.getFormat();
@@ -931,6 +944,8 @@ QString QuantitySpinBox::textFromValue(const Base::Qua
     double factor;
     QString unitStr;
     QString str = getUserString(value, factor, unitStr);
+    // Debug
+    std::cerr << "textFromValue(): str = " << str << '\n';
     if (qAbs(value.getValue()) >= 1000.0) {
         str.remove(locale().groupSeparator());
     }
