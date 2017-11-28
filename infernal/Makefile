# Created by: Jason Wayne Bacon <jwb@FreeBSD.org>
# $FreeBSD$
#
# 1.1.1 does not work with qiime 1.9.1

PORTNAME=	infernal
PORTVERSION=	1.1.1
CATEGORIES=	wip biology
MASTER_SITES=	http://eddylab.org/infernal/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Search DNA databases for RNA structure and sequence similarities

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
USES=		gmake

# Should probably patch configure to support amd64 instead
CONFIGURE_ARGS+=	--host=x86_64

.include <bsd.port.mk>
