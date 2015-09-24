# Created by: Jason Bacon <bacon@unixdev.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	fastx_toolkit
PORTVERSION=	0.0.14
CATEGORIES=	biology science

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	CLI tools for Short-Reads FASTA/FASTQ files preprocessing

LICENSE=	AGPLv3

LIB_DEPENDS=	libgtextutils.so:/usr/wip/biology/libgtextutils

USES=		perl5 pkgconfig shebangfix tar:bzip2
USE_PERL5=	run
SHEBANG_FILES=	scripts/*.pl

USE_GITHUB=	yes
GH_ACCOUNT=	agordon
GH_PROJECT=	fastx_toolkit

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	PKG_CONFIG_PATH=${LOCALBASE}/lib/pkgconfig

.include <bsd.port.mk>
