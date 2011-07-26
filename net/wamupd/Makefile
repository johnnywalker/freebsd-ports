# Ports collection makefile for:    wamupd
# Date created:         4 Jul 2011
# Whom:                 jdw
#
# $FreeBSD$
#

PORTNAME=	wamupd
PORTVERSION=	1.1
CATEGORIES=	net

MAINTAINER=	kallous@gmail.com
COMMENT=	A Ruby program to update DNS-SD using Avahi & D-Bus

USE_RUBY=       yes
RUBY_VER=       1.9
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USE_RC_SUBR=	wamupd

.ifdef GETTING_BUILD_DEPENDS
GEM_DEPENDS=    algorithms \
                ruby-dbus \
                dnsruby \
                logger \
		daemons

ruby-dbus_GEM_VERSION=	0.6.[!0]
.else
BUILD_DEPENDS!=	make -f ${.MAKEFILE_LIST:M*Makefile} GETTING_BUILD_DEPENDS=yes get-build-depends
RUN_DEPENDS:=	${BUILD_DEPENDS}
.endif

FETCH_DEPENDS=    git:${PORTSDIR}/devel/git

TMPDIR?=    /tmp
NO_CHECKSUM=    yes

CONF_FILES=	wamupd.yaml.dist

.ifdef GETTING_BUILD_DEPENDS
get-build-depends:
.for _GEM_DEPEND in ${GEM_DEPENDS}
.ifdef ${_GEM_DEPEND}_GEM_VERSION
	@echo "`find ${LOCALBASE}/${GEMS_DIR}/ -name \"${_GEM_DEPEND}-${${_GEM_DEPEND}_GEM_VERSION}\"`:${PORTSDIR}/devel/rubygem-${_GEM_DEPEND}"
.else
	@echo "`find ${LOCALBASE}/${GEMS_DIR}/ -name \"${_GEM_DEPEND}-*\"`:${PORTSDIR}/devel/rubygem-${_GEM_DEPEND}"
.endif
.endfor
.endif

do-fetch:
	@TMPGITDIR=`mktemp -d -t wamupd` && \
	git clone git://github.com/johnnywalker/wamupd.git $${TMPGITDIR} && \
	cd $${TMPGITDIR} && \
	rake build && \
	${CP} -f pkg/wamupd-1.0.gem ${_DISTDIR}/ && \
	cd ${_DISTDIR} && \
	${RM} -rf $${TMPGITDIR}

post-install:
	@${ECHO_MSG} "===> Installing configuration files"
	@${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}
	@for i in ${CONF_FILES}; do \
	    ${INSTALL_SCRIPT} ${FILESDIR}/$${i} ${PREFIX}/etc/$${i}; \
	    if [ ! -f ${PREFIX}/etc/$${i%.dist} ]; then \
		${CP} ${PREFIX}/etc/$${i} ${PREFIX}/etc/$${i%.dist}; \
	    fi; \
	    ${ECHO_CMD} "@unexec if cmp -s %D/etc/$${i%.dist} %D/etc/$${i}; then rm -f %D/etc/$${i%.dist}; fi" >> ${TMPPLIST}; \
	    ${ECHO_CMD} "etc/$${i%}" >> ${TMPPLIST}; \
	done

.include <bsd.port.mk>
