PORTNAME=	GenomeAnalysisTKQueue
PORTVERSION=	3.1
CATEGORIES=	wip biology science
DISTNAME=	Queue-${PORTVERSION}-1

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Analyse next-generation resequencing data
WWW=		https://port.home.page/

#LICENSE=	restricted

USES=		tar:bzip2
USE_JAVA=	yes

RUN_DEPENDS+=	R:math/R

RESTRICTED=	License required for commercial use

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTFILES})
IGNORE=	may not be redistributed because of licensing reasons.\
	Please register at http://fvcom.smast.umassd.edu/FVCOM/index.html\
	in order to download the source code ${DISTFILES}\
	and place it in ${DISTDIR}/${DIST_SUBDIR}/
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/*.jar ${STAGEDIR}${PREFIX}/bin
	cd ${WRKDIR}/resources && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.post.mk>
