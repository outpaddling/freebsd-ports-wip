
PORTNAME=	microbiomeutil
PORTVERSION=	r20110519
CATEGORIES=	wip biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	microbiomeutil

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Utilities for processing and analyzing 16S rRNA genes

LICENSE=	BSD4CLAUSE

RUN_DEPENDS=	cdbfasta>=2010.07.22:biology/cdbfasta

USES=		tar:tgz

MODULE_PATH=	etc/modulefiles/${PORTNAME}/${PORTVERSION}

post-patch:
	${REINPLACE_CMD} \
		-e 's|gcc|$${CC}|g' \
		${WRKSRC}/NAST-iEr/Makefile
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/modulefiles/${PORTNAME}
	${INSTALL_SCRIPT} ${FILESDIR}/modulefile \
		${STAGEDIR}${LOCALBASE}/${MODULE_PATH}
	cd ${WRKSRC} && ${COPYTREE_BIN} \
		'AmosCmp16Spipeline ChimeraSlayer NAST-iEr TreeChopper WigeoN RESOURCES' ${STAGEDIR}${PREFIX}/${PORTNAME}

.include <bsd.port.mk>
