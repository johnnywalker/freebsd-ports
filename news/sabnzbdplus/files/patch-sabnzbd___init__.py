--- sabnzbd/__init__.py.orig	2011-07-31 11:31:08.284795101 -0500
+++ sabnzbd/__init__.py	2011-07-31 11:31:16.844764052 -0500
@@ -46,8 +46,6 @@
     except:
         pass
 elif os.name == 'posix':
-    ORG_UMASK = os.umask(18)
-    os.umask(ORG_UMASK)
     POSIX = True
     import platform
     if platform.system().lower() == 'darwin':
