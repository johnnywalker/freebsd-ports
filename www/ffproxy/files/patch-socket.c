--- socket.c.orig	Fri Dec 31 10:59:54 2004
+++ socket.c	Thu Nov  9 20:19:53 2006
@@ -58,7 +58,7 @@
 open_socket(void)
 {
 	extern struct cfg config;
-	struct sockaddr claddr;
+	struct sockaddr_storage claddr;
 	struct addrinfo hints[2], *res;
 	struct clinfo  *clinfo;
 	struct pollfd	s[2];
@@ -135,7 +135,6 @@
 	if (config.bind_ipv6)
 		info("waiting for requests on %s port %d (IPv6)", *config.ipv6 ? config.ipv6 : "(any)", config.port);
 
-	claddr_len = sizeof(claddr);
 	config.ccount = 0;
 	cl = 0;
 	isipv4 = config.bind_ipv4;
@@ -160,13 +159,14 @@
 			}
 		} else
 			st = s[0].fd;
+		claddr_len = sizeof(claddr);
 		if ((cl = accept(st, (struct sockaddr *) & claddr, &claddr_len)) == -1) {
 			DEBUG(("open_socket() => accept() failed"));
 			continue;
 		}
 
 		DEBUG(("open_socket() => connection, checking access"));
-		clinfo = identify(&claddr, (socklen_t) isipv4 ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6));
+		clinfo = identify((struct sockaddr *)&claddr, claddr_len);
 		if (check_access(clinfo) != 0) {
 			DEBUG(("open_socket() => no access"));
 			if (config.logrequests)
