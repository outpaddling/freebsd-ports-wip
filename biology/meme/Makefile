# Created by: Charlie %%FULLNAME%% <root@freebsd-10.1.local>
# $FreeBSD$

PORTNAME=	meme
PORTVERSION=	4.11.1
CATEGORIES=	biology
MASTER_SITES=	http://meme-suite.org/meme-software/4.11.1/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Motif-based sequence analysis tools

#USE_GCC=        yes
GNU_CONFIGURE=  yes
USES=		autoreconf
#CONFIGURE_ENV=	HAVE_SYS_WAIT_H=1
#CONFIGURE_ENV=	WIFEXITED=1 AM_CFLAGS="-std=gnu89"
CONFIGURE_ARGS=	--enable-build-libxml2 \
		--enable-build-libxslt

.include <bsd.port.mk>
