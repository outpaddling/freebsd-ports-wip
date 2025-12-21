--- google/cloud/storage/internal/grpc/metrics_exporter_options.cc.orig	2025-12-21 20:39:14 UTC
+++ google/cloud/storage/internal/grpc/metrics_exporter_options.cc
@@ -35,7 +35,7 @@ auto ByName(opentelemetry::sdk::resource::ResourceAttr
             std::string const& name, std::string default_value) {
   auto const l = attributes.find(name);
   if (l == attributes.end()) return default_value;
-  return absl::get<std::string>(l->second);
+  return opentelemetry::nostd::get<std::string>(l->second);
 }
 
 }  // namespace
