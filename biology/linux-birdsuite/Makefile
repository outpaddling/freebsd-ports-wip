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

USES=		tar:tgz

RUN_DEPENDS=	linux-apt>=0:/usr/wip/biology/linux-apt

#LICENSE=	
#LICENSE_FILE=	

#    Java 1.5 or higher http://www.java.com
#    Python 2.5.2 or higher http://www.python.org
#    numpy Python package, version 1.2 or higher http://numpy.scipy.org
#    R 2.4 or higher http://www.r-project.org
#    mclust R package, version 3 or higher
#    http://lib.stat.cmu.edu/R/CRAN/web/packages/mclust/index.html
#    Affymetrix library bundle for Genome-Wide Human SNP Array 6.0
#    http://www.affymetrix.com/Auth/support/downloads/library_files/genomewidesnp6_libraryfile.zip

NO_BUILD=	yes

.include <bsd.port.mk>
