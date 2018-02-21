# $FreeBSD$

PORTNAME=	amrplusplus
PORTVERSION=	1.0.0
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Identify and characterize resistance genes within sequence data

LICENSE=	MIT

# Add nextflow dep?
RUN_DEPENDS=	trimmomatic>0:wip/trimmomatic \
		bwa>0:biology/bwa \
		samtools>0:biology/samtools \
		snpfinder>0:wip/snpfinder \
		resistome:wip/resistomeanalyzer \
		rarefaction:wip/rarefactionanalyzer

USES=		python shebangfix
SHEBANG_FILES=	bin/*
USE_GITHUB=	yes
GH_ACCOUNT=	cdeanj
GH_TAGNAME=	5ea91ac39ba83da850f33e4d7c519cf05ff64b6c

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
