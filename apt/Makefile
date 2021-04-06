
PORTNAME=	apt
PORTVERSION=	1.19.0
CATEGORIES=	wip biology
MASTER_SITES=	http://media.affymetrix.com/Download/updates/
DISTNAME=	APT-${PORTVERSION}_Source_Code

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	command line programs for working with Affymetrix GeneChip® arrays

USES=		gmake shebangfix zip
SHEBANG_FILES=	*.sh sdk/build/*.sh

# Not sure of version
LICENSE=	GPLv2
#LICENSE_FILE=	

BUILD_DEPENDS+=	cppunit>=0:devel/cppunit

WRKSRC=		${WRKDIR}/apt-${PORTVERSION}-src

post-patch:
	cd ${WRKSRC} && ${CHMOD} u+x ${SHEBANG_FILES} sdk/configure
	${REINPLACE_CMD} -e 's|/nfs|${WRKSRC}/release|g' \
		${WRKSRC}/run-build.sh \
		${WRKSRC}/sdk/Makefile.config \
		${WRKSRC}/sdk/build/bamboo-build.post.sh

do-build:
	@${MKDIR} ${WRKSRC}/release/bioinformatics/apt/master-dev/sdk/release
	cd ${WRKSRC} && bash ./run-build.sh

.include <bsd.port.mk>
