--- src/osg/Texture.cpp.orig	2025-10-30 13:05:29 UTC
+++ src/osg/Texture.cpp
@@ -1148,7 +1148,7 @@ void TextureObjectManager::recomputeStats(std::ostream
     unsigned int numObjectsInLists = 0;
     unsigned int numActive = 0;
     unsigned int numOrphans = 0;
-    unsigned int numPendingOrphans = 0;
+    // unsigned int numPendingOrphans = 0;
     unsigned int currentSize = 0;
     for(TextureSetMap::const_iterator itr = _textureSetMap.begin();
         itr != _textureSetMap.end();
@@ -1158,7 +1158,7 @@ void TextureObjectManager::recomputeStats(std::ostream
          numObjectsInLists += os->computeNumTextureObjectsInList();
          numActive += os->getNumOfTextureObjects();
          numOrphans += os->getNumOrphans();
-         numPendingOrphans += os->getNumPendingOrphans();
+         // numPendingOrphans += os->getNumPendingOrphans();
          currentSize += os->getProfile()._size * (os->computeNumTextureObjectsInList()+os->getNumOrphans());
          out<<"   size="<<os->getProfile()._size
            <<", os->computeNumTextureObjectsInList()"<<os->computeNumTextureObjectsInList()
@@ -1174,20 +1174,20 @@ bool TextureObjectManager::checkConsistency() const
 
 bool TextureObjectManager::checkConsistency() const
 {
-    unsigned int numObjectsInLists = 0;
-    unsigned int numActive = 0;
-    unsigned int numOrphans = 0;
-    unsigned int numPendingOrphans = 0;
+    // unsigned int numObjectsInLists = 0;
+    // unsigned int numActive = 0;
+    // unsigned int numOrphans = 0;
+    // unsigned int numPendingOrphans = 0;
     unsigned int currentSize = 0;
     for(TextureSetMap::const_iterator itr = _textureSetMap.begin();
         itr != _textureSetMap.end();
         ++itr)
     {
          const TextureObjectSet* os = itr->second.get();
-         numObjectsInLists += os->computeNumTextureObjectsInList();
-         numActive += os->getNumOfTextureObjects();
-         numOrphans += os->getNumOrphans();
-         numPendingOrphans += os->getNumPendingOrphans();
+         // numObjectsInLists += os->computeNumTextureObjectsInList();
+         // numActive += os->getNumOfTextureObjects();
+         // numOrphans += os->getNumOrphans();
+         // numPendingOrphans += os->getNumPendingOrphans();
          currentSize += os->getProfile()._size * (os->computeNumTextureObjectsInList()+os->getNumOrphans());
     }
 
