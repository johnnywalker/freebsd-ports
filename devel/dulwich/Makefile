# Ports collection makefile for:	dulwich
# Date created:		2009-10-24
# Whom:			Marco Broeder <marco.broeder@gmx.eu>
#
# $FreeBSD$
#

PORTNAME=	dulwich
PORTVERSION=	0.8.1
CATEGORIES=	devel python
MASTER_SITES=	http://samba.org/~jelmer/${PORTNAME}/ \
		http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	marco.broeder@gmx.eu
COMMENT=	Pure-Python implementation of the Git file formats and protocols

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

MAKE_JOBS_SAFE=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

FETCH_ARGS=	-Fpr	# default '-AFpr' prevents 302 redirects by launchpad

.ifndef (NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING HACKING NEWS README
.endif

post-patch:
	${REINPLACE_CMD} -e 's|PYTHON = python|PYTHON = /usr/bin/env python|g; \
		s|/usr|${PREFIX}|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/setup.py

post-install:
.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
