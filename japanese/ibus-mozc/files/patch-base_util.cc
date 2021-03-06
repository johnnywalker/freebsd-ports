--- base/util.cc.org	2010-11-06 10:45:14.448193623 +0900
+++ base/util.cc	2010-11-06 10:46:11.717188704 +0900
@@ -1629,9 +1629,13 @@
   return MacUtil::GetServerDirectory();
 #endif  // OS_MACOSX
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   return "/usr/lib/mozc";
 #endif  // OS_LINUX
+
+#ifdef __FreeBSD__
+  return "@@LOCALBASE@@/bin";
+#endif
 }
 
 string Util::GetServerPath() {
