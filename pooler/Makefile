PORTNAME=		pooler
DISTVERSIONPREFIX=	v
DISTVERSION=		1.77
CATEGORIES=		wip biology

MAINTAINER=	ssb22@cam.ac.uk
COMMENT=	Optimise DNA sequencing primer-set combinations

LICENSE=	APACHE20
LICENSE_FILE=	${WRKDIR}/${GH_PROJECT}-${PORTVERSION}/LICENSE

# Not neeed on x86, aarch64, or ppc64-13.x
# USES=		compiler:openmp
USE_GITHUB=	yes

GH_ACCOUNT=	ssb22
GH_PROJECT=	PrimerPooler

WRKSRC_SUBDIR=	pooler
CFLAGS+=	-fopenmp

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/pooler man/man1/pooler.1.gz

.include <bsd.port.mk>
