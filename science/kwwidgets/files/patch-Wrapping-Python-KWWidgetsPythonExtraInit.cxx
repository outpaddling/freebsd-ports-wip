--- Wrapping/Python/KWWidgetsPythonExtraInit.cxx.orig	2006-08-24 09:36:24.000000000 -0500
+++ Wrapping/Python/KWWidgetsPythonExtraInit.cxx	2012-05-06 20:26:19.000000000 -0500
@@ -88,7 +88,7 @@
 
 // change the old "init" function into a pre-init function
 #define initlibKWWidgetsPython preInitKWWidgetsPython
-#define initKWWidgetsPython preInitKWWidgetsPython
+// #define initKWWidgetsPython preInitKWWidgetsPython
 
 // include the original init file
 #include "KWWidgetsPythonInit.cxx"
@@ -102,6 +102,7 @@
 //----------------------------------------------------------------------------
 static PyObject *PyvtkKWObject_Script(PyObject *self, PyObject *args)
 {
+#if 0
   char          *input;
   const char    *output;
   vtkKWObject   *op;
@@ -175,12 +176,13 @@
     Py_DECREF(format_args);
     Py_DECREF(args);
     }
-
+#endif
   return NULL;
 }
 
 static PyObject *PyvtkKWApplication_Script(PyObject *self, PyObject *args)
 {
+#if 0
   char          *input;
   const char    *output;
   vtkKWApplication *op;
@@ -253,13 +255,14 @@
     Py_DECREF(format_args);
     Py_DECREF(args);
     }
-
+#endif
   return NULL;
 }
 
 static PyObject *PyvtkKWApplication_EvaluateBooleanExpression(PyObject *self,
                                                               PyObject *args)
 {
+#if 0
   char          *input;
   long          output;
   vtkKWApplication *op;
@@ -324,7 +327,7 @@
     Py_DECREF(format_args);
     Py_DECREF(args);
     }
-
+#endif
   return NULL;
 }
 
@@ -418,12 +421,12 @@
       return Py_None;
       }
     }
-
   return NULL;
 }
 
 static PyObject *PyvtkKWApplication_Start(PyObject *self, PyObject *args)
 {
+#if 0
   /* handle signature with no arguments */
   {
   vtkKWApplication *op;
@@ -507,6 +510,7 @@
       }
     }
   }
+#endif
   return NULL;
 }
 
