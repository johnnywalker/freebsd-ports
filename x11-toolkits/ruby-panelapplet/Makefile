# New ports collection makefile for:	Ruby/PanelApplet
# Date created:				15 August 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/ruby-panelapplet/Makefile,v 1.4 2009/04/07 04:06:54 marcus Exp $
#

PORTNAME=	panelapplet
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	x11-toolkits gnome ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding for libpanel-applet

BUILD_DEPENDS+=	rubygem-pkg-config>=1.0.7:${PORTSDIR}/devel/rubygem-pkg-config
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2

USE_RUBY=	yes
USE_GNOME=	gnomepanel
USE_RUBY_EXTCONF=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS=	--with-pkg-config-dir=${LOCALBASE}/libdata/pkgconfig

.include "${.CURDIR}/../../x11/ruby-gnome2/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/panel-applet
INSTALL_TARGET=	site-install install

DOCS=		COPYING.LIB ChangeLog README

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|/usr/lib/|${LOCALBASE}/libdata/|g ; \
		s|/usr/libexec/|${LOCALBASE}/libexec/|g' \
			${WRKSRC}/sample/README ${WRKSRC}/sample/*.server
	@${REINPLACE_CMD} -e 's|bin/ruby|bin/env ruby|g' \
		${WRKSRC}/sample/hello-applet.rb
	@${FIND} ${WRKSRC} -name '*.bak' -delete

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
