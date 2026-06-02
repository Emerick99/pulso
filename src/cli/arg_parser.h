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
