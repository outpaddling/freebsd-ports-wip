--- lefsebiom/AbundanceTable.py.orig	2019-10-05 15:40:19 UTC
+++ lefsebiom/AbundanceTable.py
@@ -353,7 +353,7 @@ class AbundanceTable:
 
 		#Validate parameters
 		if (iFirstDataIndex == -1) and (sLastMetadataName == None):
-			print "AbundanceTable:checkRawDataFile::Error, either iFirstDataIndex or sLastMetadataNamemust be given."
+			print("AbundanceTable:checkRawDataFile::Error, either iFirstDataIndex or sLastMetadataNamemust be given.")
 			return False
 
 		#Get output file and remove if existing
@@ -815,7 +815,7 @@ class AbundanceTable:
 		# Check number of input data rows
 		iDataRows = npdData.shape[0]
 		if (len(lsNames) != iDataRows):
-			print "Error:The names and the rows of data features to add must be of equal length"
+			print("Error:The names and the rows of data features to add must be of equal length")
 
 		# Grow the array by the neccessary amount and add the new rows
 		iTableRowCount = self.funcGetFeatureCount()
@@ -839,7 +839,7 @@ class AbundanceTable:
 		# Check number of input data rows
 		iMetadataCount = len(llsMetadata)
 		if (len(lsNames) != iMetadataCount):
-			print "Error:The names and the rows of metadata features to add must be of equal length"
+			print("Error:The names and the rows of metadata features to add must be of equal length")
 
 		# Add the metadata
 		for tpleMetadata in zip(lsNames,llsMetadata):
@@ -1024,7 +1024,7 @@ class AbundanceTable:
 			lsClades = sFeatureName.split(cDelimiter)
 			#If there are not enough then error
 			if(len(lsClades) > iPrefixLength):
-                                print "Error:: Too many clades given to be biologically meaningful"
+                                print("Error:: Too many clades given to be biologically meaningful")
 				return False
 			lsUpdatedFeatureNames.append(cDelimiter.join([lsPrefixes[iClade]+lsClades[iClade] if not(lsClades[iClade][0:len(lsPrefixes[iClade])]==lsPrefixes[iClade]) else lsClades[iClade] for iClade in xrange(len(lsClades))]))
 
