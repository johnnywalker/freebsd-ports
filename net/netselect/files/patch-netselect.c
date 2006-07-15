--- netselect.c.orig	2006-07-14 22:59:18.000000000 +0200
+++ netselect.c	2006-07-14 22:57:22.000000000 +0200
@@ -39,14 +39,13 @@
  * hey, great!  Let me know. -- apenwarr
  */
 
-#ifdef __EMX__
-# include <io.h>
-# include <fcntl.h>
-# include <sys/types.h>
-# include <sys/select.h>
-# include <machine/endian.h>
-#else
-# include <endian.h>
+#ifdef __linux__
+#include <endian.h>
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)
+#if defined(__OpenBSD__)
+#include <machine/types.h>
+#endif
+#include <machine/endian.h>
 #endif
 
 #include <sys/param.h>
@@ -152,6 +151,7 @@
     extern int optind;
     int hostcount, startcount, endcount = 0, sent_one, lag, min_lag = 100;
     int ch, seq, ttl, max_ttl = 30, min_tries = 10, num_score = 1;
+    int on = 1;
     struct timeval now;
     struct timezone tz;
     OPacket outpacket;          /* last output (udp) packet */
@@ -234,7 +234,12 @@
     if (verbose >= 1)
 	fprintf(stderr, "Running netselect to choose %d out of %d address%s.\n",
 		num_score, numhosts, numhosts==1 ? "" : "es");
-    
+   
+   if (setsockopt(sndsock, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
+        perror("IP_HDRINCL");
+	_exit(EXIT_FAILURE);
+   }
+
     /* keep going until most of the hosts have been finished */
     must_continue = numhosts;
     while (must_continue && must_continue >= numhosts/2)
@@ -712,7 +717,7 @@
     ip->ip_off = 0;
     ip->ip_hl = sizeof(*ip) >> 2;
     ip->ip_p = IPPROTO_UDP;
-    ip->ip_len = 0; /* kernel fills this in */
+    ip->ip_len = sizeof(OPacket);
     ip->ip_ttl = ttl;
     ip->ip_v = IPVERSION;
     ip->ip_id = htons(ident + seq);
