# New ports collection makefile for:  mongodb
# Date created:        3 November 2009
# Whom:                Mirko Zinn <mail@derzinn.de>
#
# $FreeBSD$
#

PORTNAME=	mongodb
PORTVERSION=	1.8.3
CATEGORIES=	databases net
MASTER_SITES=	http://downloads.mongodb.org/src/
DISTNAME=	${PORTNAME}-src-r${PORTVERSION}

MAINTAINER=	mail@derzinn.de
COMMENT=	A NOSQL distributed document-oriented database

LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs \
		js:${PORTSDIR}/lang/spidermonkey \
		pcre:${PORTSDIR}/devel/pcre \
		nspr4:${PORTSDIR}/devel/nspr \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported to anything other than i386 and amd64"

OPTIONS=	DEVEL "Install development files (library and headers)" off

USE_SCONS=	yes
SCONS_TARGET=	all
SCONS_ARGS=	--prefix=${PREFIX} --cxx=${CXX} --cpp=${CPP}

USERS=	mongodb
GROUPS=	mongodb

USE_RC_SUBR=	mongod

.include <bsd.port.pre.mk>

.if defined(WITH_DEVEL)
SCONS_ARGS+=	--full
PLIST_SUB+=	DEVEL=""
.else
PLIST_SUB+=	DEVEL="@comment "
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/mongodb.conf ]; then \
		${TOUCH} ${PREFIX}/etc/mongodb.conf ; \
	fi

.include <bsd.port.post.mk>
