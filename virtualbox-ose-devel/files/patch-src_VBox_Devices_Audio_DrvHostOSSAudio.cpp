--- src/VBox/Devices/Audio/DrvHostOSSAudio.cpp.orig	2019-10-10 21:09:31.000000000 +0300
+++ src/VBox/Devices/Audio/DrvHostOSSAudio.cpp	2020-05-24 01:15:17.346032000 +0300
@@ -253,10 +253,11 @@
 
             default:
                 rc = VERR_AUDIO_STREAM_COULD_NOT_CREATE;
+                iFormat = -1;				
                 break;
         }
 
-        if (RT_FAILURE(rc))
+        if (RT_UNLIKELY(iFormat == -1))
             break;
 
         if (ioctl(fdFile, SNDCTL_DSP_SAMPLESIZE, &iFormat))
@@ -664,6 +665,7 @@
 
                 pCfgAcq->Backend.cFramesPeriod     = PDMAUDIOSTREAMCFG_B2F(pCfgAcq, ossAcq.cbFragmentSize);
                 pCfgAcq->Backend.cFramesBufferSize = pCfgAcq->Backend.cFramesPeriod * 2; /* Use "double buffering". */
+                pCfgAcq->Backend.cFramesPreBuffering     = pCfgAcq->Backend.cFramesBufferSize;                
                 /** @todo Pre-buffering required? */
             }
         }
@@ -782,6 +784,7 @@
 #endif
             pCfgAcq->Backend.cFramesPeriod     = PDMAUDIOSTREAMCFG_B2F(pCfgAcq, obtStream.cbFragmentSize);
             pCfgAcq->Backend.cFramesBufferSize = pCfgAcq->Backend.cFramesPeriod * 2; /* Use "double buffering" */
+            pCfgAcq->Backend.cFramesPreBuffering     = pCfgAcq->Backend.cFramesBufferSize;            
         }
 
     } while (0);
