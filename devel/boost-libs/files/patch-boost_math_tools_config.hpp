--- boost/math/tools/config.hpp.orig	2016-09-21 09:33:31.000000000 -0500
+++ boost/math/tools/config.hpp	2016-10-19 13:57:34.065743000 -0500
@@ -28,7 +28,9 @@
 
 #include <boost/math/tools/user.hpp>
 
-#if (defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__NetBSD__) \
+#if (defined(__CYGWIN__) || defined(__NetBSD__) \
+   || (defined(__FreeBSD_version) && (__FreeBSD_version < 1002000 \
+        || (__FreeBSD_version >= 1100000 && __FreeBSD_version < 1100078))) \
    || (defined(__hppa) && !defined(__OpenBSD__)) || (defined(__NO_LONG_DOUBLE_MATH) && (DBL_MANT_DIG != LDBL_MANT_DIG))) \
    && !defined(BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
 #  define BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
