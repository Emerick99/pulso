#pragma once

#include <string>

namespace collectors {

struct TempInfo {
    float       cpu_celsius;
    std::string zona;
    bool        disponible;
};

/**
 * Lee la temperatura de CPU desde /sys/class/thermal/thermal_zone0/temp.
 *
 * El kernel expone el valor como entero en milicélsius; esta función lo
 * divide entre 1000.0f para retornarlo en grados Celsius.
 *
 * Si el archivo no existe o no puede leerse, retorna TempInfo con
 * disponible=false y cpu_celsius=0.0f — nunca lanza excepción.
 */
TempInfo getTempInfo();

} // namespace collectors