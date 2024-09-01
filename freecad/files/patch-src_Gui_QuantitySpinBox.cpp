--- src/Gui/QuantitySpinBox.cpp.orig	2024-09-01 17:20:00 UTC
+++ src/Gui/QuantitySpinBox.cpp
@@ -441,6 +441,12 @@ void QuantitySpinBox::updateEdit(const QString& text)
 
     edit->setText(text);
 
+    // Debug issue #16116
+    Base::Console().Message("QLineEdit, size=%i\n", edit->displayText().size());
+    Base::Console().Message("QLineEdit, text=%s\n", edit->displayText().toStdString().c_str());
+    Base::Console().Message("d mystery variable, size=%i\n", d->unitStr.size());
+    Base::Console().Message("d mystery variable, text=%s\n", d->unitStr.toStdString().c_str());
+
     cursor = qBound(0, cursor, edit->displayText().size() - d->unitStr.size());
     if (selsize > 0) {
         edit->setSelection(0, cursor);
