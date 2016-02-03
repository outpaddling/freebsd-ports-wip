# Created by: Jason Wayne Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	infernal
# 1.1.1 does not work with qiime
PORTVERSION=	1.1.1
CATEGORIES=	biology
MASTER_SITES=	http://selab.janelia.org/software/infernal/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Search DNA databases for RNA structure and sequence similarities

GNU_CONFIGURE=	yes
USES=		gmake

# Should probably patch configure to support amd64 instead
CONFIGURE_ARGS+=	--host=x86_64

.include <bsd.port.mk>
