#    ======================================================================
#       Copyright (C) 2005 Department of Neurology, University of Iowa
#    ======================================================================
#
#	makefile for brainvox package
#

SHELL = /bin/sh

DIRS = libs regions pals voxel trace calc filer brainvox map3 \
	misc surfview docs
ALLDIRS = IrisGL sgiuif voxlib3 $(DIRS) 
EXTRAS = Makefile include brw config config_files

default: 
	@echo ""
	@echo "Brainvox (C) 2005 University of Iowa, Department of Neurology"
	@echo ""
	@echo "Normal usage: make {target}; make all"
	@echo ""
	@echo "Top-level build facility, choose one of the following:"
	@echo ""
	@echo "Options:"
	@echo "    make FreeBSD      : Linux using Intel Fortran compiler"
	@echo "    make linux        : Linux using Intel Fortran compiler"
	@echo "    make linux-g      : Linux debug using Intel compiler"
	@echo "    make linux-absoft : Linux using the Absoft Fortran compiler" 
	@echo "    make osx-absoft   : OSX using the Absoft Fortran compiler" 
	@echo "    make win32-intel  : WIN32 using Intel compiler" 
	@echo "    make win32-intel-g: WIN32 debug using Intel compiler" 
	@echo "    make irix         : Irix using IrisGL"
	@echo "    make irix-g       : Irix debug using IrisGL"
	@echo "    make irix-gl      : Irix using OpenGL"
	@echo "    make irix-gl-g    : Irix debug using OpenGL"
	@echo "    make clean        : clean out all binary objects"
	@echo "    make all          : build all the executables"
	@echo "    make tar          : build a source code tarball"
	@echo "    make bindist      : build a binary release"

FreeBSD linux linux-g irix irix-g irix-gl irix-gl-g linux-absoft osx-absoft win32-absoft win32-intel win32-intel-g:
	rm -f config; cp config_files/$@ config

all: bin ext_libs
	cd IrisGL; $(MAKE) ; $(MAKE) install 
	cd sgiuif; $(MAKE) ; $(MAKE) install
	cd voxlib3; $(MAKE) ; $(MAKE) install
	@list='$(DIRS)'; \
	for i in $$list; do \
		(cd $$i && '$(MAKE)'); \
		(cd $$i && '$(MAKE)' install ); \
	done

bin:
	-mkdir bin

ext_libs:
	-mkdir ext_libs

clean:
	@list='$(ALLDIRS)'; \
	for i in $$list; do \
		(cd $$i && '$(MAKE)' clean ); \
	done
	rm -rf bin ext_libs

bindist:
	make clean
	make all
	cd package; $(MAKE)

tar:
	$(MAKE) clean
	tar cvf brainvox.tar $(ALLDIRS) $(EXTRAS)
	rm -f brainvox.tar.gz brainvox.tgz
	gzip brainvox.tar
	mv brainvox.tar.gz brainvox.tgz


