PORTNAME=		raxml
DISTVERSIONPREFIX=	v
DISTVERSION=		8.2.12
CATEGORIES=		wip biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Phylogenetic Analysis and Post-Analysis of Large Phylogenies
WWW=		https://cme.h-its.org/exelixis/web/software/raxml/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

USE_GITHUB=	yes

GH_ACCOUNT=	stamatak
GH_PROJECT=	standard-RAxML

MAKEFILE=	${FILESDIR}/Makefile
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/raxmlHPC

.include <bsd.port.mk>
