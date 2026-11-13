
# Work-in-progress FreeBSD ports.

## Installation

Getting started with FreeBSD ports WIP is easy:

```
pkg install auto-admin
auto-ports-wip-checkout
```

## Installing a port

```
wip-reinstall-port portname
```
    
or

```
cd /usr/ports/wip/portname
make install
```

## Maintaining the WIP collection

Run `wip-update` frequently to retrieve the latest commits and
keep wip-tools up-to-date.

The `auto-update-system` script, part of `auto-admin`, will automatically
run `wip-update` if $PORTSDIR/wip is present.  However, it will not reinstall
any WIP ports other than wip-tools.

You may want to always be running the latest WIP version of a port on
all of your FreeBSD installations, either
because it doesn't exist anywhere else, or because you want to thoroughly
run-test it.

To automatically update a WIP port when running `auto-update-system`:

```
auto-mark-install-from-source wip/portname wip newer
```

This way, you won't need to manually run `wip-reinstall-port` on every machine.

## Ports development

### Poudriere

Poudriere is a tool used by FreeBSD ports developers to build-test ports
before committing them to the FreeBSD ports tree.  It performs the build
inside a pristine FreeBSD jail (a sophisticated container system,
much like Docker) with no
ports/packages preinstalled.  This ensures that the port has all dependencies
properly listed and a faulty port won't build successfully because you
just happen to have some of the dependencies installed.  E.g., if you
build-test biology/samtools outside of poudriere, it will succeed as
long as you have biology/htslib installed, whether or not htslib is
listed as a dependency in biology/samtools.  The build will then fail
on other systems where htslib is not installed.  A build could also
succeed or fail depending on the version of a dependency.  Building in
a pristine environment exposes these problems before they impact
FreeBSD end-users.

All new and upgraded ports, and all ports that depend on them, MUST be
poudriere-tested against the latest changes before being committed.
E.g., if you upgrade biology/htslib, you MUST poudriere-test the new
biology/htslib AND all other ports that list biology/htslib as a dependency.

Setting up poudriere is easy using the `port-dev` port:

```
wip-reinstall-port port-dev
port-poudriere-setup
```

Note: You may want to read the poudriere docs first to better understand the
configuration file, which you will edit while running `port-poudriere-setup`.

Once you have a poudriere installation, you can
test a WIP port by running

```
wip-poudriere-test portname jail [jail ...] | all | pattern
```

Examples:

```
# Testing in all jails is the default
wip-poudriere-test htslib

# To test in just one jail (maybe after a failure)
wip-poudriere-test htslib 15-2-amd64

# To test in all amd64 jails, but not aarch64
wip-poudriere-test htslib amd64
```

### Quality assurance

All ports developers should add the following to /etc/make.conf to
enable QA checks when building outside poudriere:

```
DEVELOPER=yes
```

## Miscellaneous

Note that there are committed, quality-controlled versions of many of these
ports available.  If you want the latest stable version, use the usual
FreeBSD ports installation methods:

```
pkg install package-name
```

or

```
cd /usr/ports/category/port && make deinstall clean install
```

## Contributing

-   Contact the owner of the repository and ask to be added as a Github
    collaborator, so you can commit changes made to your local clone.

    Collaborators need to follow two simple rules:

    -   Do not modify someone else's files without their consent.
    -   All ports must have a valid MAINTAINER email.

    Ports in this collection are works-in-progress and may be in any stage
    of development from completely non-functional to ready-to-commit.

    Ports here may not have undergone security review and are provided as-is.
    However, ports found to cause security issues by merely being installed
    will be removed from the collection.

-   Adopt an existing port:

    If there is an existing port that you are interested it, PLEASE PLEASE
    PLEASE inquire about adopting it by contacting the maintainer (see the
    port Makefile for contact info).  There are many ports here and they will
    move beyond WIP faster if more people sign up as maintainers.

-   Commit messages should use the following format whenever possible:

```
portname: Brief description of change
```
e.g.

```
bamtools: Update to 2.5.1, static only
```

This makes it easier to scan the commit history at a glance.
