PORTNAME=	slepc
PORTVERSION=	3.5.2
PKGNAMESUFFIX=	-openmpi
# DISTNAME=	${PORTNAME}-${PORTVERSION}-p5
CATEGORIES=	wip math
MASTER_SITES=	http://www.grycap.upv.es/slepc/download/distrib/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	large scale sparse eigenvalue problems on parallel computers
WWW=		https://port.home.page/

HAS_CONFIGURE=	yes
USES=		python fortran

CONFIGURE_ENV=	PETSC_ARCH= \
		PETSC_DIR=${LOCALBASE}/petsc-openmpi

CONFIGURE_ARGS+=--prefix=${STAGEDIR}${PREFIX}/slepc-openmpi

CONFLICTS=	mpich2

# USE_LDCONFIG=	${PREFIX}/${PORTNAME}/lib
USE_LDCONFIG=	yes

MAKEFILE=	makefile
MAKE_ENV+=	${CONFIGURE_ENV}
MAKE_JOBS_UNSAFE=	yes

# Is mpicc required?
#CC=		/usr/local/mpi/openmpi/mpicc
#FC=		/usr/local/mpi/openmpi/mpif90

# FIXME: Will this pick up a non-mpi petsc lib?
LIB_DEPENDS+=	libpetsc.so:wip/petsc-openmpi

post-build:
	cd ${WRKSRC} && make SLEPC_DIR=${WRKSRC} PETSC_DIR=${PREFIX}/petsc-openmpi test

.include <bsd.port.mk>
