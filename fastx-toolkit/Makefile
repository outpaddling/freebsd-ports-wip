# $FreeBSD: head/biology/fastx-toolkit/Makefile 460452 2018-01-31 01:07:07Z jwb $

PORTNAME=	fastx_toolkit
PORTVERSION=	0.0.14
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	CLI tools for Short-Reads FASTA/FASTQ files preprocessing

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtextutils.so:biology/libgtextutils

USES=		autoreconf libtool perl5 pkgconfig shebangfix
USE_PERL5=	run
SHEBANG_FILES=	scripts/*.pl

USE_GITHUB=	yes
GH_ACCOUNT=	agordon

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
