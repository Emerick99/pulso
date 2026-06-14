#include "uptime_collector.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

UptimeInfo getUptime() {
    // Abrir el archivo virtual del sistema operativo Linux
    std::ifstream file("/proc/uptime");

    // Criterio de aceptación: Lanzar std::runtime_error si no existe o no se puede abrir
    if (!file.is_open()) {
        throw std::runtime_error("Error: No se pudo abrir o no existe el archivo /proc/uptime");
    }

    double uptime_seconds = 0.0;

    // Leer el primer campo de /proc/uptime, que representa el uptime en segundos
    if (!(file >> uptime_seconds)) {
        throw std::runtime_error("Error: El formato de /proc/uptime es invalido");
    }

    const uint64_t total_seconds = static_cast<uint64_t>(uptime_seconds);

    UptimeInfo info{};
    info.total_seconds = total_seconds;

    info.days = static_cast<uint32_t>(total_seconds / 86400);

    uint64_t remaining = total_seconds % 86400;

    info.hours = static_cast<uint32_t>(remaining / 3600);
    remaining %= 3600;

    info.minutes = static_cast<uint32_t>(remaining / 60);
    info.seconds = static_cast<uint32_t>(remaining % 60);

    std::ostringstream formatted;
    formatted << info.days << "d "
              << info.hours << "h "
              << info.minutes << "m "
              << info.seconds << "s";

    info.formatted = formatted.str();

    return info;
}