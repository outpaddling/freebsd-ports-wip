--- mmSKAT/src/setid_bim_index.cpp.orig	2019-01-15 22:40:08 UTC
+++ mmSKAT/src/setid_bim_index.cpp
@@ -268,8 +268,8 @@ void Hasht::upload_snpid_from_bim(int * myerror)
 	m_snp_sets = new SNP_info[this->m_num_of_snps];
 	for (int j = 0; j < m_num_of_snps;++j)
 	{
-		this->m_snp_sets[j].letters[0] = NULL;
-		this->m_snp_sets[j].letters[1] = NULL;
+		this->m_snp_sets[j].letters[0] = '\0';
+		this->m_snp_sets[j].letters[1] = '\0';
 		this->m_snp_sets[j].total_counter_per_letter[0] = 0;
 		this->m_snp_sets[j].total_counter_per_letter[1] = 0;
 		this->m_snp_sets[j].line_counter_per_letter[0] = 0;
