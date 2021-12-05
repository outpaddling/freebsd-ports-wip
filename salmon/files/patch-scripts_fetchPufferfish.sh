--- scripts/fetchPufferfish.sh.orig	2021-12-05 14:25:23 UTC
+++ scripts/fetchPufferfish.sh
@@ -10,10 +10,6 @@ CURR_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && p
 EXTERNAL_DIR=${CURR_DIR}/../external
 INSTALL_DIR=${CURR_DIR}/../external/install
 
-if [ -d ${EXTERNAL_DIR}/pufferfish ] ; then
-    rm -fr ${EXTERNAL_DIR}/pufferfish
-fi
-
 if [ -d ${INSTALL_DIR}/include/pufferfish ] ; then
     rm -fr ${INSTALL_DIR}/include/pufferfish
 fi
@@ -25,35 +21,6 @@ fi
 SVER=salmon-v1.6.0
 #SVER=develop
 #SVER=sketch-mode
-
-EXPECTED_SHA256=f71b3c08f254200fcdc2eb8fe3dcca8a8e9489e79ef5952a4958d8b9979831dc
-
-mkdir -p ${EXTERNAL_DIR}
-curl -k -L https://github.com/COMBINE-lab/pufferfish/archive/${SVER}.zip -o ${EXTERNAL_DIR}/pufferfish.zip
-
-hashcheck=""
-if exists sha256sum; then
-	hashcheck="sha256sum"
-elif exists shasum; then
-	hashcheck="shasum -a256"
-else
-	unset hashcheck
-fi
-
-if [ -z "${hashcheck-}" ]; then
-    echo "Couldn't find shasum command; can't verify contents of downloaded pufferfish";
-else
-    if [[ $SVER != develop ]]; then
-        echo "${EXPECTED_SHA256}  ${EXTERNAL_DIR}/pufferfish.zip" | ${hashcheck} -c - || { echo "pufferfish.zip did not match expected SHA1! Exiting."; exit 1; }
-    else
-        echo "not testing sha since pulling from develop"
-    fi
-fi
-
-
-rm -fr ${EXTERNAL_DIR}/pufferfish
-unzip ${EXTERNAL_DIR}/pufferfish.zip -d ${EXTERNAL_DIR}
-mv ${EXTERNAL_DIR}/pufferfish-${SVER} ${EXTERNAL_DIR}/pufferfish
 
 mkdir -p ${INSTALL_DIR}/include/pufferfish
 
