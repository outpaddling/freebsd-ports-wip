PORTNAME=	tempo2
PORTVERSION=	2013.9.1
CATEGORIES=	wip astro
# http://downloads.sourceforge.net/project/tempo2/Tempo2%20Release%20Versions/tempo2-2013.9.1.tar.gz?r=http%3A%2F%2Fsourceforge.net%2Fprojects%2Ftempo2%2F&ts=1445380186&use_mirror=iweb
MASTER_SITES=	SF/../project/tempo2/Tempo2%20Release%20Versions/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Pulsar software for forming timing residuals.

LICENSE=	GPLv2

USES=		fortran libtool
GNU_CONFIGURE=	yes

LIB_DEPENDS=	libpgplot.so:graphics/pgplot

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS+=	--with-tempo2-plug-dir=${PREFIX}/lib/tempo2/plugins

post-configure:
	${REINPLACE_CMD} \
		-e 's|-p $$(plugindir)|-p ${STAGEDIR}$$(plugindir)|g' \
		-e 's|t2 $$(plugindir)|t2 ${STAGEDIR}$$(plugindir)|g' \
		${WRKSRC}/plugin/Makefile

post-install:
	cd ${WRKSRC}/plugin && ${MAKE} plugins-install
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tempo2/plugins/*

.include <bsd.port.mk>
