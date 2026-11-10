// src/core/tls_bridge_stub.cpp — Desktop stub for the Android TLS bridge.
//
// pcp_native's http_client.cpp and matrix_api.cpp reference
// pcp::tlsBridgeAvailable()/tlsBridgeRequest() (the Android JNI
// TLS bridge, tls_bridge.cpp — excluded from desktop builds). The normal
// build never pulls those members, so the references stay dormant; the
// unity build merges them into a member that IS pulled, surfacing the
// undefined references. This stub resolves them: desktop TLS goes through
// libcurl/OpenSSL directly, so the bridge is simply unavailable.
#include <string>

#include <pcp/tls_bridge.hpp>

namespace pcp {

bool tlsBridgeAvailable() {
    return false;
}

std::string tlsBridgeRequest(const std::string& /*host*/, int /*port*/,
                             const std::string& /*request*/, int /*timeoutMs*/) {
    return {};
}

}  // namespace pcp
