--- bwtgap.c.orig	2014-05-21 12:44:57.000000000 -0500
+++ bwtgap.c	2014-05-21 12:45:02.000000000 -0500
@@ -58,7 +58,7 @@
 		q->stack = (gap_entry_t*)realloc(q->stack, sizeof(gap_entry_t) * q->m_entries);
 	}
 	p = q->stack + q->n_entries;
-	p->info = (u_int32_t)score<<21 | i; p->k = k; p->l = l;
+	p->info = (uint32_t)score<<21 | i; p->k = k; p->l = l;
 	p->n_mm = n_mm; p->n_gapo = n_gapo; p->n_gape = n_gape;
 	p->n_ins = n_ins; p->n_del = n_del;
 	p->state = state; 
