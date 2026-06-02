#include "formatter_text.hpp"

#include <sstream>
#include <iomanip>
#include <cmath>

namespace pulso::formatters {

std::string FormatterText::formato() const {
    return "text";
}

std::string FormatterText::contentType() const {
    return "text/plain";
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

    for (const auto& metrica : snapshot.metrics) {
        if (metrica.name == "cpu" || metrica.name == "cpu_usage") {
            cpu_pct = metrica.value;
        } else if (metrica.name == "ram_used" || metrica.name == "memory_used") {
            ram_usado_gb = metrica.value;
        } else if (metrica.name == "ram_total" || metrica.name == "memory_total") {
            ram_total_gb = metrica.value;
        } else if (metrica.name == "disk_used") {
            disco_usado_gb = metrica.value;
        } else if (metrica.name == "disk_total") {
            disco_total_gb = metrica.value;
        } else if (metrica.name == "network_rx" || metrica.name == "net_rx") {
            net_rx_kbs = metrica.value;
        } else if (metrica.name == "network_tx" || metrica.name == "net_tx") {
            net_tx_kbs = metrica.value;
        }
    }

    // Formatear línea: timestamp | CPU: 45.3% | RAM: 2.1/8.0 GB | Disco: 120/500 GB | Red: 1.2/0.8 KB/s
    std::ostringstream oss;
    oss << snapshot.timestamp
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