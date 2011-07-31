--- SABnzbd.py	2011-06-07 18:02:35.000000000 -0400
+++ SABnzbd-port.py	2011-06-08 07:20:14.948254196 -0400
@@ -276,9 +276,6 @@
 
     os.chdir(sabnzbd.DIR_PROG)
     os.setsid()
-    # Make sure I can read my own files and shut out others
-    prev= os.umask(0)
-    os.umask(prev and int('077',8))
 
     try:
         pid = os.fork()
@@ -40,6 +40,9 @@
     print "The Python module Cheetah is required"
     sys.exit(1)
 
+# Force python to load the patched version of cherrypy included with the port,
+# instead of any version that may be installed otherwise.
+sys.path.insert(0,%%PREFIX%%)
 import cherrypy
 if not cherrypy.__version__.startswith("3.2"):
     print "Sorry, requires Python module Cherrypy 3.2 (use the included version)"
@@ -932,7 +935,7 @@
 
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sabnzbd.MY_FULLNAME))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
+    sabnzbd.DIR_PROG = %%PREFIX%%
     sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
     sabnzbd.DIR_LANGUAGE = real_path(sabnzbd.DIR_PROG, DEF_LANGUAGE)
     org_dir = os.getcwd()
