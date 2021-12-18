--- utgcns/libboost/boost/smart_ptr/detail/sp_counted_impl.hpp.orig	2021-12-18 00:17:43 UTC
+++ utgcns/libboost/boost/smart_ptr/detail/sp_counted_impl.hpp
@@ -26,6 +26,7 @@
 
 #include <boost/checked_delete.hpp>
 #include <boost/smart_ptr/detail/sp_counted_base.hpp>
+#include <boost/detail/sp_typeinfo.hpp>
 
 #if defined(BOOST_SP_USE_QUICK_ALLOCATOR)
 #include <boost/smart_ptr/detail/quick_allocator.hpp>
