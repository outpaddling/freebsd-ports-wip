PORTNAME=	ls-dyna10
DISTVERSION=	10.0.0
CATEGORIES=	wip science linux
MASTER_SITES=	http://ftp.lstc.com/user/ls-dyna/R${DISTVERSION}/linux.64/
PKGNAMEPREFIX=	linux-
DISTFILES=	${SINGLE_PRECISION}.gz ${DOUBLE_PRECISION}.gz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	General-purpose finite element program for simulating complex problems
WWW=		https://www.lstc.com/

LICENSE=	LS_DYNA
LICENSE_NAME=	LS-DYNA License
LICENSE_TEXT=	Please refer to: http://www.lstc.com/download
LICENSE_PERMS=	none

USES=		linux
USE_LINUX=	xorglibs

NO_BUILD=	yes

PLIST_FILES=	bin/${SINGLE_PRECISION} bin/${DOUBLE_PRECISION}

SINGLE_PRECISION=		ls-dyna_smp_s_r1000_x64_redhat59_ifort160
DOUBLE_PRECISION=		ls-dyna_smp_d_r1000_x64_redhat59_ifort160

do-extract:
	@${MKDIR} ${WRKSRC}
	@(cd ${WRKSRC} && ${GUNZIP_CMD} -c ${DISTDIR}/${SINGLE_PRECISION}.gz \
		> ${SINGLE_PRECISION})
	@(cd ${WRKSRC} && ${GUNZIP_CMD} -c ${DISTDIR}/${DOUBLE_PRECISION}.gz \
		> ${DOUBLE_PRECISION})

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${SINGLE_PRECISION} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${DOUBLE_PRECISION} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
