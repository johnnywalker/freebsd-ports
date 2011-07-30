# New ports collection makefile for:	rubygems-algorithms
# Date created:		2011-07-23
# Whom:			Jonathan Walker <kallous@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ruby-dbus
PORTVERSION=	0.6.1
CATEGORIES=	devel rubygems

MAINTAINER=	kallous@gmail.com
COMMENT=	Ruby module for interaction with D-Bus

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

FETCH_DEPENDS=    git:${PORTS_DIR}/devel/git

.include <bsd.port.pre.mk>

TMPDIR?=    /tmp
NO_CHECKSUM=    yes

do-fetch:
	@TMPGITDIR=`mktemp -d -t ruby-dbus` && \
	git clone git://github.com/mvidner/ruby-dbus.git $${TMPGITDIR} && \
	cd $${TMPGITDIR} && \
	git checkout da2427d1630476aaf4a6 && \
	echo 0.6.1 >VERSION && \
	rake gem && \
	${CP} -f pkg/ruby-dbus-0.6.1.gem ${_DISTDIR}/ && \
	cd ${_DISTDIR} && \
	${RM} -rf $${TMPGITDIR}

.include <bsd.port.post.mk>
