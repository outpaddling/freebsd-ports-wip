# This is a stopgap measure.  Bedops is open source and portable and will
# not require much work to build natively, but we had a researcher under
# heavy time pressure, so I used the linux binaries to get him started.

PORTNAME=	bedops
PORTVERSION=	2.4.20
CATEGORIES=	wip biology
MASTER_SITES=	http://github.com/bedops/bedops/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	bedops_linux_x86_64-v${PORTVERSION}.v2

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	High-performance genomic feature operations

LICENSE=	GPLv2

USES=		tar:bzip2 linux shebangfix
SHEBANG_FILES=	bam2bed \
		bam2starch \
		gff2bed \
		gff2starch \
		gtf2bed \
		gtf2starch \
		gvf2bed \
		gvf2starch \
		psl2bed \
		psl2starch \
		rmsk2bed \
		rmsk2starch \
		sam2bed \
		sam2starch \
		vcf2bed \
		vcf2starch \
		wig2bed \
		wig2starch

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
