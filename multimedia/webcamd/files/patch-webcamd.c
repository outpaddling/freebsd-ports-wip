--- webcamd.c.orig	2014-09-05 17:33:23.000000000 -0500
+++ webcamd.c	2016-08-18 08:31:59.932269000 -0500
@@ -582,6 +582,10 @@ find_devices(void)
 
 	pdev = NULL;
 	while ((pdev = libusb20_be_device_foreach(pbe, pdev))) {
+		fprintf(stderr, "Found ugen%d.%d\n",
+			libusb20_dev_get_bus_number(pdev),
+			libusb20_dev_get_address(pdev));
+		fflush(stderr);
 		if (libusb20_dev_get_mode(pdev) != LIBUSB20_MODE_HOST)
 			continue;
 
