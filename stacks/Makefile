# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	stacks
PORTVERSION=	1.46
CATEGORIES=	wip biology
MASTER_SITES=	http://catchenlab.life.illinois.edu/stacks/source/

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Software pipeline for building loci from short-read sequences

LICENSE=	GPLv2

USES=		gmake python shebangfix
SHEBANG_FILES=	scripts/*.pl scripts/*.py
GNU_CONFIGURE=	yes

LDFLAGS+=	-lpthread

.include <bsd.port.mk>
