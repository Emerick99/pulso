#include "handler_history.hpp"

#include <ctime>
#include <string>

namespace pulso::http {

void registrarHistory(
    httplib::Server& servidor,
    const pulso::storage::Storage& storage,
    const pulso::formatters::IFormatter& formatter)
{
    servidor.Get("/metrics/history",
        [&](const httplib::Request& req, httplib::Response& res)
    {
        try {

            std::time_t ahora = std::time(nullptr);

            int desde = static_cast<int>(ahora - 3600);
            int hasta = 0;
            std::size_t limite = 1000; 

            if (req.has_param("desde")) {
                desde = std::stoi(
                    req.get_param_value("desde")
                );
            }

            if (req.has_param("hasta")) {
                hasta = std::stoi(
                    req.get_param_value("hasta")
                );
            }

            if (req.has_param("limite")) {
                limite = std::stoi(
                    req.get_param_value("limite")
                );
            }

            if (limite < 1 || limite > 10000) {

                res.status = 400;

                res.set_content(
                    R"({"error":"parametros invalidos"})",
                    "application/json"
                );

                return;
            }

            auto snapshots = storage.history(
                desde,
                hasta,
                limite
            );

            auto body = formatter.formatearHistorial(
                snapshots
            );

            res.status = 200;

            res.set_content(
                body,
                "application/json"
            );
        }
        catch (const std::exception&) {

            res.status = 400;

            res.set_content(
                R"({"error":"parametros invalidos"})",
                "application/json"
            );
        }
    });
}

} // namespace pulso::http