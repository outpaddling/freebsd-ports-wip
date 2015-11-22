# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	splitter
PORTVERSION=	0.2.4
CATEGORIES=	biology
MASTER_SITES=	http://kirill-kryukov.com/study/tools/fasta-splitter/files/
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	fasta-

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Divides a FASTA file into a set of smaller, approximately equally sized files

#LICENSE=

USES=		zip

RUN_DEPENDS=	p5-File-Util>=3:${PORTSDIR}/devel/p5-File-Util \
		p5-Getopt-Long>=2:${PORTSDIR}/devel/p5-Getopt-Long

# use strict;
# use File::Basename qw(basename);use File::Path qw(make_path);
# use File::Util;
# use Getopt::Long qw(:config pass_through);

NO_BUILD=	yes

PLIST_FILES=	bin/fasta-splitter.pl

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/fasta-splitter.pl \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
