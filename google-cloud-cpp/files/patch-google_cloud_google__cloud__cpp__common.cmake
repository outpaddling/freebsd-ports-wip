--- google/cloud/google_cloud_cpp_common.cmake.orig	2025-08-28 01:18:40 UTC
+++ google/cloud/google_cloud_cpp_common.cmake
@@ -197,7 +197,7 @@ endif ()
     target_link_libraries(google_cloud_cpp_common PUBLIC OpenSSL::Crypto)
 endif ()
 
-if (opentelemetry IN_LIST GOOGLE_CLOUD_CPP_ENABLE)
+if (xxopentelemetry IN_LIST GOOGLE_CLOUD_CPP_ENABLE)
     find_package(opentelemetry-cpp CONFIG)
     if (opentelemetry-cpp_FOUND)
         target_link_libraries(google_cloud_cpp_common
