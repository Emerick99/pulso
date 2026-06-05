#include "temp_collector.h"

#include <fstream>
#include <string>

namespace collectors {

namespace {

constexpr const char* kThermalZonePath =
    "/sys/class/thermal/thermal_zone0/temp";

constexpr const char* kZoneName = "thermal_zone0";

constexpr float kMilliCelsiusDivisor = 1000.0f;

} // namespace

TempInfo getTempInfo()
{
    std::ifstream file(kThermalZonePath);

    if (!file.is_open()) {
        return TempInfo{
            /* cpu_celsius */ 0.0f,
            /* zona        */ kZoneName,
            /* disponible  */ false
        };
    }

    long raw_millicelsius = 0;
    if (!(file >> raw_millicelsius)) {
        return TempInfo{
            /* cpu_celsius */ 0.0f,
            /* zona        */ kZoneName,
            /* disponible  */ false
        };
    }

    return TempInfo{
        /* cpu_celsius */ static_cast<float>(raw_millicelsius) / kMilliCelsiusDivisor,
        /* zona        */ kZoneName,
        /* disponible  */ true
    };
}

} // namespace collectors