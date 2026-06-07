#include <atomic>
#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

// httplib
#include <httplib.h>

// Config
#include "config/config.hpp"

// Logger
#include "utils/logging/logger.hpp"

// Storage
#include "storage/schema.hpp"
#include "storage/storage.hpp"

// Collectors
#include "collectors/memory/ram_usage.hpp"
#include "platform/linux/collector_cpu.hpp"
// TODO: CollectorDisk y CollectorNetwork no implementan ICollector aún.
//       Pendiente en issue separado.

// Sampler
#include "sampler/sampler.hpp"

// Formatters
#include "formatters/formatter_json.hpp"

// HTTP handlers
#include "http/handler_health.hpp"
#include "http/handler_history.hpp"
#include "http/handler_metrics.hpp"
#include "http/handler_prometheus.hpp"

// Signal handler
extern std::atomic<bool> isRunning;
void setupSignalHandler();

int main(int argc, char* argv[]) {
    // -------------------------------------------------------------------------
    // 1. Parsear argumentos
    // -------------------------------------------------------------------------
    std::string config_path = "pulso.toml";
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--help") {
            std::cout << "Uso: pulso [--config <ruta>]\n";
            return 0;
        }
        if (arg == "--config" && i + 1 < argc) {
            config_path = argv[++i];
        }
    }

    // -------------------------------------------------------------------------
    // 2. Cargar configuración
    // -------------------------------------------------------------------------
    pulso::config::Config cfg;
    try {
        cfg = pulso::config::cargar(config_path);
    } catch (const pulso::config::ErrorConfig& e) {
        std::cerr << "[pulso] Error al cargar configuración: " << e.what() << "\n";
        return 1;
    }

    // -------------------------------------------------------------------------
    // 3. Configurar logger
    // -------------------------------------------------------------------------
    using pulso::utils::logging::LogLevel;
    using pulso::utils::logging::Logger;

    auto& log = Logger::instancia();
    if      (cfg.nivel_log == "debug") log.setMinLevel(LogLevel::DEBUG);
    else if (cfg.nivel_log == "warn")  log.setMinLevel(LogLevel::WARN);
    else if (cfg.nivel_log == "error") log.setMinLevel(LogLevel::ERROR);
    else                               log.setMinLevel(LogLevel::INFO);

    log.info("pulso v0.1.0 iniciando");
    log.info("Puerto: "        + std::to_string(cfg.servidor.puerto));
    log.info("Base de datos: " + cfg.storage.ruta_db);

    // -------------------------------------------------------------------------
    // 4. Abrir base de datos e inicializar esquema
    // -------------------------------------------------------------------------
    pulso::storage::Storage storage(cfg.storage.ruta_db);
    pulso::storage::inicializarEsquema(storage);

    // -------------------------------------------------------------------------
    // 5. Collectors
    // -------------------------------------------------------------------------
    std::vector<std::shared_ptr<pulso::collectors::ICollector>> collectors;
    collectors.push_back(std::make_shared<pulso::collectors::CollectorCPU>());
    collectors.push_back(
        std::make_shared<pulso::collectors::memory::CollectorMemory>()
    );
    // TODO: agregar CollectorDisk y CollectorNetwork cuando implementen ICollector.

    // -------------------------------------------------------------------------
    // 6. Sampler
    // -------------------------------------------------------------------------
    pulso::sampler::Sampler sampler(
        collectors,
        storage,
        cfg.sampler.intervalo_segundos
    );
    sampler.iniciar();

    // -------------------------------------------------------------------------
    // 7. Signal handler
    // -------------------------------------------------------------------------
    setupSignalHandler();

    // -------------------------------------------------------------------------
    // 8. Servidor HTTP + handlers
    // -------------------------------------------------------------------------
    httplib::Server server;
    pulso::formatters::FormatterJSON formatterJson;

    auto start_time = std::chrono::steady_clock::now();

    // GET /health
    server.Get("/health", [&start_time](
        const httplib::Request&,
        httplib::Response& res)
    {
        res.set_content(
            pulso::http::handleHealth(start_time),
            "application/json"
        );
    });

    // GET /metrics — pendiente hasta que SystemMonitor se adapte al flujo
    // actual (Storage + ICollector). Ver issue #270.
    // pulso::http::HandleMetrics(server, system_monitor);

    // GET /history
    pulso::http::registrarHistory(server, storage, formatterJson);

    // GET /metrics/prometheus
    pulso::http::registrarPrometheus(server, storage);

    // -------------------------------------------------------------------------
    // 9. Arrancar servidor HTTP en thread separado
    // -------------------------------------------------------------------------
    std::thread http_thread([&]() {
        log.info("Servidor HTTP escuchando en " +
                 cfg.servidor.host + ":" +
                 std::to_string(cfg.servidor.puerto));
        server.listen(cfg.servidor.host.c_str(), cfg.servidor.puerto);
    });

    // -------------------------------------------------------------------------
    // 10. Esperar señal de shutdown
    // -------------------------------------------------------------------------
    while (isRunning.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // -------------------------------------------------------------------------
    // 11. Shutdown limpio
    // -------------------------------------------------------------------------
    log.info("Señal recibida — iniciando shutdown...");
    server.stop();
    if (http_thread.joinable()) http_thread.join();
    sampler.detener();
    log.info("pulso detenido correctamente.");

    return 0;
}