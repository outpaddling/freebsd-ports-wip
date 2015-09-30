# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	cufflinks
PORTVERSION=	2.2.1
CATEGORIES=	biology
MASTER_SITES=	http://cole-trapnell-lab.github.io/cufflinks/assets/downloads/
# Switch to USE_GITHUB?

MAINTAINER=	jwbacon@tds.net
COMMENT=	Transcript assembly, differential expression and regulation for RNA-Seq

USES=		python
GNU_CONFIGURE=	yes

# Is samtools 1.2 OK?  Had been using 0.1.19.
# BUILD_DEPENDS=	samtools:${PORTSDIR}/biology/samtools \
BUILD_DEPENDS=	${LOCALBASE}/lib/libbam.a:/usr/wip/biology/samtools \
		bjam:${PORTSDIR}/devel/boost-jam \
		eigen>=3.2.20:${PORTSDIR}/math/eigen3
LIB_DEPENDS+=	libboost_iostreams.so:${PORTSDIR}/devel/boost-libs

CFLAGS+=	-I${LOCALBASE}/include/eigen3 \
		-Wno-unused -Wno-reorder -Wno-sign-compare

MAKE_JOBS_UNSAFE=yes

# FIXME: Find logl somewhere instead of falling back to log
# FIXME: boost problem with long double and hackaround: https://svn.boost.org/trac/boost/query?status=!closed&page=3&order=summary&row=description: #9331
# Just using double instead for now
post-patch:
	${REINPLACE_CMD} \
		-e 's|logl|log|g' \
		-e 's|long double|double|g' \
		${WRKSRC}/src/*.cpp \
		${WRKSRC}/src/*.h

.include <bsd.port.mk>
