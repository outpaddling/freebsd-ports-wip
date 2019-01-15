--- mmSKAT/src/bed_reader.cpp.orig	2019-01-15 22:35:59 UTC
+++ mmSKAT/src/bed_reader.cpp
@@ -258,8 +258,8 @@ BedFileReader::BedFileReader(char* filename, char* bim
 	m_snp_sets = new SNP_info[m_approx_line_lenght];
 	for (int j = 0; j < m_approx_line_lenght;++j)
 	{
-		this->m_snp_sets[j].letters[0] = NULL;
-		this->m_snp_sets[j].letters[1] = NULL;
+		this->m_snp_sets[j].letters[0] = '\0';
+		this->m_snp_sets[j].letters[1] = '\0';
 		this->m_snp_sets[j].total_counter_per_letter[0] = 0;
 		this->m_snp_sets[j].total_counter_per_letter[1] = 0;
 		this->m_snp_sets[j].line_counter_per_letter[0] = 0;
@@ -394,7 +394,7 @@ void BedFileReader::read_data_and_create_mwo_used_hash
 		{	//===============================================================					
 			//=== This part converts Byte "buff[i]" to bits values "bits_val"
 			//=== for example byte buff[0] = "w" ->  bits_val = 11101110
-			memset(bits_val, NULL, sizeof(bits_val));
+			memset(bits_val, '\0', sizeof(bits_val));
 			int k = MY_CHAR_BIT;  //8
 			while (k > 0)
 			{
@@ -581,7 +581,7 @@ void BedFileReader::read_data_and_update_temp_file(int
 			//===============================================================					
 			//=== This part converts Byte "buff[i]" to bits values "bits_val"
 			//=== for example byte buff[0] = "w" ->  bits_val = 11101110
-			memset(bits_val, NULL, sizeof(bits_val));
+			memset(bits_val, '\0', sizeof(bits_val));
 			int j = MY_CHAR_BIT;  //8
 			while (j > 0)
 			{
