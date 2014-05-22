# Created by: Jason Bacon <bacon@unixdev.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	fastx_toolkit
PORTVERSION=	0.0.14
CATEGORIES=	biology science
MASTER_SITES=	https://github.com/agordon/fastx_toolkit/releases/download/0.0.14/

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	CLI tools for Short-Reads FASTA/FASTQ files preprocessing

LIB_DEPENDS=	libgtextutils.so:/usr/wip/biology/gtextutils

# Just for speed: Recent GCC has better optimizer
USE_GCC=	yes
USES=		tar:bzip2 pkgconfig perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	scripts/*.pl

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	PKG_CONFIG_PATH=${LOCALBASE}/lib/pkgconfig

.include <bsd.port.mk>
