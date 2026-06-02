#include <iostream>
#include <exception>

#include <SQLiteCpp/Database.h>

#include "storage/schema.hpp"
#include "collectors/memory/ram_usage.h"

int main() {
    try {
        // Abrir o crear base SQLite
        SQLite::Database db(
            "pulso.db",
            SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE
        );

        // Inicializar esquema
        pulso::storage::inicializarEsquema(db);

        // Obtener métricas RAM
        auto ramInfo = pulso::collectors::memory::getRamUsage();

        // Mostrar resultados
        std::cout << "Pulso iniciado correctamente" << std::endl;

        std::cout << "RAM total: "
                  << ramInfo.total
                  << " bytes" << std::endl;

        std::cout << "RAM usada: "
                  << ramInfo.used
                  << " bytes" << std::endl;

        std::cout << "RAM disponible: "
                  << ramInfo.available
                  << " bytes" << std::endl;

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: "
                  << e.what()
                  << std::endl;

        return 1;
    }
}