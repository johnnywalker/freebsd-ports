# New ports collection makefile for:	gpodder
# Date created:		20 October 2007
# Whom:			Chess Griffin <chess@chessgriffin.com>
#
# $FreeBSD$
#

PORTNAME=	gpodder
PORTVERSION=	2.20
CATEGORIES=	multimedia
MASTER_SITES=	http://gpodder.org/src/ \
		http://thp.io/2010/mygpoclient/:mygpoclient \
		CHEESESHOP:mygpoclient
MASTER_SITE_SUBDIR=	source/m/mygpoclient/:mygpoclient
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		${MGC_DISTNAME}${EXTRACT_SUFX}:mygpoclient

MAINTAINER=	rm@FreeBSD.org
COMMENT=	A GTK2 podcast aggregrator written in Python

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}notify>=0:${PORTSDIR}/devel/py-notify \
		xdg-open:${PORTSDIR}/devel/xdg-utils \
		wget:${PORTSDIR}/ftp/wget \
		gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		${PYTHON_PKGNAMEPREFIX}feedparser>=0:${PORTSDIR}/textproc/py-feedparser

OPTIONS=	COVERART "Cover Art syncing support" off \
		IPOD "iPod synchronization support" off \
		MP3TAG "MP3 ID3 tag update support" off \
		OGG2MP3 "Ogg Vorbis conversion to MP3 support" off \
		SHOWNOTES "HTML episode shownotes support" off

USE_PYTHON=	2.6-2.7
USE_GNOME=	pygtk2
USE_GETTEXT=	yes
USE_GMAKE=	yes
ALL_TARGET=	messages
INSTALLS_ICONS=	yes
INSTALLS_EGGINFO=	yes

MAN1=		gpo.1 ${PORTNAME}.1 ${PORTNAME}-backup.1

MGC_DISTNAME=	mygpoclient-1.6
MGC_WRKSRC=	${WRKDIR}/${MGC_DISTNAME}/mygpoclient

.include <bsd.port.pre.mk>

.if defined(WITH_COVERART)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging
.endif

.if defined(WITH_IPOD)
LIB_DEPENDS+=	gpod.7:${PORTSDIR}/audio/libgpod
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mad>=0:${PORTSDIR}/audio/py-mad
.if !exists(${PYTHON_SITELIBDIR}/gpod/__init__.py)
IGNORE=		requires Python bindings for libgpod. Please uninstall libgpod and reinstall with Python support
.endif
.endif

.if defined(WITH_MP3TAG)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}eyed3>=0:${PORTSDIR}/audio/py-eyed3
.endif

.if defined(WITH_OGG2MP3)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame \
		oggdec:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_SHOWNOTES)
USE_GNOME+=	pygnomeextras
.endif

# ensure that setup.py can find mygpoclient module when installing gpodder
MAKE_ENV+=	PYTHONPATH="${PYTHONPREFIX_SITELIBDIR}"

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|make -C|$$(MAKE) -C|' ${WRKSRC}/Makefile

pre-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${MGC_WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${MGC_WRKSRC}

pre-install:
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/mygpoclient
	@(cd ${MGC_WRKSRC} && ${COPYTREE_SHARE} . ${PYTHONPREFIX_SITELIBDIR}/mygpoclient)

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in PKG-INFO README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
