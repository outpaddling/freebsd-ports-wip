
PORTNAME=	sratools
PORTVERSION=	2.10.9
CATEGORIES=	wip biology
MASTER_SITES=	http://ftp-trace.ncbi.nlm.nih.gov/sra/sdk/${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	sratoolkit.${PORTVERSION}-centos_linux64

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tools and libraries for using data in the INSDC Sequence Read Archives

LICENSE=	PD

USES=		linux shebangfix

SHEBANG_FILES=	example/perl/splitfastq.pl example/perl/simplefastq.pl

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/sratoolkit-${PORTVERSION}/bin
	(cd ${WRKSRC}/bin && ${COPYTREE_BIN} \
		. ${STAGEDIR}${PREFIX}/sratoolkit-${PORTVERSION}/bin)
	(cd ${WRKSRC} && ${COPYTREE_BIN} \
		"example README-vdb-config schema CHANGES README-blastn README.md" \
		${STAGEDIR}${PREFIX}/sratoolkit-${PORTVERSION})
	for f in `ls ${STAGEDIR}${PREFIX}/sratoolkit-${PORTVERSION}/bin/*.2.10.9`; do \
		${RLN} $${f} ${STAGEDIR}${PREFIX}/bin/`basename $${f%%.${PORTVERSION}}`; \
	done

.include <bsd.port.mk>
