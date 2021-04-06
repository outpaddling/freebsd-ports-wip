# Do not upgrade this port before testing the new version with biology/py-qiime
# 1.1.1 does not work with qiime

PORTNAME=	infernal
PORTVERSION=	1.0.2
CATEGORIES=	wip biology
MASTER_SITES=	http://eddylab.org/infernal/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Search DNA databases for RNA structure and sequence similarities

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
# 1.1.1 USES=		gmake

MAKE_JOBS_UNSAFE=	yes

# 1.1.1 CONFIGURE_ARGS+=	--host=x86_64

post-patch:
	${REINPLACE_CMD} -e 's|@prefix@|${STAGEDIR}@prefix@|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
