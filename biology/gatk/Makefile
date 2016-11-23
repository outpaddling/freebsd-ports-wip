# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$
# Requires login to download the jar file

PORTNAME=	GenomeAnalysisTK
PORTVERSION=	3.6
CATEGORIES=	biology java
MASTER_SITES=	http://software.broadinstitute.org/gatk/download/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Analyse next-generation resequencing data

# Not really.  Set up special license case here.
LICENSE=	BSD2CLAUSE

USES=		tar:bzip2
USE_JAVA=	1.8+

RUN_DEPENDS+=	R>=3.2:math/R

NO_BUILD=	yes

RESTRICTED=	Requires (free) registration

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	may not be redistributed due to licensing reasons.\
	Please register at https://software.broadinstitute.org/gatk/\
	in order to download ${DISTFILES}\
	and place it in ${DISTDIR}/${DIST_SUBDIR}/
.endif

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKDIR}/GenomeAnalysisTK.jar \
		${STAGEDIR}${JAVAJARDIR}
	cd ${WRKDIR}/resources && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.post.mk>
