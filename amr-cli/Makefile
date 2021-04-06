
PORTNAME=	amr-cli
PORTVERSION=	0.0.0p20180402
CATEGORIES=	wip

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Identify and characterize resistance genes within sequence data

LICENSE=	BSD2CLAUSE

# Use either trimmomatic or cutadapt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cutadapt>0:py-cutadapt${FLAVOR} \
		bwa>0:biology/bwa \
		samtools>0:biology/samtools \
		snpfinder>0:wip/snpfinder \
		resistome:wip/resistomeanalyzer \
		rarefaction:wip/rarefactionanalyzer

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling
GH_TAGNAME=	306892c3d9086c3b44348c53dbd25158bf9330ba

NO_BUILD=	yes
PLIST_FILES=	bin/amr-cli bin/amr-cleanup

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/amr-* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
