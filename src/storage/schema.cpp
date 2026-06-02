#include "schema.hpp"

namespace pulso::storage {
/**
 * @brief Inicializa el esquema de la base de datos SQLite.
 *
 * Crea la tabla `snapshots` con todas las columnas necesarias para
 * almacenar métricas del sistema (CPU, memoria, disco y red), y el
 * índice `idx_snapshots_timestamp` para optimizar las consultas por
 * rango de tiempo. La función es idempotente: puede invocarse múltiples
 * veces sobre la misma base de datos sin producir errores.
 *
 * @param db Referencia a la base de datos SQLite ya abierta.
 * @throws SQLite::Exception si la ejecución del SQL falla por un error
 *         interno de la base de datos.
 */
void inicializarEsquema(SQLite::Database& db) {

    db.exec(
        "CREATE TABLE IF NOT EXISTS snapshots ("
        "    id                 INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    timestamp          INTEGER NOT NULL,"
        "    cpu_usage          REAL,"
        "    cpu_cores          INTEGER,"
        "    memory_total       INTEGER,"
        "    memory_used        INTEGER,"
        "    memory_available   INTEGER,"
        "    disk_total         INTEGER,"
        "    disk_used          INTEGER,"
        "    disk_free          INTEGER,"
        "    network_rx_bytes   INTEGER,"
        "    network_tx_bytes   INTEGER"
        ");"
    );

    db.exec(
        "CREATE INDEX IF NOT EXISTS idx_snapshots_timestamp "
        "ON snapshots(timestamp);"
    );
}

} // namespace pulso::storage