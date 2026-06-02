#include "collector_memory.hpp"
#include "../../collectors/error_recoleccion.hpp"

#include <fstream>
#include <sstream>
#include <string>

namespace pulso::collectors {

std::string CollectorMemory::nombre() const {
    return "memory";
}

std::vector<pulso::core::Metrica> CollectorMemory::recolectar() {
    std::ifstream file("/proc/meminfo");

    if (!file.is_open()) {
        throw ErrorRecoleccion("No se pudo abrir /proc/meminfo");
    }

    long long memTotalKB = -1;
    long long memAvailableKB = -1;
    long long memFreeKB = -1;

    std::string key;
    long long value;
    std::string unit;

    while (file >> key >> value >> unit) {
        if (key == "MemTotal:") {
            memTotalKB = value;
        } else if (key == "MemAvailable:") {
            memAvailableKB = value;
        } else if (key == "MemFree:") {
            memFreeKB = value;
        }
    }

    if (memTotalKB < 0 || memAvailableKB < 0 || memFreeKB < 0) {
        throw ErrorRecoleccion(
            "No se encontraron las claves requeridas en /proc/meminfo"
        );
    }

    const double memTotalBytes =
        static_cast<double>(memTotalKB) * 1024.0;

    const double memAvailableBytes =
        static_cast<double>(memAvailableKB) * 1024.0;

    const double memUsedBytes =
        static_cast<double>(memTotalKB - memAvailableKB) * 1024.0;

    return {
        pulso::core::Metrica{
            "memory.total",
            memTotalBytes,
            "bytes",
            0
        },
        pulso::core::Metrica{
            "memory.used",
            memUsedBytes,
            "bytes",
            0
        },
        pulso::core::Metrica{
            "memory.available",
            memAvailableBytes,
            "bytes",
            0
        }
    };
}

} // namespace pulso::collectors