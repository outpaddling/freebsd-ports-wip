# Created by: Jason Wayne Bacon <bacon@sciprog.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	infernal
# 1.1.1 does not work with qiime
# PORTVERSION=	1.1.1
PORTVERSION=	1.0.2
CATEGORIES=	biology
MASTER_SITES=	http://selab.janelia.org/software/infernal/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Search DNA databases for RNA structure and sequence similarities

GNU_CONFIGURE=	yes
# 1.1.1 USES=		gmake

MAKE_JOBS_UNSAFE=	yes

# 1.1.1 CONFIGURE_ARGS+=	--host=x86_64

post-patch:
	${REINPLACE_CMD} -e 's|@prefix@|${STAGEDIR}@prefix@|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
