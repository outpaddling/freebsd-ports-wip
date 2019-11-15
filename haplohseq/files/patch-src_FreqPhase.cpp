--- src/FreqPhase.cpp.orig	2019-11-13 14:19:06 UTC
+++ src/FreqPhase.cpp
@@ -183,6 +183,7 @@ double FreqPhase::medianValue(const std:
 	std::vector<double> tempFreqs(values);
 	sort(tempFreqs.begin(), tempFreqs.end());
 
+	std::cerr << "size = " << size << '\n';
 	if (size  % 2 == 0) {
 		median = (tempFreqs[size / 2 - 1] + tempFreqs[size / 2]) / 2;
 	}
