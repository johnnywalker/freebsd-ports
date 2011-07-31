--- SABnzbd.py.orig	2011-06-13 05:08:48.000000000 -0500
+++ SABnzbd.py	2011-07-31 10:46:34.105430802 -0500
@@ -1,4 +1,4 @@
-#!/usr/bin/python -OO
+#!/usr/local/bin/python2.6 -OO
 # Copyright 2008-2011 The SABnzbd-Team <team@sabnzbd.org>
 #
 # This program is free software; you can redistribute it and/or
@@ -276,9 +276,6 @@
 
     os.chdir(sabnzbd.DIR_PROG)
     os.setsid()
-    # Make sure I can read my own files and shut out others
-    prev= os.umask(0)
-    os.umask(prev and int('077',8))
 
     try:
         pid = os.fork()
@@ -916,7 +913,7 @@
 
     sabnzbd.MY_FULLNAME = os.path.normpath(os.path.abspath(sabnzbd.MY_FULLNAME))
     sabnzbd.MY_NAME = os.path.basename(sabnzbd.MY_FULLNAME)
-    sabnzbd.DIR_PROG = os.path.dirname(sabnzbd.MY_FULLNAME)
+    sabnzbd.DIR_PROG = '/usr/local/share/sabnzbdplus'
     sabnzbd.DIR_INTERFACES = real_path(sabnzbd.DIR_PROG, DEF_INTERFACES)
     sabnzbd.DIR_LANGUAGE = real_path(sabnzbd.DIR_PROG, DEF_LANGUAGE)
     org_dir = os.getcwd()
