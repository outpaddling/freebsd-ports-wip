# $FreeBSD$

PORTNAME=	fastqc
PORTVERSION=	0.11.5
CATEGORIES=	wip biology java perl5
MASTER_SITES=	https://www.bioinformatics.babraham.ac.uk/projects/fastqc/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quality control tool for high throughput sequence data

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NO_ARCH=	yes
USES=		zip perl5 shebangfix
USE_JAVA=	yes
USE_PERL5=	run
SHEBANG_FILES=	fastqc

WRKSRC=		${WRKDIR}/FastQC

NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$RealBin$$delimiter|${DATADIR}$$delimiter${JAVAJARDIR}/fastqc$$delimiter|g' \
		-e 's|$$RealBin/|${JAVAJARDIR}/fastqc/|g' \
		${WRKSRC}/fastqc

# Help files are not optional docs, but required for Help menu functionality
do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/fastqc
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${JAVAJARDIR}/fastqc
	${INSTALL_SCRIPT} ${WRKSRC}/fastqc \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} Configuration \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} Templates \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} Help \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} net \
		${STAGEDIR}${JAVAJARDIR}/fastqc
	cd ${WRKSRC} && ${COPYTREE_SHARE} uk \
		${STAGEDIR}${JAVAJARDIR}/fastqc
	cd ${WRKSRC} && ${COPYTREE_SHARE} org \
		${STAGEDIR}${JAVAJARDIR}/fastqc

.include <bsd.port.mk>
