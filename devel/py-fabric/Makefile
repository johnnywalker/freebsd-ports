# New ports collection makefile for:	py-fabric
# Date created:		2009-03-15
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fabric
PORTVERSION=	1.0.2
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	http://code.fabfile.org/projects/fabric/files/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Fabric-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	A simple pythonic remote deployment tool

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=1.9:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}paramiko>=1.7.6:${PORTSDIR}/security/py-paramiko

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Fabric

.include <bsd.port.mk>
