PORTNAME=	linux-birdsuite
PORTVERSION=	1.5.5
CATEGORIES=	wip biology
MASTER_SITES=	https://www.broadinstitute.org/ftp/pub/mpg/birdsuite/
DISTNAME=	birdsuite_executables_${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Report SNP genotypes, CNPs, and novel, rare, or de novo CNVs

# Just a guess
LICENSE=	GPLv2

USES=		python shebangfix tar:tgz
SHEBANG_FILES=	birdsuite.sh apt-probeset-summarize.sh

# Need Linux Java?
USE_JAVA=	yes
# https://www.broadinstitute.org/birdsuite/birdsuite-install#birdsuite_prerequisites
# Site says Affymetrix Power Tools (APT) 1.8.6 or 1.10.2, binaries
# Will 1.19 work?
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>=1.2:math/py-numpy \
		R>0:math/R \
		R-cran-mclust>0:wip/R-cran-mclust \
		linux-apt>=0:wip/linux-apt
# Affymetrix library bundle for Genome-Wide Human SNP Array 6.0
# Appears to be Windows only
# http://www.affymetrix.com/Auth/support/downloads/library_files/genomewidesnp6_libraryfile.zip

NO_BUILD=	yes

WRKSRC=		${WRKDIR}

# Far from finished
# https://www.broadinstitute.org/birdsuite/birdsuite-install#birdsuite_installation
do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} *.sh \
		birdseed birdseye_32 birdseye_64 \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
