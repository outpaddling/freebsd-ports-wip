--- src/OpenFOAM/primitives/hashes/Hasher/Hasher.C.orig	2026-08-24 20:13:42 UTC
+++ src/OpenFOAM/primitives/hashes/Hasher/Hasher.C
@@ -457,7 +457,7 @@ static unsigned jenkins_hashbig
             case 4 : a += k[3]; [[fallthrough]];
             case 3 : a += static_cast<uint32_t>(k[2]) << 8; [[fallthrough]];
             case 2 : a += static_cast<uint32_t>(k[1]) << 16; [[fallthrough]];
-            case 1 : a += static_cast<uint32_t>(k[0]) << 24; [[fallthrough]];
+            case 1 : a += static_cast<uint32_t>(k[0]) << 24;
                 break;
             case 0 : return c;
         }
