PORTNAME=	radiance
PORTVERSION=	4.1
CATEGORIES=	wip science
MASTER_SITES=	http://radsite.lbl.gov/radiance/dist/
DISTNAME=	rad4R1all

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Highly accurate ray-tracing software system
WWW=		https://radsite.lbl.gov/radiance/

USE_TCL=	yes

WRKSRC=		${WRKDIR}/ray

MAN1=	arch2rad.1 \
	bgraph.1 \
	cnt.1 \
	compamb.1 \
	cv.1 \
	dayfact.1 \
	dctimestep.1 \
	dgraph.1 \
	ev.1 \
	falsecolor.1 \
	fieldcomb.1 \
	findglare.1 \
	gcomp.1 \
	genBSDF.1 \
	genblinds.1 \
	genbox.1 \
	genclock.1 \
	gendaylit.1 \
	genklemsamp.1 \
	genprism.1 \
	genrev.1 \
	gensky.1 \
	genskyvec.1 \
	gensurf.1 \
	genworm.1 \
	getbbox.1 \
	getinfo.1 \
	glare.1 \
	glarendx.1 \
	glrad.1 \
	histo.1 \
	icalc.1 \
	ies2rad.1 \
	igraph.1 \
	lampcolor.1 \
	lookamb.1 \
	macbethcal.1 \
	meta2bmp.1 \
	meta2tga.1 \
	mgf2meta.1 \
	mgf2rad.1 \
	mkillum.1 \
	mksource.1 \
	neaten.1 \
	normpat.1 \
	normtiff.1 \
	obj2mesh.1 \
	obj2rad.1 \
	objline.1 \
	objview.1 \
	oconv.1 \
	pcomb.1 \
	pcompos.1 \
	pcond.1 \
	pdfblur.1 \
	pexpand.1 \
	pextrem.1 \
	pfilt.1 \
	pflip.1 \
	phisto.1 \
	pinterp.1 \
	pkgBSDF.1 \
	plotin.1 \
	pmblur.1 \
	pmdblur.1 \
	protate.1 \
	psign.1 \
	psmeta.1 \
	psort.1 \
	pvalue.1 \
	ra_bmp.1 \
	ra_gif.1 \
	ra_pict.1 \
	ra_ppm.1 \
	ra_ps.1 \
	ra_rgbe.1 \
	ra_t16.1 \
	ra_t8.1 \
	ra_tiff.1 \
	ra_xyze.1 \
	rad.1 \
	rad2mgf.1 \
	raddepend.1 \
	ran2tiff.1 \
	ranimate.1 \
	ranimove.1 \
	rcalc.1 \
	replmarks.1 \
	rhcopy.1 \
	rhinfo.1 \
	rholo.1 \
	rhoptimize.1 \
	rhpict.1 \
	rlam.1 \
	rpict.1 \
	rpiece.1 \
	rsensor.1 \
	rtcontrib.1 \
	rtrace.1 \
	rvu.1 \
	tabfunc.1 \
	tmesh2rad.1 \
	total.1 \
	trad.1 \
	ttyimage.1 \
	vwrays.1 \
	vwright.1 \
	x11meta.1 \
	xform.1 \
	xglaresrc.1 \
	ximage.1 \
	xshowtrace.1
MAN3=	meta.3
MAN5=	metafile.5

post-patch:
	${SED} -e "s|%%WRKSRC%%|${WRKSRC}|g" \
		${FILESDIR}/responses.txt > ${WRKSRC}/responses.txt

do-build:
	@${MKDIR} ${WRKSRC}/install/bin ${WRKSRC}/install/lib/ray
	(cd ${WRKSRC} && ./makeall install < ${WRKSRC}/responses.txt)

# Temporary hack
do-install:
	${CP} -R ${WRKSRC}/install/* ${PREFIX}
	${CP} -R ${WRKSRC}/doc/man/* ${MANPREFIX}/man

.include <bsd.port.mk>
