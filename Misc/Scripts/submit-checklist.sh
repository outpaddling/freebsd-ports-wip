#!/bin/sh -e

##########################################################################
#   Function description:
#       Walk user through port quality checks
#       
#   History:
#   Date        Name        Modification
#   2018-11-19  Charlie &   Begin
##########################################################################

step()
{
    pause
    clear
    # printf "==============================================================\n"
}


##########################################################################
#   Function description:
#       Pause until user presses return
##########################################################################

pause()
{
    local junk
    
    printf "Press return to continue..."
    read junk
}

: ${PORTSDIR:=/usr/ports}
clear
if ! fgrep -q DEVELOPER=yes /etc/make.conf; then
    printf "Consider adding DEVELOPER=yes to /etc/make.conf.\n"
    step
fi

cat << EOM

If maintaining the source, clean up and reroll distfile

EOM

step
cat << EOM

Make sure the port is on the latest upstream version.

EOM

step
cat << EOM

Open the Makefile in an editor in another window.

EOM

step
cat << EOM

PORTNAME should match the upstream dist, including case for p5, cran, and
possibly other special cases, otherwise use all lowercase.

Do not change case for established ports as this would break pkg upgrade.

pkg is case-insensitive for some subcommands, not others.

Ports that install only one binary can use the binary name

EOM

step
cat << EOM

If DISTNAME is not versioned, set DIST_SUBDIR.

EOM

step
cat << EOM

Replace PORTVERSION with DISTVERSION wherever possible
    * Only when changing version, otherwise breaks svn annotate / git blame
    DISTVERSION must match upstream version
    PORTVERSION is derived from DISTVERSION
    Use PORTVERSION directly if DISTVERSION is incompatible with
	FreeBSD version rules
    See porter's handbook "Configuring the Makefile" for details

EOM

step
cat << EOM

Bump PORTREVISION if not changing VERSION
    Otherwise, remove PORTREVISION

EOM

step
cat << EOM

Add PORTEPOCH if downgrading

EOM

step
cat << EOM

Check categories
    Add java, linux, perl5, python, etc. for ports that use them

EOM

step
cat << EOM

Use = instead of += wherever possible
    Use += only for vars commonly set in make.conf, like CFLAGS.

EOM

step
cat << EOM

If updating a port
    portsnap fetch update
    Merge latest changes in committed port into development port

EOM

step
cat << EOM

PKGNAMEPREFIX
    p5-, \${PYTHON_PKGNAMEPREFIX}, etc.

EOM

step
cat << EOM

Check/correct MASTER_SITES
    Use https if possible to protect download stream from hackers
    USE_GITHUB, SF, DISTVERSIONPREFIX, etc. if possible
    DISTVERSIONPREFIX=v preferred over GH_TAGNAME=v\${DISTVERSION}
    No need to manually set WRKSRC if using USE_GITHUB
    Remove MASTER_SITE_SUBDIR if present (deprecated)

EOM

step
cat << EOM

GITHUB
    See USE_GITHUB in guide for versioning between releases, etc.

EOM

step
cat << EOM

Check use of each LOCALBASE and PREFIX
Remove references to wip category
Use \${PORTNAME}, \${DISTVERSION}, etc in body wherever possible

EOM

step
cat << EOM

MAINTAINER=     email

Check comment

EOM

step
cat << EOM

Add LICENSE (after COMMENT)
    Add LICENSE_FILE if included in dist

EOM

step
cat << EOM

Add NO_ARCH=yes if the port is architecture free
    e.g. Only installs scripts or Java byte code

EOM

step
cat << EOM

Replace pre and post with <bsd.port.mk> if possible

EOM

step
cat << EOM

Check developer website for optional dependencies not flagged by portlint
or QA.

EOM

step
cat << EOM

Check versions of all depends
    Be as generic as possible

EOM

step
cat << EOM

Check order of blocks:
    https://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/porting-order.html

EOM

step
cat << EOM

Use USES or USE_* variables wherever possible
    USES before USE_*
	USES=localbase = CFLAGS+=-I\${LOCALBASE}/include, etc.
	See /usr/ports/Mk/Uses
    USE_TEX instead of tex-* depends
    pathfix for pkgconfig lib/libdata
    USE_XORG= instead of LIB_DEPENDS where possible

EOM

step
cat << EOM

Use JAVA_HOME if possible over JAVAJARDIR, etc.

EOM

step
cat << EOM

Python
    Check required version on PYPI or developer site
    https://wiki.freebsd.org/Python/PortsPolicy
    Use autoplist unless there's a good reason not to
    If including a plist, USE_PYTHON+=py3kplist
	%%PYTHON_PYOEXTENSION%%->pyo? (antoine)
    USE_PYTHON=concurrent if multiple flavors install the same files
    Ports that depend on a python module should use USES=python:env or :run
    \${PYNUMPY} for numpy dep.  Check python.mk for other goodies
    Deps should end in @\${PY_FLAVOR}
    Check dep version requirements in setup.py
    Match port attributes to setup.py as closely as possible
	COMMENT to setup.py description
    Add TEST_DEPENDS and do-test target if appropriate
	py-nose or py-pytest
	Examine setup.py and locate a test directory under \${WRKSRC} to
	determine test requirements

EOM

step
cat << EOM

BROKEN_\${OPSYS}_\${REL}_\${ARCH}

EOM

step
cat << EOM

OPTIONS
    options.mk only needed when using the PORT_OPTIONS variable
    All non-options macros before bsd.options.mk
    Add DOCS and EXAMPLES to OPTIONS_DEFINE if needed
	If installing to PORTDOCS or PORTEXAMPLES:
	    OPTIONS_DEFINE= DOCS EXAMPLES
	    PORTDOCS= *
    Remove PORT_OPTIONS:MDOCS checks (automatic with staging)
    Check OPTIONS_DEFINE for standards like MYSQL, etc.

EOM

step
cat << EOM

If installing config files (usually .conf):
    suffix with .sample
	may need to hack install
    plist entry: @sample path/file.conf.sample
    This will automatically install/deinstall .conf file if not different
    from sample

EOM

step
cat << EOM

Remove MAKE_JOBS_UNSAFE if possible
    Verify on build host with many cores.  May work on 4 but not 16.

EOM

step
cat << EOM

WRKSRC_SUBDIR instead of WRKSRC if possible

EOM

step
cat << EOM

Check need for USES vars like pkgconfig, localbase, gettext,
    desktop-file-utils (installs a .desktop file)
    DEVELOPER=yes will help with this during stage-qa

EOM

step
cat << EOM

CMAKE_ARGS format VAR:BOOL=ON, not VAR=1
    CMAKE_ON and CMAKE_OFF where possible

EOM

step
cat << EOM

Use CFLAGS_i386, CFLAGS_amd64, etc.

EOM

step
cat << EOM

Use COPYTREE_* instead of \${CP} -r
    Combine dirs going to the same destination:
	cd \${WRKSRC} && COPYTREE_SHARE "A B C" \${STAGEDIR}...

EOM

step
cat << EOM

If port requires a newer GCC than 4.2.1 (e.g. c++11 or later) and the
USES=compiler:* setting does not already require USE_GCC (as is the case for
compiler:openmp), add the following for 2nd tier platforms that still use
GCC 4.2 for the base:

# Force newer GCC on platforms using GCC 4.2 as base
.if \${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=        yes
.endif

EOM

step
cat << EOM

If building static libs, be sure to compile with -fPIC?

EOM

step
cat << EOM

Shared libs:

Make sure all levels of library versions are in pkg-plist, using ${RLN}
if necessary:

libname.so
libname.so.x
libname.so.x.y
libname.so.x.y.z

If upgrading major version, all ports that link to it
must at least have PORTREVISION bumped to force rebuild.

EOM

step
cat << EOM

Use @ to silence most commands, except commands that contribute to plist

EOM

step
cat << EOM

Carefully check REINPLACE_CMDS and patches
    
    Do reinplaces in pre-configure rather than post-patch to avoid breaking
    make makepatch.
    
    Otherwise should be done at the earliest possible stage, e.g. don't
    patch in post-stage if the same effect can be achieved in pre-configure

EOM

step
cat << EOM

Prefer \$() preferred over \`\` unless \`\` is more readable

EOM

step
cat << EOM

Check all installed scripts for proper shebang line
    (DEVELOPER=yes in /etc/make.conf will enable QA tests to detect this)
    USES=shebangfix
    SHEBANG_FILES=path ...

EOM

step
cat << EOM

Make sure build system respects CC, CXX, FC, LD, 
CFLAGS, CXXFLAGS, FFLAGS, LDFLAGS, etc.

USE_CXXSTD= rather than CXXFLAGS+=--std=

Disable non-portable flags like avx, sse, etc.
If required, add *FLAGS_i386=-msse*

EOM

step
cat << EOM

Respect WITH_DEBUG: install target should not strip binaries unconditionally.
Using \${INSTALL_PROGRAM} will avoid this.

EOM

step
cat << EOM

pkg-plist:

Check for conflicts with other ports.

EOM

step
cat << EOM

@dir entries OK, unlike pkgsrc

EOM

step
cat << EOM

pkgconfig files should be in libdata/pkgconfig
    configure may support --with-pkgconfigdir= even if not advertised
Use EXAMPLESDIR, DOCSDIR, DATADIR where possible
Executables called by bin/* but not meant for users go in prefix/libexec
Optional scripts for users go in DATADIR or EXAMPLESDIR at your discretion
Perl modules (*.pm) \${PREFIX}/\${SITE_PERL_REL}
Java .jar files in \${JAVAJARDIR}

EOM

step
cat << EOM

pkg-descr

Find a good description more than once sentence long
spell-check
space, not tab after WWW
fmt -w 79

EOM

step
cat << EOM

Remove any extraneous files from port framework and add a post-extract \${RM}
for any preexisting .orig files that cause makepatch to generate an extraneous
patch

EOM

step
cat << EOM

Test on all available platforms.  Do the following IN ORDER:

    Add DEVELOPER=yes to /etc/make.conf to enable QA tests

    wip-reinstall-port -u -r ports-mgmt/port-dev
    make clean
    make test
    port-check

    test with NOPORT* (whatever is in pkg-plist)

    If USES=ssl, test with each of the following in /etc/make.conf:
	DEFAULT_VERSIONS+= ssl=libressl
	DEFAULT_VERSIONS+= ssl=openssl
	DEFAULT_VERSIONS+= base

	See /usr/ports/Mk/bsd.default-versions.mk

EOM

step
cat << EOM

Test with poudriere to ensure all depends are installed by the port
    If you've installed Poudriere with port-poudriere-setup:
	wip-poudriere-test category/portname all
    Python flavors are not tested by default:
	Also run testport cat/port@py36 or use poudriere bulk -t

EOM

step
cat << EOM

Check poudriere logs for hints from stage-qa.

EOM

step
cat << EOM

Run make describe on port and entire tree

EOM

step
cat << EOM

If shared lib major version changed, bump PORTREVISION on all dependent ports.

EOM

step
cat << EOM

Generate unified diff for updates, shar file for new ports
    (port-diff or port-shar scripts from ports-mgmt/port-dev)

EOM

step
cat << EOM

Carefully inspect diff or shar

EOM

step
cat << EOM

Follow porter's handbook to submit new port or update.
    https://www.freebsd.org/doc/en/books/porters-handbook/
    https://www.freebsd.org/support/bugreports.html

    Subject line:
    
    [NEW PORT] category/port: COMMENT field
    [MAINTAINER UPDATE] category/port: ?
    [CHANGE REQUEST] category/port: ?
    
    Text:
    
    Description
    
    Justification for PR
    
    portlint: OK (summary output)
    testport: OK (poudriere: {9.3, 10.3, 11.0}, {i386, amd64}, options tested)
    unittest: OK (test suite summary output)

EOM

step
cat << EOM

Make sure the port is copied to it's category directory, not just in wip.

EOM

${PORTSDIR}/wip/Misc/Scripts/post-commit.sh

