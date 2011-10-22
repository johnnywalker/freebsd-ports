# Common stuff for Licq-based ports
# $FreeBSD: ports/net-im/licq/Makefile.inc,v 1.29 2010/11/27 12:25:42 dinoex Exp $

PKGNAMEPREFIX=		licq-
LICQ_VER=		1.5.1
QT_LICQ_VER=		1.5.1
OSD_LICQ_VER=		1.5.1
CONSOLE_LICQ_VER=	1.5.1
.if ${PORTNAME} != "base"
BUILD_DEPENDS+=		licq:${PORTSDIR}/${LICQ_PORT}
RUN_DEPENDS+=		licq:${PORTSDIR}/${LICQ_PORT}
WRKSRC?=		${WRKDIR}/${DISTNAME}/plugins/${PORTNAME}
.endif
MASTER_SITES=		SF/licq/licq/${LICQ_VER}
DISTNAME=		${PKGNAMEPREFIX}${LICQ_VER}
DISTFILES=		${DISTNAME}.tar.bz2
DISTINFO_FILE?=		${PORTSDIR}/${LICQ_PORT}/distinfo
USE_BZIP2=		yes
