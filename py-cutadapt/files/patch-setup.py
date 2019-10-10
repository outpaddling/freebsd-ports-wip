--- setup.py.orig	2019-10-10 16:47:45 UTC
+++ setup.py
@@ -102,7 +102,7 @@ setup(
     package_dir={'': 'src'},
     packages=find_packages('src'),
     entry_points={'console_scripts': ['cutadapt = cutadapt.__main__:main']},
-    install_requires=['dnaio~=0.3.0', 'xopen~=0.8.1'],
+    install_requires=['dnaio>=0.3.0', 'xopen>=0.8.1'],
     extras_require={
         'dev': ['Cython', 'pytest', 'pytest-timeout', 'sphinx', 'sphinx_issues'],
     },
