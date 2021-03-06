# New ports collection makefile for:    apache mod_auth_mysql_another
# Date created:		2002/04/20
# Whom:			mbr@freebsd.org
#
# $FreeBSD$

PORTNAME=	mod_auth_mysql
PORTVERSION=	3.0.0
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF/modauthmysql/modauthmysql/${PORTVERSION}
PKGNAMESUFFIX=	_another

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Allows users to use MySQL databases for user authentication

MAKE_JOBS_SAFE=	yes

USE_MYSQL=	YES
USE_APACHE=	13+

SHORTMODNAME=	mysql_auth
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
AP_INC=	${LOCALBASE}/include/mysql
AP_LIB=	${LOCALBASE}/lib/mysql
AP_EXTRAS=	-lmysqlclient -lz -lm

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} > 20
AP_EXTRAS+=	-DAPACHE2
.endif

.if ${APACHE_VERSION} > 20
post-patch:
	${REINPLACE_CMD} -e "s|APR_XtOffsetOf|APR_OFFSETOF|g" \
		-e "s|APR_XtOffset|APR_OFFSET|g" ${WRKSRC}/mod_auth_mysql.c
.else
pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s|%%APXS%%|${APXS}|g" \
	-e "s|%%AP_INC%%|${AP_INC}|g" -e "s|%%AP_LIB%%|${AP_LIB}|g" ${WRKSRC}/Makefile
.endif

.if !defined(NOPORTDOCS)
post-build:
	@${ECHO} "%%PORTDOCS%%%%DOCSDIR%%/CONFIGURE" >> ${PLIST}
	@${ECHO} "%%PORTDOCS%%%%DOCSDIR%%/CHANGES" >> ${PLIST}
	@${ECHO} "%%PORTDOCS%%@dirrm %%DOCSDIR%%" >> ${PLIST}

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CONFIGURE ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
