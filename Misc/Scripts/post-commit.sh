#!/bin/sh -e

: ${PORTSDIR:=/usr/ports}

read -p "category/port? " port_name
pkg_name=$(auto-print-make-variable $port_name PKGBASE)
cat << EOM

After commit:

Remove poudriere logs if present

Switch dependencies in other wip ports from /usr/wip to \${PORTSDIR}

If maintaining source

    tag this version of source and create next one

    update wip ports if present

else

    1)  Send patches through proper channels.
    
    2)  Contact author(s):

    People often assume the only supported platforms are those listed on
    the software's home page and that they should follow the (usually
    inadequate) instructions on the developer's site to install the software.
    
    Example:
    
    "Currently, GEMMA is supported for 64-bit Mac OS X and Linux platforms."
    
    A simple note about using a package manager and a link to the ports site
    can do a lot to raise awareness of the advantages of FreeBSD ports and
    other package managers.

    Send the following message AFTER THE PORT IS COMMITTED and then
    update FreeBSD-citing.
	
============================================================================

FYI:

$pkg_name has been committed to the FreeBSD ports collection.
It might be helpful to users if you could post a message like
the following on your website:

Thanks!

$pkg_name can be installed on FreeBSD via the FreeBSD ports system.

To install via the binary package, simply run:

    pkg install $pkg_name

This will very quickly install a prebuilt package and all run-time
dependencies using only highly-portable optimizations, much like apt, yum,
etc.

FreeBSD ports can just as easily be built and installed from source,
although it will take longer (for the computer, not for you):

    cd /usr/ports/$port_name
    make install

Building from source allows installing to a different prefix, compiling with
native optimizations, and in some cases, building with non-default options
such as different compilers or dependencies.  For example, adding

    CFLAGS+=-march=native

to /etc/make.conf will cause ports built from source to use all native
optimizations known to the compiler for the local CPU, resulting in faster
but less portable binaries.

It also allows building and installing compiled programs with debug flags
enabled so that gdb and lldb can locate issues in the source code:

    cd /usr/ports/category/port
    env WITH_DEBUG=yes make install

To report issues with a FreeBSD port, please submit a PR at:

    https://www.freebsd.org/support/bugreports.html

For more information, visit https://www.freebsd.org/ports/index.html.

============================================================================

EOM
