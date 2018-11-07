# $FreeBSD$

PORTNAME=	hisat2
# DISTVERSION=	2.1.0p20180625
DISTVERSION=	2.1.0-20
DISTVERSIONSUFFIX=	-g5622808
CATEGORIES=	wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Alignment program for mapping next-generation sequencing reads

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake perl5 python shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	hisat2 hisat2-build hisat2-inspect *.py \
		scripts/*.sh scripts/*.pl \
		hisatgenotype_modules/*.py \
		hisatgenotype_scripts/*.py \
		hisatgenotype_scripts/*.sh
GH_ACCOUNT=	infphilo

MAKEFILE=	${FILESDIR}/Makefile.pkg

.include <bsd.port.mk>
