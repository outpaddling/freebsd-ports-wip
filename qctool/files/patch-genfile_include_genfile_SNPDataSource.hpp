--- genfile/include/genfile/SNPDataSource.hpp.orig	2020-08-09 14:22:09 UTC
+++ genfile/include/genfile/SNPDataSource.hpp
@@ -13,6 +13,7 @@
 #include <map>
 #include "config/config.hpp"
 #include <boost/optional.hpp>
+#include <boost/optional/optional_io.hpp>
 #include <boost/function.hpp>
 #include "genfile/snp_data_utils.hpp"
 #include "genfile/wildcard.hpp"
