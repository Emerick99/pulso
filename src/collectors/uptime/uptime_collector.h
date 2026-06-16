#ifndef UPTIME_COLLECTOR_H
#define UPTIME_COLLECTOR_H

#include <cstdint>
#include <string>

/**
 * Estructura que almacena el tiempo de actividad del sistema.
 */
struct UptimeInfo {
    uint64_t total_seconds;
    uint32_t days;
    uint32_t hours;
    uint32_t minutes;
    uint32_t seconds;
    std::string formatted;
};

/**
 * Lee el archivo virtual /proc/uptime y extrae el uptime del sistema.
 *
 * @return Una estructura UptimeInfo con el tiempo total y formateado.
 * @throws std::runtime_error si /proc/uptime no puede abrirse o leerse.
 */
UptimeInfo getUptime();

#endif // UPTIME_COLLECTOR_H