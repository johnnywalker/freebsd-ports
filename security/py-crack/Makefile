# New ports collection makefile for:	py-crack
# Date created:		2005-07-17
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	pycrack
PORTVERSION=	0.5.1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	python-crack
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-crack-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python bindings to cracklib

BUILD_DEPENDS=	${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYSETUP=	distutil.py
GNU_CONFIGURE=	yes

PLIST_FILES:=	${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,}/_crack.so \
		${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,}/crack.py

CONFIGURE_ENV=	"DEFAULT_DICTPATH=${LOCALBASE}/libdata/cracklib/pw_dict"
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's/setup(/setup(name="${PORTNAME}",version="${PORTVERSION}",/' \
		${WRKSRC}/distutil.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/crack.py ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
