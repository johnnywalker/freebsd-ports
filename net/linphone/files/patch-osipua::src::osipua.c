--- osipua/src/osipua.c.orig	Mon Oct 20 17:55:05 2003
+++ osipua/src/osipua.c	Fri Nov 21 11:52:31 2003
@@ -591,8 +591,7 @@
 			if (ipaddr != NULL)
 			{
 				osip_trace(OSIP_INFO1,("osip_ua_find 1: %s <> %s \n",ua->ua_ipaddr,ipaddr));
-				if ((strcasecmp(ua->ua_ipaddr,ipaddr)==0) || (strcasecmp("127.0.0.1",ipaddr)==0) ||
-				   	IN6_IS_ADDR_LOOPBACK(res->ai_addr))
+				if ((strcasecmp(ua->ua_ipaddr,ipaddr)==0) || (strcasecmp("127.0.0.1",ipaddr)==0))
 				{
 				   	 ret_ua=ua;       /* ip addresses match */
 				}
