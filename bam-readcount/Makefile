
PORTNAME=	bam-readcount
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Count DNA sequence reads in BAM files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs
RUN_DEPENDS=	samtools>0:biology/samtools

USES=		cmake
USE_GITHUB=	yes

GH_ACCOUNT=	genome

.include <bsd.port.mk>
