# New ports collection makefile for:	petsc
# Date created:		2012-04-08
# Whom:			Jason Bacon <jwb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	petsc
PORTVERSION=	3.4.1
CATEGORIES=	wip math
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/
PKGNAMESUFFIX=	-openmpi

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Parallel solution of partial differential equations

HAS_CONFIGURE=	yes
USE_PERL5=	yes
USE_PYTHON=	yes
USE_FORTRAN=	yes
USE_LDCONFIG=	${MPI_PREFIX}/lib
CONFIG_SHELL=	${PYTHONBIN}
CONFIGURE_LOG=	configure.log

CONFIGURE_ENV+=	PETSC_ARCH=${OPSYS:L} \
		PETSC_DIR=${WRKSRC} \
		LD_LIBRARY_PATH=${LOCALBASE}/mpi/openmpi/lib:${LOCALBASE}/lib:/usr/lib:/lib:${LD_LIBRARY_PATH}

# make PETSC_DIR=wip/petsc-3.4.1 PETSC_ARCH=freebsd all
# Not necessary to set INSTALL_MAKE_ENV, since generated makefile does it
MAKE_ENV+=	PETSC_DIR=${WRKSRC} \
		PETSC_ARCH=${OPSYS:L}
MAKEFILE=	makefile

MPI_PREFIX=	${PREFIX}/mpi/openmpi

USE_GMAKE=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

CONFIGURE_ARGS+=	\
	--doCleanup=0 \
	--search-dirs=[${LOCALBASE}/mpi/openmpi/bin,${LOCALBASE}/bin,${LOCALBASE}/sbin] \
	--prefix=${MPI_PREFIX} \
	--with-make='make' \
	--with-clanguage='C' \
	--with-fortran=1 \
	--with-errorchecking=1 \
	--with-chud=0 \
	--with-timer=mpi \
	--with-ctable=1 \
	--with-fortran-kernels=0 \
	--with-64-bit-indices=1 \
	--with-precision=double \
	--with-shared-libraries=1 \
	--with-dynamic-loading=0 \
	--with-debugger=gdb \
	--with-proc-filesystem=0 \
	--with-fortran-datatypes=0 \
	--with-fortran-interfaces=1 \
	--with-cmake=${LOCALBASE}/bin/cmake \
	--with-gnu-compilers=0 \
	--with-large-file-io=1 \
	--AR=ar \
	--with-ranlib=ranlib \
	--with-pic=1 \
	--with-debugging=1 \
	--with-blas-lapack-dir=${LOCALBASE} \
	--with-mpi=1 \
	--with-mpi-dir=${LOCALBASE}/mpi/openmpi \
	--with-mpi-compilers=1 \
	--with-f2c-blaslapack=1 \
	--with-x=0 \
	--with-sundials=0 \
	--with-superlu_dist=0 \
	--with-parmetis=0 \
	--with-metis=0 \
	--with-threadcomm=0 \
	--with-zoltan=0 \
	--with-spai=0 \
	--with-p3dlib=0 \
	--with-hwloc=0 \
	--with-tetgen=0 \
	--with-sowing=0 \
	--with-pthreadclasses=0 \
	--with-pthread=1 \
	--with-mumps=0 \
	--with-scalapack=0 \
	--with-ptscotch=0 \
	--with-lgrind=0 \
	--with-pastix=0 \
	--with-numpy=0 \
	--with-pvode=0 \
	--with-cuda=0 \
	--with-cusp=0 \
	--with-thrust=0 \
	--with-sprng=0 \
	--with-afterimage=0 \
	--with-txtpetscgpu=0 \
	--with-openmp=0 \
	--with-glut=0 \
	--with-opengl=0 \
	--with-triangle=0 \
	--with-ccafe=0 \
	--with-generator=0 \
	--with-sieve=0 \
	--with-boost=0 \
	--with-petsc4py=0 \
	--with-pami=0 \
	--with-mathematic=0 \
	--with-clique=0 \
	--with-elemental=0 \
	--with-babel=0 \
	--with-ams=0 \
	--with-java=0 \
	--with-mpe=0 \
	--with-matlab-engine=0 \
	--with-matlab=0 \
	--with-ml=0 \
	--with-hypre=0 \
	--with-yaml=0 \
	--with-oske=0 \
	--with-suggar=0 \
	--with-expat=0 \
	--with-cproto=0 \
	--with-papi=0 \
	--with-ctetgen=0 \
	--with-ffc=0 \
	--with-fiat=0 \
	--with-scientificpython=0 \
	--with-server=0 \
	--with-pcbddc=0 \
	--with-superlu=0 \
	--with-party=0 \
	--with-c2html=0 \
	--with-chaco=0 \
	--with-valgrind=0 \
	--with-parms=0 \
	--with-fftw=0 \
	--with-mpi4py=0 \
	--with-chomod=0 \
	--with-exodusii=0 \
	--with-netcdf=0 \
	--with-hdf5=0 \
	--with-moab=0 \
	--with-umfpack=0 \
	--with-netcdf-cxx=0

CONFIGURE_ARGS+=	| ${TR} '\r' '\n'

# Hate to hack after installing, but the installer is an ad-hoc Python
# script that would require extensive hacking to add a libdata install
# function.
post-install:
	${MKDIR} ${MPI_PREFIX}/libdata
	${MV} ${MPI_PREFIX}/lib/pkgconfig ${MPI_PREFIX}/libdata

.include <bsd.port.mk>
