--- main.c.orig	Wed Jul 26 04:45:13 2006
+++ main.c	Sat Jun 16 19:49:25 2007
@@ -2,12 +2,14 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <syslog.h>
+#include <pthread.h>
 #include <signal.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <sys/stat.h>
 #include <sys/resource.h>
 #include <time.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <upnp/upnp.h>
 #include "globals.h"
@@ -22,7 +24,6 @@
 int main (int argc, char** argv)
 {
 	char descDocUrl[7+15+1+5+1+sizeof(g_vars.descDocName)+1]; // http://ipaddr:port/docName<null>
-	char intIpAddress[16];     // Server internal ip address
 	sigset_t sigsToCatch;
 	int ret, signum, arg = 1, foreground = 0;
 
@@ -46,11 +47,17 @@
 	strncpy(g_vars.intInterfaceName, argv[arg++], IFNAMSIZ);
 
 	// Get the internal ip address to start the daemon on
-	if (GetIpAddressStr(intIpAddress, g_vars.intInterfaceName) == 0) {
+	if (GetIpAddressStr(g_vars.intIpAddress, g_vars.intInterfaceName) == 0) {
 		fprintf(stderr, "Invalid internal interface name '%s'\n", g_vars.intInterfaceName);
 		exit(EXIT_FAILURE);
 	}
 
+	// Get the external ip address to start the daemon on
+	if (GetIpAddressStr(g_vars.extIpAddress, g_vars.extInterfaceName) == 0) {
+		fprintf(stderr, "Invalid external interface name '%s'\n", g_vars.extInterfaceName);
+		exit(EXIT_FAILURE);
+	}
+
 	if (!foreground) {
 		struct rlimit resourceLimit = { 0, 0 };
 		pid_t pid, sid;
@@ -114,9 +121,9 @@
 
 	// Initialize UPnP SDK on the internal Interface
 	trace(3, "Initializing UPnP SDK ... ");
-	if ( (ret = UpnpInit(intIpAddress,0) ) != UPNP_E_SUCCESS)
+	if ( (ret = UpnpInit(g_vars.intIpAddress,0) ) != UPNP_E_SUCCESS)
 	{
-		syslog (LOG_ERR, "Error Initializing UPnP SDK on IP %s ",intIpAddress);
+		syslog (LOG_ERR, "Error Initializing UPnP SDK on IP %s ",g_vars.intIpAddress);
 		syslog (LOG_ERR, "  UpnpInit returned %d", ret);
 		UpnpFinish();
 		exit(1);
