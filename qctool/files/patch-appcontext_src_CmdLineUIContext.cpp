--- appcontext/src/CmdLineUIContext.cpp.orig	2020-08-09 14:16:58 UTC
+++ appcontext/src/CmdLineUIContext.cpp
@@ -101,7 +101,7 @@ namespace appcontext {
 		}
 	
 		if( total_count ) {	
-			double progress = (total_count == 0) ? 1.0 : (static_cast< double >( count ) / *total_count ) ;
+			double progress = (total_count == 0ul) ? 1.0 : (static_cast< double >( count ) / *total_count ) ;
 			
 			if( count == *total_count ) {
 				m_ui_context.logger()
