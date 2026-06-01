#include <gtest/gtest.h>
#include "collectors/disk/disk_usage.cpp"

namespace {

// Tolerancia de 1 MB para la verificación de consistencia
constexpr uint64_t TOLERANCIA = 1048576;

/**
 * @brief Verifica que el espacio total del disco es mayor a cero.
 */
TEST(DiskUsageTest, TotalEsMayorACero) {
    DiskUsage uso = getDiskUsage();
    ASSERT_GT(uso.total, static_cast<uint64_t>(0));
}

/**
 * @brief Verifica que el espacio libre no es negativo.
 */
TEST(DiskUsageTest, LibreNoEsNegativo) {
    DiskUsage uso = getDiskUsage();
    ASSERT_GE(uso.libre, static_cast<uint64_t>(0));
}

/**
 * @brief Verifica que el espacio usado no es negativo.
 */
TEST(DiskUsageTest, UsadoNoEsNegativo) {
    DiskUsage uso = getDiskUsage();
    ASSERT_GE(uso.usado, static_cast<uint64_t>(0));
}

/**
 * @brief Verifica que usado + libre no supera total más la tolerancia de 1 MB.
 */
TEST(DiskUsageTest, ConsistenciaUsadoMasLibre) {
    DiskUsage uso = getDiskUsage();
    ASSERT_LE(uso.usado + uso.libre, uso.total + TOLERANCIA);
}

} // namespace