--- google/cloud/opentelemetry/internal/monitored_resource.cc.orig	2025-09-05 00:42:39 UTC
+++ google/cloud/opentelemetry/internal/monitored_resource.cc
@@ -222,7 +222,7 @@ std::string AsString(
 
 std::string AsString(
     opentelemetry::sdk::common::OwnedAttributeValue const& attribute) {
-  return absl::visit(AsStringVisitor{}, attribute);
+  return opentelemetry::nostd::visit(AsStringVisitor{}, attribute);
 }
 
 MonitoredResource ToMonitoredResource(
