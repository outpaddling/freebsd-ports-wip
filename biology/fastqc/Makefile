# Created by: Jason Bacon <bacon@unixdev.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	fastqc
PORTVERSION=	0.10.1
CATEGORIES=	biology
MASTER_SITES=	http://www.bioinformatics.babraham.ac.uk/projects/fastqc/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	A quality control tool for high throughput sequence data

LICENSE=	GPLv3

USES=		zip perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	fastqc

WRKSRC=		${WRKDIR}/FastQC

NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/fastqc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fastqc ${WRKSRC}/*.jar \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'Contaminants Templates uk' \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'Help' \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
