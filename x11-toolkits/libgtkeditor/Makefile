# New ports collection makefile for:	libgtkeditor
# Date created:				25 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgtkeditor
PORTVERSION=	0.1.8
PORTREVISION=	6
CATEGORIES=	x11-toolkits editors
MASTER_SITES=	SF/gtkeditor/gtkeditor/${PORTVERSION}
DISTNAME=	${PORTNAME:S/lib//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A source code editor widget for GTK+

DEPRECATED=	No more supported upstream, not depend on anymore.
EXPIRATION_DATE=	2011-12-03

LIB_DEPENDS=	unicode.0:${PORTSDIR}/devel/libunicode

USE_AUTOTOOLS=	automake:env autoconf:env libtool
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes
CFLAGS+=	-fPIC

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

pre-configure:
.for file in install-sh mkinstalldirs
	@${LN} -sf ${AUTOMAKE_DIR}/${file} ${WRKSRC}/${file}
.endfor
	@${RM} ${WRKSRC}/config.guess ${WRKSRC}/config.sub
	@${TOUCH} ${WRKSRC}/config.sub

# Crazy hacking to get around the fact that the tktext subdirectory
# generates files ending in .lo that libtool 1.5.x is considerably
# stricter on than libtool 1.3.x
CRAZY_HACK_FILES= \
	gtktextlayout.c gtktext.c gtktextdisplay.c gtktextbtree.c \
	gtktextbuffer.c gtktexttag.c gtktextmark.c gtktexttypes.c \
	gstring.c gbsearch.c gtktextchild.c gtktexttagtable.c \
	gtktextiter.c gtktextsegment.c

post-configure:
.for file in ${CRAZY_HACK_FILES}
	@${LN} -sf tktext-port/${file} ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/scanner.c

pre-install:
	@${MKDIR} ${PREFIX}/include/tktext-port

.include <bsd.port.mk>
