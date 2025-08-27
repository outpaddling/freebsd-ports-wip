--- google/cloud/internal/grpc_opentelemetry.cc.orig	2025-08-27 22:43:32 UTC
+++ google/cloud/internal/grpc_opentelemetry.cc
@@ -25,7 +25,11 @@
 #ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
 #include <opentelemetry/context/propagation/global_propagator.h>
 #include <opentelemetry/context/propagation/text_map_propagator.h>
-#include <opentelemetry/trace/semantic_conventions.h>
+// https://github.com/open-telemetry/opentelemetry-cpp/pull/3475/commits/d569ad4c00552146f9f78c1016732ce4fac5d13a
+// #include <opentelemetry/trace/semantic_conventions.h>
+#include <opentelemetry/semconv/url_attributes.h>
+#include <opentelemetry/semconv/incubating/net_attributes.h>
+#include <opentelemetry/semconv/incubating/rpc_attributes.h>
 #include <opentelemetry/trace/span_metadata.h>
 #include <opentelemetry/trace/span_startoptions.h>
 #endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
@@ -110,17 +114,17 @@ opentelemetry::nostd::shared_ptr<opentelemetry::trace:
 opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> MakeSpanGrpc(
     opentelemetry::nostd::string_view service,
     opentelemetry::nostd::string_view method) {
-  namespace sc = opentelemetry::trace::SemanticConventions;
+  namespace sc = opentelemetry::semconv;
   opentelemetry::trace::StartSpanOptions options;
   options.kind = opentelemetry::trace::SpanKind::kClient;
   return internal::MakeSpan(
       absl::StrCat(absl::string_view{service.data(), service.size()}, "/",
                    absl::string_view{method.data(), method.size()}),
-      {{sc::kRpcSystem, sc::RpcSystemValues::kGrpc},
-       {sc::kRpcService, service},
-       {sc::kRpcMethod, method},
+      {{sc::rpc::kRpcSystem, sc::rpc::RpcSystemValues::kGrpc},
+       {sc::rpc::kRpcService, service},
+       {sc::rpc::kRpcMethod, method},
        {/*sc::kNetworkTransport=*/"network.transport",
-        sc::NetTransportValues::kIpTcp},
+        sc::net::NetTransportValues::kIpTcp},
        {"grpc.version", grpc::Version()}},
       options);
 }
