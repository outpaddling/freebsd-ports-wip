PORTNAME=	R-studio
PORTVERSION=	0.95.262
CATEGORIES=	wip math
MASTER_SITES=	https://github.com/rstudio/rstudio/tarball/ \
		https://s3.amazonaws.com/rstudio-buildtools/
DISTFILES=	v${PORTVERSION} \
		gin-1.5.zip \
		gwt-2.4.0.zip \
		junit-4.9b3.jar

EXTRACT_ONLY=	v${PORTVERSION}

FETCH_ARGS=	-Fpr 

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	GUI for R statistical software

USE_CMAKE=	yes
USE_ANT=	yes

CMAKE_ARGS+=	-DDL_LIBRARIES:FILEPATH=/usr/lib \
		-DUUID_LIBRARIES:FILEPATH=/usr/lib

WRKSRC=		${WRKDIR}/rstudio-rstudio-928abf1

BUILD_DEPENDS=	R:${PORTSDIR}/math/R \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	R:${PORTSDIR}/math/R

post-patch:
	${CP} ${DISTDIR}/gin-1.5.zip ${WRKSRC}/dependencies/common
	${CP} ${DISTDIR}/gwt-2.4.0.zip ${WRKSRC}/dependencies/common
	${CP} ${DISTDIR}/junit-4.9b3.jar ${WRKSRC}/dependencies/common
	(cd ${WRKSRC}/dependencies/common && ./install-gwt)

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
