#pragma once
#include <string>
#include <vector>
#include "../../collectors/icollector.hpp"
#include "../../collectors/error_recoleccion.hpp"
#include "../../core/types.hpp"

namespace pulso::platform::linux_platform {

/**
 * @brief Collector que mide el espacio de disco en el sistema de archivos raíz.
 *
 * Usa la llamada al sistema statvfs sobre el punto de montaje "/".
 * Devuelve las métricas disk.total, disk.used y disk.free en bytes.
 */
class CollectorDisk : public pulso::collectors::ICollector {
public:
    /// @brief Retorna el nombre identificador de este collector.
    /// @return "disk"
    std::string nombre() const override;

    /// @brief Recolecta las métricas de disco del sistema.
    /// @return Vector con disk.total, disk.used y disk.free en bytes.
    /// @throws pulso::collectors::ErrorRecoleccion si statvfs falla.
    std::vector<pulso::core::Metrica> recolectar() override;
};

} // namespace pulso::platform::linux_platform