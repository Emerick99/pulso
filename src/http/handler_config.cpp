#include "handler_config.hpp"

#include <sstream>
#include <string>

namespace pulso::http {

/// Versión del agente Pulso, alineada con handler_health.cpp.
static const std::string VERSION = "0.1.0";

/**
 * @brief Escapa caracteres especiales JSON en un string.
 *
 * Reemplaza `"` → `\"` y `\` → `\\` para evitar JSON malformado si algún
 * campo de configuración contiene esos caracteres.
 *
 * @param s  String original.
 * @return   String con caracteres especiales escapados.
 */
static std::string jsonEscape(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    for (const char c : s) {
        if      (c == '"')  out += "\\\"";
        else if (c == '\\') out += "\\\\";
        else                out += c;
    }
    return out;
}

/**
 * @brief Serializa los campos no sensibles de config en JSON.
 *
 * Convierte `sampler.intervalo_segundos` a milisegundos multiplicando por
 * 1000, ya que la issue especifica el campo como `interval_ms`.
 *
 * @param config  Configuración activa de la instancia Pulso.
 * @return        String JSON con los cinco campos públicos.
 */
std::string handleConfig(const pulso::config::Config& config) {
    const int interval_ms = config.sampler.intervalo_segundos * 1000;

    std::ostringstream json;
    json << "{"
         << "\"interval_ms\":"   << interval_ms                            << ","
         << "\"http_port\":"     << config.servidor.puerto                 << ","
         << "\"log_level\":\""   << jsonEscape(config.nivel_log)   << "\","
         << "\"output_format\":\"" << jsonEscape(config.output_format) << "\","
         << "\"version\":\""     << VERSION                               << "\""
         << "}";

    return json.str();
}

} // namespace pulso::http