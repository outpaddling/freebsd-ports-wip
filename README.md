
# Work-in-progress FreeBSD ports.

## Installation

Getting started with FreeBSD ports WIP is easy:

```
pkg install auto-admin
auto-ports-wip-checkout
```

## Maintaining the WIP collection

1.   Run `wip-update` frequently to retreive the latest commits.

1.   To automatically update wip ports via auto-update-system:

```
auto-mark-install-from-source wip/portname wip
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

## Ports development

### Poudriere

Setting up poudriere is easy using the port-dev port:

```
wip-reinstall-port port-dev
port-poudriere-setup
```

Note: You may want to read the poudriere docs first to better understand the
config file.

Once you have a poudriere installation, you can
test a port by running

```
wip-poudriere-test portname jail [jail ...] | all | pattern
```

Examples:

```
# Testing on all jails is the default
wip-poudriere-test htslib

# To test on just one jail (maybe after a failure)
wip-poudriere-test htslib 15-2-amd64
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

    Collaborators need to follow one simple rule:

	Do not modify someone else's files without their consent.

    Ports in this collection are works-in-progress and may be in any stage
    of development from completely non-functional to ready-to-commit.

    All ports must have a valid MAINTAINER email.

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
