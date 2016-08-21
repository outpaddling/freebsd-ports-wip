--- kernel/linux_usb.c.orig	2016-08-20 19:48:21.294817000 -0500
+++ kernel/linux_usb.c	2016-08-20 20:58:32.424592000 -0500
@@ -94,12 +94,15 @@ usb_linux_lookup_id(
 	 * "match_flags" equal to zero, which indicates the end of the
 	 * array:
 	 */
+	fprintf(stderr, "usb_linux_lookup_id(): id->match_flags = %04x\n",
+		id->match_flags);
 	for (; id->match_flags; id++) {
-
+		fprintf(stderr, "Vendor: %x %x\n", id->idVendor, pdd->idVendor);
 		if ((id->match_flags & USB_DEVICE_ID_MATCH_VENDOR) &&
 		    (id->idVendor != pdd->idVendor)) {
 			continue;
 		}
+		fprintf(stderr, "Product: %x %x\n", id->idProduct, pdd->idProduct);
 		if ((id->match_flags & USB_DEVICE_ID_MATCH_PRODUCT) &&
 		    (id->idProduct != pdd->idProduct)) {
 			continue;
@@ -330,27 +333,44 @@ usb_linux_probe_p(int *p_bus, int *p_add
 
 	pdev = NULL;
 	while ((pdev = libusb20_be_device_foreach(pbe, pdev))) {
+		fprintf(stderr, "pdev = %p  pbe = %p\n", pdev, pbe);
 
 		if (libusb20_dev_get_mode(pdev) != LIBUSB20_MODE_HOST)
+		{
+			fprintf(stderr, "!= LIBUSB20_MODE_HOST\n");
 			continue;
+		}
 
 		if (match_bus_addr) {
 			if (libusb20_dev_get_bus_number(pdev) != bus)
+			{
+				fprintf(stderr, "!= bus\n");
 				continue;
+			}
 			if (libusb20_dev_get_address(pdev) != addr)
+			{
+				fprintf(stderr, "!= bus\n");
 				continue;
+			}
 		} else {
 			addr = libusb20_dev_get_address(pdev);
 		}
 		if (libusb20_dev_open(pdev, 4 * 16))
+		{
+			fprintf(stderr, "Non-zero libusb20_dev_open\n");
 			continue;
+		}
 
 		pcfg = libusb20_dev_alloc_config(pdev,
 		    libusb20_dev_get_config_index(pdev));
 		if (pcfg == NULL)
+		{
+			fprintf(stderr, "pcfg == NULL\n");
 			continue;
+		}
 
 		for (i = 0; i != pcfg->num_interface; i++) {
+			fprintf(stderr, "interface = %d\n", i);
 			pifc = pcfg->interface + i;
 
 			/*
@@ -358,12 +378,17 @@ usb_linux_probe_p(int *p_bus, int *p_add
 			 * detection by some V4L drivers.
 			 */
 			if (pifc->desc.bInterfaceClass == USB_CLASS_HUB)
+			{
+				fprintf(stderr, "USB_CLASS_HUB\n");
 				continue;
+			}
 
 			LIST_FOREACH(udrv, &usb_linux_driver_list, linux_driver_list) {
 				id = usb_linux_lookup_id(libusb20_dev_get_device_desc(pdev),
 				    &pifc->desc, udrv->id_table);
 				if (id != NULL) {
+					fprintf(stderr, "id = %p\n", id);
+					fprintf(stderr, "index = %d\n", index);
 					if (!index--)
 						goto found;
 
@@ -372,6 +397,8 @@ usb_linux_probe_p(int *p_bus, int *p_add
 					 * same device
 					 */
 
+					fprintf(stderr, "match_bus_addr = %d\n", id);
+					fprintf(stderr, "id->match_flags = %x\n", id);
 					if ((!match_bus_addr) &&
 					    (!(id->match_flags & USB_DEVICE_ID_MATCH_INT_INFO))) {
 						goto next_dev;
@@ -386,6 +413,7 @@ next_dev:
 		libusb20_dev_close(pdev);
 	}
 	libusb20_be_free(pbe);
+	fprintf(stderr, "-ENXIO\n");
 	return (-ENXIO);
 
 found:
@@ -423,6 +451,7 @@ found:
 	if (p_dev == NULL) {
 		free(pcfg);
 		libusb20_be_free(pbe);
+		fprintf(stderr, "-ENOMEM\n");
 		return (-ENOMEM);
 	}
 	ui = p_dev->bsd_iface_start + i;
@@ -452,6 +481,7 @@ found:
 		}
 		usb_linux_detach_sub(sc);
 		libusb20_be_free(pbe);
+		fprintf(stderr, "-ENXIO2\n");
 		return (-ENXIO);
 	}
 	libusb20_be_dequeue_device(pbe, pdev);
