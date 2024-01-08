--- threadpoolctl.py.orig	2023-07-13 14:44:13 UTC
+++ threadpoolctl.py
@@ -66,6 +66,7 @@ try:
 except AttributeError:
     _RTLD_NOLOAD = ctypes.DEFAULT_MODE
 
+_RTLD_DEFAULT=-2
 
 class LibController(ABC):
     """Abstract base class for the individual library controllers
@@ -818,8 +819,63 @@ class ThreadpoolController:
             self._find_libraries_with_dyld()
         elif sys.platform == "win32":
             self._find_libraries_with_enum_process_module_ex()
+        elif "freebsd" in sys.platform:
+            self._find_libraries_with_dl_iterate_phdr_freebsd()
         else:
             self._find_libraries_with_dl_iterate_phdr()
+
+    def _find_libraries_with_dl_iterate_phdr_freebsd(self):
+        """Loop through loaded libraries and return binders on supported ones
+
+        This function is expected to work on POSIX system only.
+        This code is adapted from code by Intel developer @anton-malakhov
+        available at https://github.com/IntelPython/smp
+
+        Copyright (c) 2017, Intel Corporation published under the BSD 3-Clause
+        license
+        """
+       
+ 
+        parent = ctypes.CDLL(None)
+    
+        dlopen = parent.dlopen
+        dlopen.restype = ctypes.c_void_p
+
+        dlsym = parent.dlsym
+        dlsym.restype = ctypes.c_void_p
+
+        dl_iterate_phdr_ptr = dlsym(_RTLD_DEFAULT, b'dl_iterate_phdr')
+
+        if dl_iterate_phdr_ptr == 0:
+            return []
+
+        # Callback function for `dl_iterate_phdr` which is called for every
+        # library loaded in the current process until it returns 1.
+        def match_library_callback(info, size, data):
+            # Get the path of the current library
+            filepath = info.contents.dlpi_name
+            if filepath:
+                filepath = filepath.decode("utf-8")
+
+                # Store the library controller if it is supported and selected
+                self._make_controller_from_path(filepath)
+            return 0
+
+        c_func_signature = ctypes.CFUNCTYPE(
+            ctypes.c_int,  # Return type
+            ctypes.POINTER(_dl_phdr_info),
+            ctypes.c_size_t,
+            ctypes.c_char_p,
+        )
+        c_match_library_callback = c_func_signature(match_library_callback)
+
+        data = ctypes.c_char_p(b"")
+
+        dl_iterate_phdr_c_signature = ctypes.CFUNCTYPE(ctypes.c_int, ctypes.c_void_p, ctypes.c_void_p)
+        dl_iterate_phdr_c_signature.argtypes = [ c_func_signature, ctypes.c_void_p ]
+        dl_iterate_phdr =  dl_iterate_phdr_c_signature(dl_iterate_phdr_ptr)
+
+        dl_iterate_phdr(c_match_library_callback, data)
 
     def _find_libraries_with_dl_iterate_phdr(self):
         """Loop through loaded libraries and return binders on supported ones
