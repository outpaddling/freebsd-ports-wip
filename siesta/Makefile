# Created by: Jason Bacon <jwb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	siesta
PORTVERSION=	3.2
CATEGORIES=	wip science
DISTNAME=	${PORTNAME}-${PORTVERSION}-pl-4
EXTRACT_SUFX=	.tgz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Spanish Initiative for Electronic Simulations with Thousands of Atoms

# LICENSE=	Siesta license

RESTRICTED=	Redistribution is not permitted

USES=		gmake fortran
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--srcdir=../Src

FCFLAGS+=	-DGRID_DP -DPHI_GRID_SP -O2

WRKSRC=		${WRKDIR}/${DISTNAME}/Obj

PLIST_FILES=	bin/siesta bin/transiesta

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		is not redistributable. You must agree to the license terms at http://departments.icmab.es/leem/siesta/CodeAccess/selector.html and download ${DISTFILES} manually. Then copy ${DISTFILES} into ${DISTDIR} and run make again.  Note that the license for computer centers requires that systems managers limit access to users who have agreed to the user license
.endif

pre-configure:
	(cd ${WRKSRC} && ${SH} ../Src/obj_setup.sh && ${CP} ../Src/configure .)

do-build:
	(cd ${WRKSRC} && \
		${MAKE_CMD} siesta && \
		${MV} siesta siesta.save && \
		${MAKE_CMD} clean transiesta)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/siesta.save ${STAGEDIR}${PREFIX}/bin/siesta
	${INSTALL_PROGRAM} ${WRKSRC}/transiesta ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
