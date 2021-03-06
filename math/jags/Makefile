# vim: tabstop=8 softtabstop=0 noexpandtab
# Ports collection Makefile for:	jags
# Date created:		21 April 2004
# Whom:			Eric van Gyzen <vangyzen@stat.duke.edu>
#
# $FreeBSD$
#

PORTNAME=	mcmc-jags
PORTVERSION=	3.1.0
CATEGORIES=	math
MASTER_SITES=	SF:1,2,3,4
MASTER_SITE_SUBDIR=	${PORTNAME}/JAGS/${PORTVERSION:C|\..*|.x|}/Source/:1 \
		${PORTNAME}/Examples/2.x/:2 \
		${PORTNAME}/Manuals/2.x/:3 \
		${PORTNAME}/Manuals/${PORTVERSION:C|\..*|.x|}/:4
DISTFILES=	${DISTNAME:S/mcmc-//:U}${EXTRACT_SUFX}:1
.if !defined(NOPORTDOCS)
DISTFILES+=	classic-bugs.tar.gz:2 jags_developer_manual.pdf:3 \
		jags_installation_manual.pdf:4 jags_user_manual.pdf:4
EXTRACT_ONLY=	${DISTNAME:S/mcmc-//:U}${EXTRACT_SUFX}
.endif

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Just Another Gibbs Sampler

LICENSE=	GPLv2

OPTIONS=	ATLAS "use ATLAS libraries instead of BLAS and LAPACK" off

DIST_SUBDIR=	${PORTNAME}
WRKSRC=		${WRKDIR}/${PKGNAME:S/mcmc-//:U}

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_FORTRAN=	yes
USE_LDCONFIG=	yes
USE_BISON=	build
PLIST_SUB=	MODULEVERSION=${PORTVERSION:C|\..*||}

MAN1=		jags.1

.include <bsd.port.options.mk>

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
CONFIGURE_ARGS=	--with-lapack="-lalapack -lcblas" --with-blas=-lf77blas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
CONFIGURE_ARGS=	--with-lapack=-llapack --with-blas=-lblas
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/etc/Makefile.in
	@${REINPLACE_CMD} \
		-e '/@WINDOWS_FALSE@bin_SCRIPTS =/s/jags/mcmc-&/' \
		-e '/CLEANFILES =/s/jags/mcmc-&/' \
		-e '/@WINDOWS_FALSE@jags:/s/jags/mcmc-&/' \
		-e '/@WINDOWS_FALSE@.*rm -f jags/s/jags/mcmc-&/' \
		-e '/@WINDOWS_FALSE@.*mv jags.tmp jags/s/jags/mcmc-&/2' \
		${WRKSRC}/src/terminal/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for M in developer installation user
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/jags_${M}_manual.pdf \
		${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@( cd ${EXAMPLESDIR}; \
	  ${PAX} -rzf ${DISTDIR}/${DIST_SUBDIR}/classic-bugs.tar.gz \
	    -s ':^classic-bugs/*::' )
	@${SED} -i '' \
		-e '\|JAGS ?=|{s|jags|mcmc-&|;s|/usr/local|${PREFIX}|;}' \
		${EXAMPLESDIR}/vol[12]/Makefile
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.endif

.if defined(MAINTAINER_MODE)
RUN_DEPENDS+=	${LOCALBASE}/lib/R/library/coda/R/coda.rdb:${PORTSDIR}/math/R-cran-coda

testclean:	install
.for _i in 1 2
	@( cd ${EXAMPLESDIR}/vol${_i} && ${SETENV} ${MAKE_ENV} ${MAKE} \
	 	${_MAKE_JOBS} ${MAKE_ARGS} clean)
.endfor

regression-test test check:	testclean
.for _i in 1 2
	@( cd ${EXAMPLESDIR}/vol${_i} && ${SETENV} ${MAKE_ENV} ${MAKE} \
	 	${_MAKE_JOBS} ${MAKE_ARGS} check)
.endfor

.endif
.include <bsd.port.mk>
