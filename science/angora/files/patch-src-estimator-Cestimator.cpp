--- src/estimator/Cestimator.cpp.orig	2012-06-02 18:02:05.000000000 -0500
+++ src/estimator/Cestimator.cpp	2012-06-02 18:08:51.000000000 -0500
@@ -31,7 +31,7 @@
 #else
 #define FDTD_GETTIME ntp_gettime
 #define FDTD_SEC time.tv_sec
-#define FDTD_FRACSEC time.tv_usec
+#define FDTD_FRACSEC time.tv_nsec
 //FIXME: This is a quick, dirty (and incorrect) fix to the nanosecond-microsecond bug for this Linux kernel (tv_usec returns nanosec values)
 //#ifdef STA_NANO  //should be removed once tv_usec returns microseconds again in the future (as it should!!!)
 // #define FDTD_TIMECONVERSION 1000000000  //should be removed once tv_usec returns microseconds again in the future (as it should!!!)
