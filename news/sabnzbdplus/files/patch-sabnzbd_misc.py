--- sabnzbd/misc.py.orig	2011-07-23 15:32:11.935695293 -0500
+++ sabnzbd/misc.py	2011-07-23 15:32:47.527562111 -0500
@@ -291,13 +291,6 @@
                         result = True
                     except:
                         result = False
-                    if umask:
-                        mask = cfg.umask()
-                        if mask:
-                            try:
-                                os.chmod(path, int(mask, 8) | 0700)
-                            except:
-                                pass
     return result
 
 ################################################################################
