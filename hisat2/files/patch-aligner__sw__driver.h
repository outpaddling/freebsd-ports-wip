--- aligner_sw_driver.h.orig	2025-03-17 23:44:07 UTC
+++ aligner_sw_driver.h
@@ -1594,7 +1594,7 @@ int SwDriver<index_t>::extendSeeds(
 						swmSeed.ungapsucc++;
 					}
 				}
-				int64_t pastedRefoff = (int64_t)wr.toff - rdoff;
+				// int64_t pastedRefoff = (int64_t)wr.toff - rdoff;
 				DPRect rect;
 				if(state == FOUND_NONE) {
 					found = dpframe.frameSeedExtensionRect(
@@ -1613,7 +1613,7 @@ int SwDriver<index_t>::extendSeeds(
 						continue;
 					}
 				}
-				int64_t leftShift = refoff - rect.refl;
+				// int64_t leftShift = refoff - rect.refl;
 				size_t nwindow = 0;
 				if(toff >= rect.refl) {
 					nwindow = (size_t)(toff - rect.refl);
@@ -1621,7 +1621,7 @@ int SwDriver<index_t>::extendSeeds(
 				// NOTE: We might be taking off more than we should because the
 				// pasted string omits non-A/C/G/T characters, but we included them
 				// when calculating leftShift.  We'll account for this later.
-				pastedRefoff -= leftShift;
+				// pastedRefoff -= leftShift;
 				size_t nsInLeftShift = 0;
 				if(state == FOUND_NONE) {
 					if(!swa.initedRead()) {
@@ -2292,7 +2292,7 @@ int SwDriver<index_t>::extendSeedsPaired(
 						swmSeed.ungapsucc++;
 					}
 				}
-				int64_t pastedRefoff = (int64_t)wr.toff - rdoff;
+				// int64_t pastedRefoff = (int64_t)wr.toff - rdoff;
 				DPRect rect;
 				if(state == FOUND_NONE) {
 					found = dpframe.frameSeedExtensionRect(
@@ -2311,7 +2311,7 @@ int SwDriver<index_t>::extendSeedsPaired(
 						continue;
 					}
 				}
-				int64_t leftShift = refoff - rect.refl;
+				// int64_t leftShift = refoff - rect.refl;
 				size_t nwindow = 0;
 				if(toff >= rect.refl) {
 					nwindow = (size_t)(toff - rect.refl);
@@ -2319,7 +2319,7 @@ int SwDriver<index_t>::extendSeedsPaired(
 				// NOTE: We might be taking off more than we should because the
 				// pasted string omits non-A/C/G/T characters, but we included them
 				// when calculating leftShift.  We'll account for this later.
-				pastedRefoff -= leftShift;
+				// pastedRefoff -= leftShift;
 				size_t nsInLeftShift = 0;
 				if(state == FOUND_NONE) {
 					if(!swa.initedRead()) {
