--- setup.py.orig	2018-03-03 14:45:20 UTC
+++ setup.py
@@ -34,8 +34,6 @@ if sys.argv[-1] == 'publish':
 
 tests_require = [
     'pytest >3,<4',
-    'pytest-cov',
-    'pytest-runner',
 ]
 
 needs_pytest = set(('pytest', 'test', 'ptr')).intersection(sys.argv)
@@ -67,7 +65,6 @@ setup(
         'Topic :: Utilities',
     ],
     test_suite='tests',
-    setup_requires=pytest_runner,
     tests_require=tests_require,
     extras_require=dict(
         test=tests_require,
