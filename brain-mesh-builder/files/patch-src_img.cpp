--- src/img.cpp.orig	2021-04-15 21:30:36 UTC
+++ src/img.cpp
@@ -1109,7 +1109,7 @@ void img::thresholdAuto(double cutoff, int nbin, strin
   unsigned char **pxl_tmp=new unsigned char*[rows];
   int i,j,i0=0,i1=0,i2;
   vector<int> local_min, local_max; // local histo min/max
-  vector<int>::iterator it;
+  // Unused vector<int>::iterator it;
   
   string sdum=(tag1=="")?tag:tag1;
 
@@ -1216,7 +1216,7 @@ void img::thresholdHisto(double *cutoff, int nbin, str
   unsigned char **pxl_tmp=new unsigned char*[rows];
   int i,j,i0,i2,imax;
   vector<int> local_min; 
-  vector<int>::iterator it;
+  // Unused vector<int>::iterator it;
   
   string sdum=(tag1=="")?tag:tag1;
 
@@ -1443,7 +1443,7 @@ vector<img>::iterator findImg(string tag)
 void getImgTagRange(stringstream& ss, string *svec)
 {
   string sdum,sdum0,sdum1;
-  size_t found;  char *cdum;
+  size_t found;  char *cdum = nullptr;
   int i,j,k;
   
   svec[0]=vimg.begin()->tag; svec[1]=vimg.rbegin()->tag; // default
