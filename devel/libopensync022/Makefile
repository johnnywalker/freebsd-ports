# New ports collection makefile for:	libopensync
# Date created:		2005-06-19
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libopensync
PORTVERSION=	0.22
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Freedesktop synchronization framework

CONFLICTS=	libopensync-0.[3-9]*

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13

USE_BZIP2=	yes
LDFLAGS+=	${PTHREAD_LIBS}
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack glib20 libxml2
USE_LDCONFIG=	yes

LATEST_LINK=	libopensync022

pre-everything::
	@${ECHO_MSG} "NOTE: You may want to avoid extra dependencies"
	@${ECHO_MSG} " from devel/swig13 by building with the following"
	@${ECHO_MSG} " SWIG_LANGUAGES=\"perl python\""
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|$${libdir}/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e "s,-Werror,," ${WRKSRC}/opensync/Makefile.in \
		${WRKSRC}/osengine/Makefile.in \
		${WRKSRC}/formats/vformats-xml/Makefile.in
	${REINPLACE_CMD} -e "s,echo aout, echo elf,g" ${WRKSRC}/configure

.include <bsd.port.mk>
