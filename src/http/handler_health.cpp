#include "handler_health.hpp"

#include <chrono>
#include <sstream>
#include <string>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <unistd.h>
#endif

namespace pulso::http {

static const std::string VERSION = "0.1.0";

std::string handleHealth(std::chrono::steady_clock::time_point start_time) {

    // Calcular uptime en segundos
    auto ahora   = std::chrono::steady_clock::now();
    auto uptime  = std::chrono::duration_cast<std::chrono::seconds>(
                       ahora - start_time).count();

    // Obtener hostname
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        std::string(hostname, sizeof(hostname)) = "unknown";
    }

    // Construir JSON
    std::ostringstream json;
    json << "{"
         << "\"status\":\"ok\","
         << "\"uptime_seconds\":" << uptime << ","
         << "\"version\":\"" << VERSION << "\","
         << "\"hostname\":\"" << hostname << "\""
         << "}";

    return json.str();
}

} // namespace pulso::http