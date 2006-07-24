
$FreeBSD: ports/net/asterisk/files/patch-channels::chan_skinny.c,v 1.1 2006/05/23 02:47:04 sobomax Exp $

--- channels/chan_skinny.c.orig
+++ channels/chan_skinny.c
@@ -99,7 +99,7 @@
 #define htolel(x) (x)
 #define htoles(x) (x)
 #else
-#if defined(SOLARIS) || defined(__Darwin__) || defined(__NetBSD__)
+#if defined(SOLARIS) || defined(__Darwin__) || defined(__NetBSD__) || defined(__FreeBSD__)
 #define __bswap_16(x) \
      ((((x) & 0xff00) >> 8) | \
       (((x) & 0x00ff) << 8))
