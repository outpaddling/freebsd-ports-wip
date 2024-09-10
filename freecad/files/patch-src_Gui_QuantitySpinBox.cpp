--- src/Gui/QuantitySpinBox.cpp.orig	2024-09-09 12:25:19 UTC
+++ src/Gui/QuantitySpinBox.cpp
@@ -35,6 +35,9 @@
 # include <QToolTip>
 #endif
 
+// Debug with cout
+#include <iostream>
+
 #include <sstream>
 
 #include <App/Application.h>
@@ -385,6 +388,8 @@ void Gui::QuantitySpinBox::setNumberExpression(App::Nu
 
 void Gui::QuantitySpinBox::setNumberExpression(App::NumberExpression* expr)
 {
+    // Debug
+    std::cout << "setNumberExpression() calling updateEdit()...\n";
     updateEdit(getUserString(expr->getQuantity()));
     handlePendingEmit();
 }
@@ -425,12 +430,16 @@ void QuantitySpinBox::updateText(const Quantity &quant
     double dFactor;
     QString txt = getUserString(quant, dFactor, d->unitStr);
     d->unitValue = quant.getValue()/dFactor;
+    // Debug
+    std::cout << "updateText() calling updateEdit()...\n";
     updateEdit(txt);
     handlePendingEmit();
 }
 
 void QuantitySpinBox::updateEdit(const QString& text)
 {
+    Base::Console().Message("updateEdit(): text argument=%s\n", text.toStdString().c_str());
+
     Q_D(QuantitySpinBox);
 
     QLineEdit* edit = lineEdit();
@@ -441,7 +450,15 @@ void QuantitySpinBox::updateEdit(const QString& text)
 
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
+    // cursor = qBound(0, cursor, size);
     if (selsize > 0) {
         edit->setSelection(0, cursor);
     }
@@ -459,6 +476,8 @@ void QuantitySpinBox::validateInput()
     const App::ObjectIdentifier & path = getPath();
     d->validateAndInterpret(text, state, path);
     if (state != QValidator::Acceptable) {
+	// Debug
+	std::cout << "validateInput() calling updateEdit()...\n";
         updateEdit(d->validStr);
     }
 
@@ -494,6 +513,9 @@ void QuantitySpinBox::setValue(double value)
 
 void QuantitySpinBox::setValue(double value)
 {
+    // Debug
+    std::cout << "setValue(): value = " << value << '\n';
+
     Q_D(QuantitySpinBox);
 
     Base::QuantityFormat currentformat = d->quantity.getFormat();
@@ -931,6 +953,8 @@ QString QuantitySpinBox::textFromValue(const Base::Qua
     double factor;
     QString unitStr;
     QString str = getUserString(value, factor, unitStr);
+    // Debug
+    std::cout << "textFromValue(): str = " << str.toStdString() << '\n';
     if (qAbs(value.getValue()) >= 1000.0) {
         str.remove(locale().groupSeparator());
     }
