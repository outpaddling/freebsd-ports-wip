--- FIAT/expansions.py.orig	2018-12-20 00:07:51 UTC
+++ FIAT/expansions.py
@@ -48,7 +48,7 @@ def _tabulate_dpts(tabulator, D, n, orde
         out = []
         try:
             out = [sympy.diff(F, X[j]) for j in range(D)]
-        except AttributeError:
+        except (AttributeError, ValueError):
             # Intercept errors like
             #  AttributeError: 'list' object has no attribute
             #  'free_symbols'
