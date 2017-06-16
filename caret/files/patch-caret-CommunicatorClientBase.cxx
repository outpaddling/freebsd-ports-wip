--- caret/CommunicatorClientBase.cxx.orig	2008-11-12 20:33:21.000000000 -0600
+++ caret/CommunicatorClientBase.cxx	2008-11-12 20:33:46.000000000 -0600
@@ -330,9 +330,9 @@
       case QTcpSocket::UnknownSocketError:
          msg.append(" unknown socket error");
          break;
-      case QTcpSocket::SslHandshakeFailedError:
-         msg.append(" SSL Handshake Failed error");
-         break;
+//      case QTcpSocket::SslHandshakeFailedError:
+//         msg.append(" SSL Handshake Failed error");
+//         break;
       case QTcpSocket::ProxyAuthenticationRequiredError:
          msg.append(" proxy authentication required error");
          break;
