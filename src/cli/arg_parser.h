<<<<<<< HEAD
#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <string>

// Definición de la estructura Config con el campo requerido por el issue
struct Config {
    int http_port = 8080;
};

/**
 * Analiza los argumentos de la línea de comandos buscando los flags -p o --port.
 * Si encuentra un puerto válido en el rango [1, 65535], sobreescribe config.http_port.
 * Si el valor es inválido, imprime un error por std::cerr y finaliza con código 1.
 */
void parse_arguments(int argc, char* argv[], Config& config);

#endif // ARG_PARSER_H
=======
#pragma once

#include "../config.hpp"

/**
 * @brief Procesa argumentos de línea de comandos.
 *
 * Permite sobrescribir valores dentro de MonitorConfig.
 *
 * Argumentos soportados:
 * - --interval <ms>
 * - --metrics <lista>
 * - -h | --help
 *
 * @param argc Cantidad de argumentos.
 * @param argv Vector de argumentos.
 * @param config Configuración a modificar.
 *
 * @return true si la ejecución puede continuar.
 * @return false si ocurrió un error o se mostró ayuda.
 */
bool parse_arguments(int argc, char* argv[], MonitorConfig& config);

/**
 * @brief Muestra la ayuda del programa.
 */
void print_help();
>>>>>>> dev
