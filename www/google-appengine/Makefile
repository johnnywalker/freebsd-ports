# New ports collection makefile for:	google-appengine
# Date created:		2008-04-09
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	google-appengine
PORTVERSION=	1.5.3
PORTREVISION=	0
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${PORTNAME:S|-|_|}_${PORTVERSION}.zip
.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-docs-${GAEDOCSREL}.zip
.endif

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Development tools for Google App Engine (SDK)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=${PYTHON_VER}:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6_2:${PORTSDIR}/graphics/py-imaging

MANUAL_PACKAGE_BUILD=		uses Python 2.5

PROJECTHOST=	googleappengine

USE_PYTHON=	2.5
USE_ZIP=	yes
USE_GETTEXT=	yes

WRKSRC=	${WRKDIR}/${PORTNAME:S,-,_,}

FIND_FILES=	${WRKSRC} -type f -name "*.py" -print0
FIND_FILES_BAK=	${WRKSRC} -type f -and \( -name "*.orig" -or -name "*.bak" \)

LN_OPTS=	-s

XARGS_ARGS=	-0
REINPLACE_ARGS=	-i.bak -e 's,/usr/bin/env python,&${PYTHON_VER},'

GAEDATADIR=	google lib new_project_template templates tools
GAEDOCSREL=	20110817
GAESCRIPTS=	appcfg bulkload_client bulkloader dev_appserver gen_protorpc remote_api_shell

post-patch:
	@${FIND} ${FIND_FILES} | ${XARGS} ${XARGS_ARGS} ${REINPLACE_CMD}
	@${FIND} ${FIND_FILES_BAK} -delete

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC} || true
	${PYTHON_CMD} -OO -m compileall ${WRKSRC} || true

do-install:
	${MKDIR} ${DATADIR}
.for D in ${GAEDATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${D} ${DATADIR}
.endfor
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/README ${DOCSDIR}
	cd ${WRKDIR}/google-appengine-docs-${GAEDOCSREL} && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.for S in ${GAESCRIPTS}
.  for EXT in py pyc pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${S}.${EXT} ${DATADIR}
	${LN} ${LN_OPTS} ${DATADIR}/${S}.${EXT} ${PREFIX}/bin/${S}.${EXT}
.  endfor

.endfor
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DATADIR}

.include <bsd.port.mk>
