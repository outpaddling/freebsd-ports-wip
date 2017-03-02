# Created by: Jason Bacon <bacon@zebra.acadix.biz>
# $FreeBSD$

PORTNAME=	linux-birdsuite
PORTVERSION=	1.5.5
CATEGORIES=	biology
MASTER_SITES=	https://www.broadinstitute.org/ftp/pub/mpg/birdsuite/
DISTNAME=	birdsuite_executables_${PORTVERSION}

MAINTAINER=	bacon@zebra.acadix.biz
COMMENT=	Report SNP genotypes, CNPs, and novel, rare, or de novo CNVs

# Just a guess
LICENSE=	GPLv2

USES=		python tar:tgz
# Need Linux Java?
USE_JAVA=	yes
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>=1.2:math/py-numpy \
		R>0:math/R \
		R-cran-mclust>0:/usr/wip/math/R-cran-mclust

RUN_DEPENDS=	linux-apt>=0:/usr/wip/biology/linux-apt

#    Affymetrix library bundle for Genome-Wide Human SNP Array 6.0
#    http://www.affymetrix.com/Auth/support/downloads/library_files/genomewidesnp6_libraryfile.zip

NO_BUILD=	yes

.include <bsd.port.mk>
