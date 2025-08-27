--- google/cloud/internal/rest_opentelemetry.cc.orig	2025-08-27 22:53:18 UTC
+++ google/cloud/internal/rest_opentelemetry.cc
@@ -23,7 +23,10 @@
 #include <opentelemetry/context/propagation/global_propagator.h>
 #include <opentelemetry/context/propagation/text_map_propagator.h>
 #include <opentelemetry/trace/provider.h>
-#include <opentelemetry/trace/semantic_conventions.h>
+// https://github.com/open-telemetry/opentelemetry-cpp/pull/3475/commits/d569ad4c00552146f9f78c1016732ce4fac5d13a
+// #include <opentelemetry/trace/semantic_conventions.h>
+#include <opentelemetry/semconv/url_attributes.h>
+#include <opentelemetry/semconv/incubating/net_attributes.h>
 #include <opentelemetry/trace/span_metadata.h>
 #include <opentelemetry/trace/span_startoptions.h>
 
@@ -71,13 +74,13 @@ opentelemetry::nostd::shared_ptr<opentelemetry::trace:
 
 opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> MakeSpanHttp(
     RestRequest const& request, opentelemetry::nostd::string_view method) {
-  namespace sc = opentelemetry::trace::SemanticConventions;
+  namespace sc = opentelemetry::semconv;
   opentelemetry::trace::StartSpanOptions options;
   options.kind = opentelemetry::trace::SpanKind::kClient;
   auto span = internal::MakeSpan(
       absl::StrCat("HTTP/", absl::string_view{method.data(), method.size()}),
       {{/*sc::kNetworkTransport=*/"network.transport",
-        sc::NetTransportValues::kIpTcp},
+        sc::net::NetTransportValues::kIpTcp},
        {/*sc::kHttpRequestMethod=*/"http.request.method", method},
        {/*sc::kUrlFull=*/"url.full", request.path()}},
       options);
