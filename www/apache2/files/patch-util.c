===================================================================
RCS file: /home/cvs/apache-1.3/src/main/util.c,v
retrieving revision 1.194
retrieving revision 1.197
diff -u -r1.194 -r1.197
--- src/main/util.c	2001/02/01 10:06:37	1.194
+++ src/main/util.c	2001/03/30 17:37:54	1.197
@@ -2013,12 +2013,14 @@
     int x;
 
     if (!strchr(p->h_name, '.')) {
-	for (x = 0; p->h_aliases[x]; ++x) {
-	    if (strchr(p->h_aliases[x], '.') &&
-		(!strncasecmp(p->h_aliases[x], p->h_name, strlen(p->h_name))))
-		return ap_pstrdup(a, p->h_aliases[x]);
-	}
-	return NULL;
+        if (p->h_aliases) {
+        	for (x = 0; p->h_aliases[x]; ++x) {
+                if (p->h_aliases[x] && strchr(p->h_aliases[x], '.') &&
+            		(!strncasecmp(p->h_aliases[x], p->h_name, strlen(p->h_name))))
+		            return ap_pstrdup(a, p->h_aliases[x]);
+            }
+	    }
+	    return NULL;
     }
     return ap_pstrdup(a, (void *) p->h_name);
 }
@@ -2040,7 +2042,6 @@
 	ap_log_error(APLOG_MARK, APLOG_WARNING, NULL,
 	             "%s: gethostname() failed to determine ServerName\n",
                      ap_server_argv0);
-	server_hostname = ap_pstrdup(a, "127.0.0.1");
     }
     else 
     {
@@ -2048,14 +2049,14 @@
         if ((!(p = gethostbyname(str))) 
             || (!(server_hostname = find_fqdn(a, p)))) {
             /* Recovery - return the default servername by IP: */
-            if (p->h_addr_list[0]) {
+            if (p && p->h_addr_list && p->h_addr_list[0]) {
                 ap_snprintf(str, sizeof(str), "%pA", p->h_addr_list[0]);
 	        server_hostname = ap_pstrdup(a, str);
                 /* We will drop through to report the IP-named server */
             }
         }
 	else
-            /* Since we found a fdqn, return it with no logged message. */
+            /* Since we found a fqdn, return it with no logged message. */
             return server_hostname;
     }
 
