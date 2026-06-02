#pragma once

#include "../../collectors/icollector.hpp"
#include <vector>
#include <string>

namespace pulso::collectors {

class CollectorMemory : public ICollector {
public:
    std::string nombre() const override;
    std::vector<pulso::core::Metrica> recolectar() override;
};

} // namespace pulso::collectors