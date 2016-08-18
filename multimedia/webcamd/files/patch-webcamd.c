--- webcamd.c.orig	2016-08-18 08:25:51.942580000 -0500
+++ webcamd.c	2016-08-18 08:27:43.550685000 -0500
@@ -582,6 +582,8 @@ find_devices(void)
 
 	pdev = NULL;
 	while ((pdev = libusb20_be_device_foreach(pbe, pdev))) {
+		printf("Found ugen%d.%d\n", libusb20_dev_get_bus_number(pdev),
+			 libusb20_dev_get_address(pdev));
 		if (libusb20_dev_get_mode(pdev) != LIBUSB20_MODE_HOST)
 			continue;
 
