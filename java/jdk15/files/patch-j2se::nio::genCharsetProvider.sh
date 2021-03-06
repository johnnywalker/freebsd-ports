$FreeBSD: ports/java/jdk15/files/patch-j2se::nio::genCharsetProvider.sh,v 1.2 2006/10/14 08:54:34 marcus Exp $

--- ../../j2se/make/java/nio/genCharsetProvider.sh	8 Nov 2004 22:27:03 -0000	1.1.1.1
+++ ../../j2se/make/java/nio/genCharsetProvider.sh	24 Mar 2005 16:14:52 -0000
@@ -94,9 +94,9 @@
   }
 '
 
-$JAVA -cp $NIO_TMPDIR Hasher -i Aliases <$NIO_TMPDIR/aliases >>$OUT
-$JAVA -cp $NIO_TMPDIR Hasher -i Classes <$NIO_TMPDIR/classes >>$OUT
-$JAVA -cp $NIO_TMPDIR Hasher -i -e Cache -t Charset <$NIO_TMPDIR/classes >>$OUT
+$JAVA -cp $NIO_TMPDIR Hasher -i Aliases <$NIO_TMPDIR/aliases | egrep -v '^Java Hotspot' >>$OUT
+$JAVA -cp $NIO_TMPDIR Hasher -i Classes <$NIO_TMPDIR/classes | egrep -v '^Java Hotspot' >>$OUT
+$JAVA -cp $NIO_TMPDIR Hasher -i -e Cache -t Charset <$NIO_TMPDIR/classes | egrep -v '^Java Hotspot' >>$OUT
 
 
 # Constructor
