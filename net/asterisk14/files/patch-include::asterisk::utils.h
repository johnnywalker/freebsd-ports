
$FreeBSD: ports/net/asterisk14/files/patch-include::asterisk::utils.h,v 1.2 2009/08/02 19:34:54 mezz Exp $

--- include/asterisk/utils.h	2004/10/10 12:55:50	1.1
+++ include/asterisk/utils.h	2004/10/10 12:56:43
@@ -37,7 +37,6 @@
 #ifdef inet_ntoa
 #undef inet_ntoa
 #endif
-#define inet_ntoa __dont__use__inet_ntoa__use__ast_inet_ntoa__instead__
 
 #ifdef LINUX
 #define ast_pthread_create pthread_create
