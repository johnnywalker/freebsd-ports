--- single.cc.orig	Sat Aug 18 18:18:16 2001
+++ single.cc	Sat Aug 18 18:17:24 2001
@@ -1,16 +1,13 @@
 // generated by Fast Light User Interface Designer (fluid) version 1.00
-
 #include <client.h>
 #include <sqlplus.hh>
+#undef Time
 //
 //	This file implements the file I/O routines for the editor engine.
 //	These are simple ASCII I/O routines, just for getting text out of
 //	a file, or putting it into one.
 //
 #include "single.h"
-#include <FL/vartypes.h>
-#include <FL/strings.h>
-#include <FL/editor.h>
 
 extern Connection *con;
 
