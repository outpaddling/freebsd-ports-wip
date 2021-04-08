PORTNAME=	snptest
PORTVERSION=	2.5.2
CATEGORIES=	wip biology
MASTER_SITES=	http://www.well.ox.ac.uk/~gav/resources/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}_v${PORTVERSION}_CentOS6.5_x86_64_static

MAINTAINER=	weinertw@uwm.edu
COMMENT=	Analyze single SNP associations in genome-wide studies

LICENSE=	UNKNOWN
LICENSE_NAME=	Oxford Non-free
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

USES=		linux tar:tgz

NO_BUILD=	yes

# FIXME: unexpected reloc type in static binary Segmentation fault (core dumped)
# on some systems if the binary is stripped.  Both linux-c6 and linux-c7 may
# exhibit the issue.  Not yet seeing a key difference between systems where it
# works and those where it does not.
STRIP=		# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}_v${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

WRKSRC=		${WRKDIR}/${PORTNAME}_v${PORTVERSION}_linux_x86_64_static

.include <bsd.port.mk>
