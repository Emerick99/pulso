#include "arg_parser.h"
//#include "../config/config.h"
#include <iostream>
#include <string>
#include <cstdlib>

void parse_arguments(int argc, char* argv[], Config& config) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        if (arg == "-p" || arg == "--port") {
            // Validar que haya un argumento después del flag
            if (i + 1 >= argc) {
                std::cerr << "Error: El flag " << arg << " requiere un numero de puerto.\n";
                std::exit(1);
            }
            
            std::string port_str = argv[i + 1];
            int port = 0;
            
            try {
                size_t idx;
                port = std::stoi(port_str, &idx);
                
                // Evitar caracteres basura como "9090abc"
                if (idx < port_str.size()) {
                    std::cerr << "Error: Puerto invalido.\n";
                    std::exit(1);
                }
            } catch (...) {
                std::cerr << "Error: Puerto invalido.\n";
                std::exit(1);
            }
            
            // Criterio de aceptación: Validar rango [1, 65535]
            if (port < 1 || port > 65535) {
                std::cerr << "Error: El puerto debe estar en el rango [1, 65535].\n";
                std::exit(1);
            }
            
            // Asignar el puerto validado
            config.http_port = port;
            
            // Avanzar el índice extra para saltar el valor numérico
            ++i;
        }
    }
}
