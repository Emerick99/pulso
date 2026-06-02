#pragma once

#include <httplib.h>

#include "../storage/storage.hpp"
#include "../formatters/iformatter.hpp"

namespace pulso::http {

void registrarHistory(
    httplib::Server& servidor,
    const pulso::storage::Storage& storage,
    const pulso::formatters::IFormatter& formatter);

} // namespace pulso::http