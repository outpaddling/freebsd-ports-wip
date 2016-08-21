--- webcamd.c.orig	2014-09-05 17:33:23.000000000 -0500
+++ webcamd.c	2016-08-20 19:44:01.078689000 -0500
@@ -582,6 +582,10 @@ find_devices(void)
 
 	pdev = NULL;
 	while ((pdev = libusb20_be_device_foreach(pbe, pdev))) {
+		fprintf(stderr, "Found ugen%d.%d\n",
+			libusb20_dev_get_bus_number(pdev),
+			libusb20_dev_get_address(pdev));
+		fflush(stderr);
 		if (libusb20_dev_get_mode(pdev) != LIBUSB20_MODE_HOST)
 			continue;
 
@@ -947,8 +951,12 @@ main(int argc, char **argv)
 	linux_late();
 
 	if (vtuner_client == 0) {
-		if (usb_linux_probe_p(&u_unit, &u_addr, &u_index, &d_desc) < 0)
+		int s;
+		if ((s=usb_linux_probe_p(&u_unit, &u_addr, &u_index, &d_desc)) < 0)
+		{
+			fprintf(stderr, "usb_linux_probe_p returned %d\n", s);
 			v4b_errx(EX_USAGE, "Cannot find USB device");
+		}
 	}
 	if (vtuner_server == 0) {
 		if (webcamd_hal_register)
