--- src/secure_input.c.orig	2019-06-10 13:24:43 UTC
+++ src/secure_input.c
@@ -33,7 +33,7 @@ secure_input(char *buf, size_t buf_size)
 	DWORD mode;
 	HANDLE ih;
 #else
-	struct termio ttymode;
+	struct termios ttymode;
 #endif
 	int pos;
 	int ch;
@@ -51,9 +51,11 @@ secure_input(char *buf, size_t buf_size)
 	}
 	SetConsoleMode(ih, mode & ~(ENABLE_ECHO_INPUT ));
 #else
-	ioctl(STDIN_FILENO, TCGETA, &ttymode);
+	// ioctl(STDIN_FILENO, TCGETA, &ttymode);
+	tcgetattr(STDIN_FILENO,&ttymode);
 	ttymode.c_lflag &= ~( ECHO | ECHOE | ECHONL );
-	ioctl(STDIN_FILENO, TCSETAF, &ttymode);
+	// ioctl(STDIN_FILENO, TCSETAF, &ttymode);
+	tcsetattr(STDIN_FILENO, TCSANOW, &ttymode);
 #endif
 
 	pos=0;
@@ -75,7 +77,8 @@ secure_input(char *buf, size_t buf_size)
 	fputc('\n', stdout);
 #else
 	ttymode.c_lflag |= ECHO | ECHOE | ECHONL;
-	ioctl(STDIN_FILENO, TCSETAF, &ttymode);
+	// ioctl(STDIN_FILENO, TCSETAF, &ttymode);
+	tcsetattr(STDIN_FILENO, TCSANOW, &ttymode);
 	fputc('\n', stdout);
 #endif
 }
