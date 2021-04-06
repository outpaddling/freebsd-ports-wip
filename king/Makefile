
PORTNAME=	king
DISTVERSION=	2.2.2
CATEGORIES=	wip biology
MASTER_SITES=	http://people.virginia.edu/~wc9c/KING/executables/
DISTNAME=	KING${DISTVERSION}code

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Kinship-based INference for Gwas

# Fake to avoid download delays
LICENSE=	BSD2CLAUSE
#LICENSE_FILE=

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/king

do-build:
	(cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o king *.cpp)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/king ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
