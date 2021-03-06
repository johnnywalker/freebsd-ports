# New ports collection makefile for:	gramps
# Date created:		2003-12-25
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$

PORTNAME=	gramps
PORTVERSION=	3.3.0
CATEGORIES=	science gnome python
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	freebsd@troback.com
COMMENT=	A GTK/GNOME-based genealogy program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb \
		${PYXML}

USE_BDB=	43
USE_PYTHON=	2.6+
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pygnome2 pygnomeextras desktopfileutils gnomedocutils
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	GMSGFMT="${LOCALBASE}/bin/msgfmt"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		gramps.1
MANLANG=	"" cs fr nl pl sv

OPTIONS=	ENCHANT "Spellchecking support" off \
		PYWEBKITGTK "Use webkit backend for Geographic view" on \
		GRAPHVIZ "Use graphviz for graphs creating" on \
		EXIV "Managing exiv metadata support" on

.include <bsd.port.pre.mk>

.if defined(WITH_ENCHANT)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}enchant>=0:${PORTSDIR}/textproc/py-enchant
.endif
.if defined(WITH_PYWEBKITGTK)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}webkitgtk>=0:${PORTSDIR}/www/py-webkitgtk
.endif
.if defined(WITH_GRAPHVIZ)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}graphviz>-0:${PORTSDIR}/graphics/py-graphviz
.endif
.if defined(WITH_EXIV)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}exiv2>=0.1.3:${PORTSDIR}/graphics/py-exiv2
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
