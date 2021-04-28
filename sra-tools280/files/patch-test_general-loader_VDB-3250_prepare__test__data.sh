--- test/general-loader/VDB-3250/prepare_test_data.sh.orig	2017-10-27 02:08:53 UTC
+++ test/general-loader/VDB-3250/prepare_test_data.sh
@@ -160,7 +160,7 @@ test_check_exe LOADER_EXE $BIN_DIR/gener
 #
 cd $TEST_DATA_DIR
 
-_exec make
+_exec gmake
 
 test_check_exe PREPARER_EXE $TEST_BIN_DIR/prepare_test_data
 test_check_exe CHECKER_EXE $TEST_BIN_DIR/check_test_result
