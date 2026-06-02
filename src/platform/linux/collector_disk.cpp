#include "collector_disk.hpp"
#include <sys/statvfs.h>
#include <ctime>

namespace pulso::platform::linux_platform {

std::string CollectorDisk::nombre() const {
    return "disk";
}

std::vector<pulso::core::Metrica> CollectorDisk::recolectar() {
    struct statvfs buffer{};

    // Llamar al sistema de archivos raíz
    if (statvfs("/", &buffer) != 0) {
        throw pulso::collectors::ErrorRecoleccion(errno);
    }

    // Calcular valores en bytes
    double disk_total = static_cast<double>(buffer.f_blocks) * buffer.f_frsize;
    double disk_free  = static_cast<double>(buffer.f_bavail) * buffer.f_frsize;
    double disk_used  = disk_total - disk_free;

    // Timestamp actual
    std::int64_t ahora = static_cast<std::int64_t>(std::time(nullptr));

    return {
        {"disk.total", disk_total, "bytes", ahora},
        {"disk.used",  disk_used,  "bytes", ahora},
        {"disk.free",  disk_free,  "bytes", ahora},
    };
}

} // namespace pulso::platform::linux_platform