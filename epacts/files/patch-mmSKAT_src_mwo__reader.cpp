--- mmSKAT/src/mwo_reader.cpp.orig	2019-01-15 22:39:10 UTC
+++ mmSKAT/src/mwo_reader.cpp
@@ -392,7 +392,7 @@ void MwoFileReader::prepare_out_array_print_snpset_to_
 			//===============================================================
 			//=== This part converts Byte "buff[i]" to bits values "bits_val"
 			//=== for example byte buff[0] = "w" ->  bits_val = 11101110
-			memset(bits_val, NULL, sizeof(bits_val));
+			memset(bits_val, '\0', sizeof(bits_val));
 			int k = MY_CHAR_BIT;  //8
 			while (k > 0)
 			{
