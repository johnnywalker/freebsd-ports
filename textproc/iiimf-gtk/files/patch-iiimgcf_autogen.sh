--- iiimgcf/autogen.sh	Thu Dec 11 17:29:28 2003
+++ iiimgcf/autogen.sh	Wed Feb 16 16:48:14 2005
@@ -12,7 +12,15 @@
 
 DIE=0
 
-(libtool --version) < /dev/null > /dev/null 2>&1 || {
+LIBTOOL=libtool15
+INTLTOOLIZE=intltoolize
+LIBTOOLIZE=libtoolize15
+ACLOCAL=aclocal15
+AUTOHEADER=autoheader253
+AUTOMAKE=automake15
+AUTOCONF=autoconf253
+
+(${LIBTOOL} --version) < /dev/null > /dev/null 2>&1 || {
 	echo
 	echo "You must have libtool installed to compile $PROJECT."
 	echo "Install the appropriate package for your distribution,"
@@ -30,7 +38,7 @@
 }
 
 (grep "^AC_PROG_INTLTOOL" $srcdir/configure.ac >/dev/null) && {
-  (intltoolize --version) < /dev/null > /dev/null 2>&1 || {
+  (${INTLTOOLIZE} --version) < /dev/null > /dev/null 2>&1 || {
     echo
     echo "**Error**: You must have \`intltoolize' installed to compile $PKG_NAME."
     echo "Get ftp://ftp.gnome.org/pub/GNOME/stable/sources/intltool/intltool-0.10.tar.gz"
@@ -39,7 +47,7 @@
   }
 }
 
-(autoconf --version) < /dev/null > /dev/null 2>&1 || {
+(${AUTOCONF} --version) < /dev/null > /dev/null 2>&1 || {
 	echo
 	echo "You must have autoconf installed to compile $PROJECT."
 	echo "libtool the appropriate package for your distribution,"
@@ -48,8 +56,8 @@
 }
 
 have_automake=false
-if automake --version < /dev/null > /dev/null 2>&1 ; then
-	automake_version=`automake --version | grep 'automake (GNU automake)' | sed 's/^[^0-9]*\(.*\)/\1/'`
+if ${AUTOMAKE} --version < /dev/null > /dev/null 2>&1 ; then
+	automake_version=`${AUTOMAKE} --version | grep 'automake (GNU automake)' | sed 's/^[^0-9]*\(.*\)/\1/'`
 	case $automake_version in
 	   1.2*|1.3*|1.4) 
 		;;
@@ -96,19 +104,19 @@
 fi
 if grep "^AC_PROG_INTLTOOL" configure.ac >/dev/null; then
   echo "Running intltoolize..."
-  intltoolize --copy --force --automake
+  ${INTLTOOLIZE} --copy --force --automake
 fi
 
 # intentionally we don't call "libtoolize --force"
 # to avoid overriding ../acfiles/ltmain.h, which we don't want to happen!
 
-aclocal -I ../acfiles $ACLOCAL_FLAGS
+${ACLOCAL} -I ../acfiles $ACLOCAL_FLAGS
 
 # optionally feature autoheader
-(autoheader --version)  < /dev/null > /dev/null 2>&1 && autoheader
+(${AUTOHEADER} --version)  < /dev/null > /dev/null 2>&1 && ${AUTOHEADER}
 
-automake -a $am_opt
-autoconf
+${AUTOMAKE} -a $am_opt
+${AUTOCONF}
 cd $ORIGDIR
 
 if test -z "$AUTOGEN_SUBDIR_MODE"; then
