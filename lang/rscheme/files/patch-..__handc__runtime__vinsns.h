
$FreeBSD: ports/lang/rscheme/files/patch-vinsns.h,v 1.1 2006/02/10 15:07:06 anray Exp $

--- ../handc/runtime/vinsns.h	Fri Feb 10 15:56:41 2006
+++ ../handc/runtime/vinsns.h	Fri Feb 10 15:56:57 2006
@@ -58,7 +58,7 @@
 			       arg_count_reg = num; \
 			       return (jump_addr)label;)
 #else
-#define JUMP(num,label)   return (jump_addr)((jump_addr)label)()
+#define JUMP(num,label)   return label()
 #endif
 #endif
 
