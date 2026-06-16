#pragma once

#include <string>

#include "config/config.hpp"

namespace pulso::http {

/**
 * @brief Genera la respuesta JSON para el endpoint GET /config.
 *
 * Serializa los campos no sensibles de @p config en un objeto JSON plano.
 * El campo `interval_ms` se obtiene convirtiendo
 * `config.sampler.intervalo_segundos` a milisegundos (`× 1000`).
 *
 * Ejemplo de respuesta:
 * @code
 * {
 *   "interval_ms": 10000,
 *   "http_port": 8080,
 *   "log_level": "info",
 *   "output_format": "json",
 *   "version": "0.1.0"
 * }
 * @endcode
 *
 * @param config  Configuración activa cargada por `pulso::config::cargar()`.
 * @return        String con el JSON listo para enviar como cuerpo HTTP.
 *
 * @note  La función es pura (sin efectos secundarios) y thread-safe: puede
 *        invocarse desde el callback de httplib sin sincronización adicional.
 *
 * @see pulso::config::Config
 * @see pulso::config::cargar()
 */
std::string handleConfig(const pulso::config::Config& config);

} // namespace pulso::http