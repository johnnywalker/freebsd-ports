--- base/debug/debugger_posix.cc.orig	2011-07-28 11:01:28.000000000 +0300
+++ base/debug/debugger_posix.cc	2011-08-28 20:25:41.000000000 +0300
@@ -13,6 +13,7 @@
 #include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/user.h>
 #include <unistd.h>
 
 #include <string>
@@ -57,7 +58,7 @@
   return false;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 
 // Based on Apple's recommended method as described in
 // http://developer.apple.com/qa/qa2004/qa1361.html
@@ -95,7 +96,11 @@
 
   // This process is being debugged if the P_TRACED flag is set.
   is_set = true;
+#if defined(OS_FREEBSD)
+  being_debugged = (info.ki_flag & P_TRACED) != 0;
+#else
   being_debugged = (info.kp_proc.p_flag & P_TRACED) != 0;
+#endif
   return being_debugged;
 }
 
@@ -145,12 +150,11 @@
 #else
 
 bool BeingDebugged() {
-  // TODO(benl): can we determine this under FreeBSD?
   NOTIMPLEMENTED();
   return false;
 }
 
-#endif  // defined(OS_FREEBSD)
+#endif
 
 // We want to break into the debugger in Debug mode, and cause a crash dump in
 // Release mode. Breakpad behaves as follows:
