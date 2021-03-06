--- cpp.orig/src/Ice/Network.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Ice/Network.cpp	2011-07-15 23:40:26.000000000 +0200
@@ -715,7 +715,11 @@
     WSASetLastError(error);
 #else
     int error = errno;
-    if(close(fd) == SOCKET_ERROR)
+    if(close(fd) == SOCKET_ERROR
+#  if defined(__FreeBSD__)
+    && getSocketErrno() != ECONNRESET
+#  endif
+    )
     {
         SocketException ex(__FILE__, __LINE__);
         ex.error = getSocketErrno();
