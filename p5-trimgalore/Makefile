# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	trimgalore
PORTVERSION=	0.4.4
CATEGORIES=	wip perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Wrapper around Cutadapt and FastQC for adapter and quality trimming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-IPC-Open3-Simple>=0:devel/p5-IPC-Open3-Simple \
		p5-File-Spec-Native>=0:devel/p5-File-Spec-Native \
		p5-File-BaseDir>=0:devel/p5-File-BaseDir \
		p5-Cwd-Guard>=0:devel/p5-Cwd-Guard \
		${PYTHON_PKGNAMEPREFIX}cutadapt>0:wip/py-cutadapt \
		fastqc>0:wip/fastqc

USES=		perl5 python shebangfix
SHEBANG_FILES=	trim_galore
USE_PERL5=	run

USE_GITHUB=	yes
GH_ACCOUNT=	FelixKrueger

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/TrimGalore-${PORTVERSION}

PLIST_FILES=	bin/trim_galore

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/trim_galore ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
