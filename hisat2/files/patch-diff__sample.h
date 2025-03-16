--- diff_sample.h.orig	2020-07-24 20:07:54 UTC
+++ diff_sample.h
@@ -377,7 +377,7 @@ static EList<T> getDeltaMap(T v, const EList<T>& dc) {
 static EList<T> getDeltaMap(T v, const EList<T>& dc) {
 	// Declare anchor-map-related items
 	EList<T> amap;
-	size_t amapEnts = 1;
+	// size_t amapEnts = 1;
 	amap.resizeExact((size_t)v);
 	amap.fill(0xffffffff);
 	amap[0] = 0;
@@ -392,11 +392,11 @@ static EList<T> getDeltaMap(T v, const EList<T>& dc) {
 			assert_lt(diffRight, v);
 			if(amap[diffLeft] == 0xffffffff) {
 				amap[diffLeft] = dc[i];
-				amapEnts++;
+				// amapEnts++;
 			}
 			if(amap[diffRight] == 0xffffffff) {
 				amap[diffRight] = dc[j];
-				amapEnts++;
+				// amapEnts++;
 			}
 		}
 	}
@@ -560,7 +560,9 @@ void DifferenceCoverSample<TStr>::doBuiltSanityCheck()
 	uint32_t v = this->v();
 	assert(built());
 	VMSG_NL("  Doing sanity check");
+	#ifndef NDEBUG
 	TIndexOffU added = 0;
+	#endif
 	EList<TIndexOffU> sorted;
 	sorted.resizeExact(_isaPrime.size());
 	sorted.fill(OFF_MASK);
@@ -571,10 +573,14 @@ void DifferenceCoverSample<TStr>::doBuiltSanityCheck()
 			assert_eq(OFF_MASK, sorted[_isaPrime[doi]]);
 			// Maps the offset of the suffix to its rank
 			sorted[_isaPrime[doi]] = (TIndexOffU)(v*i + d);
+			#ifndef NDEBUG
 			added++;
+			#endif
 		}
 	}
+	#ifndef NDEBUG
 	assert_eq(added, _isaPrime.size());
+	#endif
 #ifndef NDEBUG
 	for(size_t i = 0; i < sorted.size()-1; i++) {
 		assert(sstr_suf_lt(this->text(), sorted[i], this->text(), sorted[i+1], false));
@@ -631,7 +637,9 @@ void DifferenceCoverSample<TStr>::buildSPrime(
 	sPrime.fill(OFF_MASK);
 	// Slot suffixes from text into sPrime according to the mu
 	// mapping; where the mapping would leave a blank, insert a 0
+	#ifndef NDEBUG
 	TIndexOffU added = 0;
+	#endif
 	TIndexOffU i = 0;
 	for(uint64_t ti = 0; ti <= tlen; ti += v) {
 		for(uint32_t di = 0; di < d; di++) {
@@ -642,11 +650,16 @@ void DifferenceCoverSample<TStr>::buildSPrime(
 			assert_leq(tti, tlen);
 			assert_lt(spi, sPrimeSz);
 			assert_eq(OFF_MASK, sPrime[spi]);
-			sPrime[spi] = tti; added++;
+			sPrime[spi] = tti;
+			#ifndef NDEBUG
+			added++;
+			#endif
 		}
 		i++;
 	}
+	#ifndef NDEBUG
 	assert_eq(added, sPrimeSz);
+	#endif
 }
 
 /**
