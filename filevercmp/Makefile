# $FreeBSD$

PORTNAME=	filevercmp
PORTVERSION=	0.0.0p20151117
CATEGORIES=	wip sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Filevercmp function as in sort --version-sort

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	cccb6ba1fffa2898718b0a96c63279e0979e002b

PLIST_FILES=	bin/filevercmp include/filevercmp.h lib/libfilevercmp.a

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
