#pragma once
#include <string>
#include <vector>
#include "../../collectors/icollector.hpp"
#include "../../collectors/error_recoleccion.hpp"
#include "../../core/types.hpp"

namespace pulso::platform::linux_platform {

/**
 * @brief Collector que mide el tráfico de red acumulado desde /proc/net/dev.
 *
 * Lee el pseudo-archivo /proc/net/dev del kernel de Linux, que expone
 * estadísticas de red por interfaz. Suma rx_bytes y tx_bytes de todas
 * las interfaces activas, excluyendo el loopback ("lo") que no representa
 * tráfico real de red.
 *
 * Formato relevante de /proc/net/dev (columnas por interfaz):
 *   face | rx_bytes rx_packets ... | tx_bytes tx_packets ...
 *
 * Las métricas devueltas son:
 *   - network.rx_bytes : total de bytes recibidos (todas las ifaces salvo lo)
 *   - network.tx_bytes : total de bytes transmitidos (todas las ifaces salvo lo)
 *
 * @note Los valores son contadores acumulados desde el arranque del sistema,
 *       no tasas. El consumidor es responsable de calcular deltas si necesita
 *       ancho de banda en tiempo real.
 */
class CollectorNetworkLinux : public pulso::collectors::ICollector {
public:
    /// @brief Retorna el nombre identificador de este collector.
    /// @return "network"
    std::string nombre() const override;

    /// @brief Recolecta las métricas de red del sistema.
    /// @return Vector con network.rx_bytes y network.tx_bytes en bytes.
    /// @throws pulso::collectors::ErrorRecoleccion si /proc/net/dev no puede abrirse
    ///         o si el formato del archivo es inesperado.
    std::vector<pulso::core::Metrica> recolectar() override;
};

} // namespace pulso::platform::linux_platform