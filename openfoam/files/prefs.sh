export WM_COMPILER=Clang
export WM_MPLIB=SYSTEMMPI
export MPI_ROOT=/usr/local
export MPI_ARCH_FLAGS="-DMPICH_SKIP_MPICXX"
export MPI_ARCH_INC="-isystem /usr/local/include"
export MPI_ARCH_LIBS="-L/usr/local/lib -Wl,-rpath,/usr/local/lib -lmpi"
export SCOTCH_TYPE=system
export ZOLTAN_TYPE=none
