# New ports collection makefile for: gnome-ssh-askpass
# Date created:	11 June 2002
# Whom: Mark Hannon <markhannon@optusnet.com.au>
#
# $FreeBSD$

PORTNAME=	gnome-ssh-askpass
PORTVERSION=	3.6p1
PORTREVISION=	10
CATEGORIES=	security gnome
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/OpenSSH/portable/ \
		ftp://carroll.cac.psu.edu/pub/OpenBSD/OpenSSH/portable/
DISTNAME=	openssh-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical ssh askpass utility for Gnome2

WRKSRC=		${WRKDIR}/openssh-3.6p1
BUILD_WRKSRC=	${WRKSRC}/contrib
ALL_TARGET=	gnome-ssh-askpass2

PLIST_FILES=	bin/gnome-ssh-askpass2
USE_GNOME=	gtk20

.include <bsd.port.pre.mk>
CFLAGS+=	${PTHREAD_LIBS}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gnome-ssh-askpass2 ${PREFIX}/bin

.include <bsd.port.post.mk>
