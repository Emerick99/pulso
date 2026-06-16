#include "formatter_text.hpp"

#include <sstream>
#include <iomanip>
#include <ctime>

namespace pulso::formatters {

std::string FormatterText::formato() const {
    return "text";
}

std::string FormatterText::contentType() const {
    return "text/plain";
}

// Convierte timestamp Unix (segundos) a string ISO 8601
static std::string formatearTimestamp(std::int64_t ts) {
    std::time_t tiempo = static_cast<std::time_t>(ts);
    std::tm* tm = std::gmtime(&tiempo);
    
    std::ostringstream oss;
    oss << std::put_time(tm, "%Y-%m-%dT%H:%M:%SZ");
    return oss.str();
}

// Convierte bytes a GB con 1 decimal
static double bytesAGB(double bytes) {
    return bytes / (1024.0 * 1024.0 * 1024.0);
}

// Convierte bytes a KB/s con 1 decimal
static double bytesAKBs(double bytes) {
    return bytes / 1024.0;
}

std::string FormatterText::formatear(
    const pulso::core::Snapshot& snapshot
) const {
    // Extraer métricas del snapshot
    double cpu_pct = 0.0;
    double ram_usado_gb = 0.0;
    double ram_total_gb = 0.0;
    double disco_usado_gb = 0.0;
    double disco_total_gb = 0.0;
    double net_rx_kbs = 0.0;
    double net_tx_kbs = 0.0;

    for (const auto& metrica : snapshot.metricas) {
        if (metrica.nombre == "cpu.usage" || metrica.nombre == "cpu") {
            cpu_pct = metrica.valor;
        } else if (metrica.nombre == "ram.used" || metrica.nombre == "ram.usado") {
            ram_usado_gb = bytesAGB(metrica.valor);
        } else if (metrica.nombre == "ram.total" || metrica.nombre == "ram.total") {
            ram_total_gb = bytesAGB(metrica.valor);
        } else if (metrica.nombre == "disk.used" || metrica.nombre == "disco.usado") {
            disco_usado_gb = bytesAGB(metrica.valor);
        } else if (metrica.nombre == "disk.total" || metrica.nombre == "disco.total") {
            disco_total_gb = bytesAGB(metrica.valor);
        } else if (metrica.nombre == "network.rx" || metrica.nombre == "net.rx") {
            net_rx_kbs = bytesAKBs(metrica.valor);
        } else if (metrica.nombre == "network.tx" || metrica.nombre == "net.tx") {
            net_tx_kbs = bytesAKBs(metrica.valor);
        }
    }

    // Formatear línea: timestamp | CPU: 45.3% | RAM: 2.1/8.0 GB | Disco: 120/500 GB | Red: 1.2/0.8 KB/s
    std::ostringstream oss;
    oss << formatearTimestamp(snapshot.timestamp)
        << " | CPU: " << std::fixed << std::setprecision(1) << cpu_pct << "%"
        << " | RAM: " << ram_usado_gb << "/" << ram_total_gb << " GB"
        << " | Disco: " << disco_usado_gb << "/" << disco_total_gb << " GB"
        << " | Red: " << net_rx_kbs << "/" << net_tx_kbs << " KB/s";

    return oss.str();
}

std::string FormatterText::formatearHistorial(
    const std::vector<pulso::core::Snapshot>& snapshots
) const {
    std::ostringstream oss;

    for (const auto& snapshot : snapshots) {
        oss << formatear(snapshot) << "\n";
    }

    return oss.str();
}

} // namespace pulso::formatters