
PORTNAME=	ofed
PORTVERSION=	2.1.6
CATEGORIES=	wip sysutils
MASTER_SITES=	http://www.mellanox.com/downloads/Drivers/ \
		http://www.mellanox.com/related-docs/prod_software/
DISTFILES=	MLNX_OFED_FREEBSD_V2.1.6.tar.gz \
		packet_pacing_supporting_package_v2.1.6.zip \
		Mellanox_FreeBSD_Release_Notes_v2.1.6.pdf \
		Mellanox_FreeBSD_User_Manual_v2.1.6.pdf
MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Mellanox OFED drivers
WRKSRC=		${WRKDIR}/freebsd-fbsd_ofed_2_1_6

do-build:
	cd ${WRKSRC}/modules/mlx4 && \
		make -m /usr/src/share/mk SYSDIR=/usr/src/sys clean cleandepend

.include <bsd.port.mk>
