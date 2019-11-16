--- src/FreqPhase.cpp.orig	2019-11-13 14:19:06 UTC
+++ src/FreqPhase.cpp
@@ -180,10 +180,16 @@ double FreqPhase::meanValue(const std::vector<double>&
 double FreqPhase::medianValue(const std::vector<double>& values) {
 	double median;
 	size_t size = values.size();
+
+	if ( size == 0 ) {
+		std::cerr << "FreqPhase::medianValue(): values vector is empty." << endl;
+		std::cerr << "Make sure your VCF has all of GT:AD:DP." << endl;
+		exit(EX_DATAERR);
+	}
 	std::vector<double> tempFreqs(values);
 	sort(tempFreqs.begin(), tempFreqs.end());
 
-	if (size  % 2 == 0) {
+	if (size % 2 == 0) {
 		median = (tempFreqs[size / 2 - 1] + tempFreqs[size / 2]) / 2;
 	}
 	else {
