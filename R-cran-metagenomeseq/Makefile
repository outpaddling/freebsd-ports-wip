PORTNAME=	metagenomeSeq
DISTVERSION=	1.16.0
CATEGORIES=	wip biology
MASTER_SITES=	https://bioconductor.org/packages/release/bioc/src/contrib/
# DISTmetagenomeSeq_1.16.0.tar.gz
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Determine features differentially abundant between groups of samples
WWW=		https://bioconductor.org/packages/release/bioc/html/metagenomeSeq.html

LICENSE=	ART20
#LICENSE_FILE=	

# 'Biobase', 'limma', 'glmnet', 'matrixStats', 'gplots'
CRAN_DEPENDS=	R-cran-RColorBrewer>0:graphics/R-cran-RColorBrewer \
		R-cran-foreach>0:devel/R-cran-foreach
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
