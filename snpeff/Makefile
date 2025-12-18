PORTNAME=	snpeff
DISTVERSION=	5.3a
CATEGORIES=	wip biology java python
# Non-standard tarballs
MASTER_SITES=	https://github.com/pcingola/SnpEff/archive/refs/tags/
DISTNAME=	v${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genetic variant annotation and effect prediction toolbox
WWW=		https://snpeff.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	bash:shells/bash

USES=		java python shebangfix

JAVA_VERSION=	17+
SHEBANG_FILES=	scripts/* scripts/gsa/*

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/SnpEff-${DISTVERSION}

LIBEXEC_DIR=	${PREFIX}/libexec/snpeff

pre-configure:
	${REINPLACE_CMD} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g' \
			 -e 's|%%JAVA_HOME%%|${JAVA_HOME}|g' \
			 ${WRKSRC}/scripts/snpEff ${WRKSRC}/scripts/snpSift

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/snpeff
	${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/snpEff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/snpSift ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/snpeff
	${INSTALL_DATA} ${WRKSRC}/*.config ${STAGEDIR}${JAVAJARDIR}/snpeff
	${MV} ${WRKSRC}/scripts/_OLD ${WRKSRC}
	cd ${WRKSRC}/scripts && ${COPYTREE_BIN} . ${STAGEDIR}${LIBEXEC_DIR}
	${MV} ${WRKSRC}/_OLD ${WRKSRC}/scripts

.include <bsd.port.mk>
