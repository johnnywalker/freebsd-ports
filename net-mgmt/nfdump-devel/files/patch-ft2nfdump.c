
$FreeBSD: ports/net-mgmt/nfdump-devel/files/patch-ft2nfdump.c,v 1.1 2006/01/15 23:56:27 pav Exp $

--- ft2nfdump.c.orig
+++ ft2nfdump.c
@@ -66,7 +66,7 @@
 #include "nffile.h"
 #include "launch.h"
 
-#include "ftbuild.h"
+/*#include "ftbuild.h" */
 
 /* Global defines */
 #define MAXRECORDS 30
