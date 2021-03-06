# New ports collection makefile for:	ruby-goocanvas
# Date created:		2010-11-19
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	goocanvas
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	x11-toolkits gnome ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for goocanvas

LIB_DEPENDS=	goocanvas.3:${PORTSDIR}/graphics/goocanvas
BUILD_DEPENDS+=	rubygem-pkg-config>=1.0.7:${PORTSDIR}/devel/rubygem-pkg-config \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/cairo.so:${PORTSDIR}/graphics/ruby-cairo
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/cairo.so:${PORTSDIR}/graphics/ruby-cairo

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
CONFIGURE_ARGS=	--with-pkg-config-dir=${LOCALBASE}/libdata/pkgconfig

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/goocanvas
INSTALL_TARGET=	site-install install

DOCS=		ChangeLog README

post-patch: general-patch

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
