
PORTNAME=	splitter
PORTVERSION=	0.2.4
CATEGORIES=	wip biology
MASTER_SITES=	http://kirill-kryukov.com/study/tools/fasta-splitter/files/
PKGNAMEPREFIX=	fasta-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Divides FASTA file into a smaller approx. equal sized set of files

LICENSE=	ZLIB

RUN_DEPENDS=	p5-File-Util>=3:devel/p5-File-Util \
		p5-Getopt-Long>=2:devel/p5-Getopt-Long

USES=		zip

# use strict;
# use File::Basename qw(basename);use File::Path qw(make_path);
# use File::Util;
# use Getopt::Long qw(:config pass_through);

NO_BUILD=	yes

PLIST_FILES=	bin/fasta-splitter.pl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/fasta-splitter.pl \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
