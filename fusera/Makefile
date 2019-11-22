# $FreeBSD$

PORTNAME=	fusera
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	wip biology

MAINTAINER=	bacon@toshiba.acadix.biz
COMMENT=	FUSE interface to the NCBI Sequence Read Archive (SRA)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	mitre

MAKE_ENV=	GOPATH="${WRKSRC}:${WRKSRC}/vendor"

post-patch:
	${MKDIR} ${WRKSRC}/vendor/github.com/mitre/fusera
.for f in cmd awsutil flags fuseralib sdl
	${MV} ${WRKSRC}/${f} ${WRKSRC}/vendor/github.com/mitre/fusera
.endfor

.include <bsd.port.mk>
