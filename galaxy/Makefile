# Created by: Jason Bacon
# $FreeBSD$

PORTNAME=	galaxy
PORTVERSION=	2014.05.27
CATEGORIES=	wip biology
# Mirrored snapshots of github repo
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Web-based platform for data intensive biomedical research

#LICENSE=	various

USES=		tar:xz shebangfix
SHEBANG_FILES=	tools/*/*.pl tools/*/*.py tools/*/*.sh

NO_BUILD=	yes

# This is going to be a mess.  Galaxy is meant to be run out of the source
# directory.  Just dumping to libexec for deelopment and testing.
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/galaxy
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${PREFIX}/libexec/galaxy

.include <bsd.port.mk>
