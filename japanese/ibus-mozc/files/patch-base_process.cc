--- base/process.cc.org	2010-11-06 10:44:33.530187843 +0900
+++ base/process.cc	2010-11-06 10:45:08.765186704 +0900
@@ -194,13 +194,18 @@
   return ShellExecuteInSystemDir(L"open", wurl.c_str(), NULL, SW_SHOW);
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   static const char kBrowserCommand[] = "/usr/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
   return SpawnProcess(kBrowserCommand, url);
 #endif  // LINUX
 
+#ifdef __FreeBSD__
+  static const char kBrowserCommand[] = "@@LOCALBASE@@/bin/xdg-open";
+  return SpawnProcess(kBrowserCommand, url);
+#endif
+
 #ifdef OS_MACOSX
   return MacProcess::OpenBrowserForMac(url);
 #endif  // OS_MACOSX
