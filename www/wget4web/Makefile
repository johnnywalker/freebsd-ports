# New ports collection makefile for:	wget4web
# Date created:				Feb 02, 2005
# Whom:					Roman Y. Bogdanov <sam@brj.pp.ru>
#
# $FreeBSD$

PORTNAME=	wget4web
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	www ftp
MASTER_SITES=	http://irodov.nm.ru/wget4web/

MAINTAINER=	sam@brj.pp.ru
COMMENT=	WWW interface for console wget

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

USE_APACHE=	13

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

LOGSDIR?=	/var/log/wget4web
TASKDIR?=	/var/spool/wget4web
FILESDIR?=	/var/spool/wget4web/files

PLIST_SUB=	INSTALLDIR=${WWWDIR} \
		LOGSDIR=${LOGSDIR} TASKDIR=${TASKDIR} FILESDIR=${FILESDIR}

post-patch:
	@${REINPLACE_CMD} -e "s#%%LOGSDIR%%#${LOGSDIR}#; \
			     s#%%TASKDIR%%#${TASKDIR}#; \
			     s#%%FILESDIR%%#${FILESDIR}#" \
		${WRKSRC}/data/info.cgi

do-install:
	@${MKDIR} ${WWWDIR}/
	@cd ${WRKSRC}; ${FIND} . -name "*.cgi" -o -name "*.lib" \
		| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/
	${MKDIR} ${LOGSDIR}/ ${TASKDIR}/ ${FILESDIR}/
	${CHOWN} ${WWWOWN}:${WWWGRP} ${LOGSDIR}/ ${TASKDIR}/ ${FILESDIR}/

.include <bsd.port.mk>
