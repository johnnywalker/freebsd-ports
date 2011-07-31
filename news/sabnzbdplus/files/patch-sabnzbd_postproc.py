--- sabnzbd/postproc.py.orig	2011-07-23 15:31:31.040849036 -0500
+++ sabnzbd/postproc.py	2011-07-23 15:31:58.999744135 -0500
@@ -312,10 +312,6 @@
                             new_path = get_unique_filename(new_path)
                             move_to_path(path, new_path, unique=False)
 
-            ## Set permissions right
-            if not sabnzbd.WIN32:
-                perm_script(tmp_workdir_complete, cfg.umask())
-
             if all_ok:
                 ## Remove files matching the cleanup list
                 cleanup_list(tmp_workdir_complete, True)
@@ -523,41 +519,6 @@
 
 #------------------------------------------------------------------------------
 
-def perm_script(wdir, umask):
-    """ Give folder tree and its files their proper permissions """
-    from os.path import join
-
-    try:
-        # Make sure that user R is on
-        umask = int(umask, 8) | int('0400', 8)
-        report_errors = True
-    except ValueError:
-        # No or no valid permissions
-        # Use the effective permissions of the session
-        # Don't report errors (because the system might not support it)
-        umask = int('0777', 8) & (sabnzbd.ORG_UMASK ^ int('0777', 8))
-        report_errors = False
-
-    # Remove X bits for files
-    umask_file = umask & int('7666', 8)
-
-    # Parse the dir/file tree and set permissions
-    for root, dirs, files in os.walk(wdir):
-        try:
-            os.chmod(root, umask)
-        except:
-            if report_errors:
-                logging.error(Ta('Cannot change permissions of %s'), root)
-                logging.info("Traceback: ", exc_info = True)
-        for name in files:
-            try:
-                os.chmod(join(root, name), umask_file)
-            except:
-                if report_errors:
-                    logging.error(Ta('Cannot change permissions of %s'), join(root, name))
-                    logging.info("Traceback: ", exc_info = True)
-
-
 def addPrefixes(path, dirprefix):
     """ Add list of prefixes as sub folders to path
         '/my/path' and ['a', 'b', 'c'] will give '/my/path/a/b/c'
