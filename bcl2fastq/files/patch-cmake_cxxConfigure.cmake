--- cmake/cxxConfigure.cmake.orig	2017-06-22 17:14:50 UTC
+++ cmake/cxxConfigure.cmake
@@ -28,7 +28,7 @@ include(CheckFunctionExists)
 
 bcl2fastq_find_header_or_die(HAVE_INTTYPES_H inttypes.h)
 bcl2fastq_find_header_or_die(HAVE_MALLOC_H malloc.h)
-bcl2fastq_find_header_or_die(HAVE_MCHECK_H mcheck.h)
+# bcl2fastq_find_header_or_die(HAVE_MCHECK_H mcheck.h)
 bcl2fastq_find_header_or_die(HAVE_MEMORY_H memory.h)
 bcl2fastq_find_header_or_die(HAVE_SIGNAL_H signal.h)
 bcl2fastq_find_header_or_die(HAVE_STDINT_H stdint.h)
@@ -85,7 +85,7 @@ else  (HAVE_LIBRT)
 endif (HAVE_LIBRT)
 
 
-bcl2fastq_find_boost(${BCL2FASTQ_BOOST_VERSION} "${BCL2FASTQ_BOOST_COMPONENTS}")
+# bcl2fastq_find_boost(${BCL2FASTQ_BOOST_VERSION} "${BCL2FASTQ_BOOST_COMPONENTS}")
 
 bcl2fastq_find_library(CPGPLOT cpgplot.h cpgplot)
 bcl2fastq_find_library(PGPLOT cpgplot.h pgplot)
