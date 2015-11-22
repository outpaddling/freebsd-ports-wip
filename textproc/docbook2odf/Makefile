# New ports collection makefile for:	docbook2odf
# Date created:		2010-09-06
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	docbook2odf
PORTVERSION=	0.244
CATEGORIES=	textproc
MASTER_SITES=	http://open.comsultia.com/docbook2odf/dwn/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Docbook to ODF converter

LICENSE=	GPLv2

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Sablotron.pm:${PORTSDIR}/textproc/p5-XML-Sablotron \
		${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip

USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -e 's|/usr/share|/usr/local/share|g' '{}' \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/utils/docbook2odf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/docbook2odf.1 ${MAN1PREFIX}/man/man1
	${CP} -R ${WRKSRC}/ ${DATADIR}

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
