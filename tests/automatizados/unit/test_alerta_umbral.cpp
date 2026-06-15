#include <gtest/gtest.h>
#include <stdexcept>
#include "alertas/alerta_umbral.hpp"
#include "core/MetricSnapshot.hpp"

using namespace pulso::alertas;
using namespace pulso;

TEST(AlertaUmbralTest, OperadorMayorDisparaCuandoSuperaUmbral)
{
    AlertaUmbral alerta("cpu.usage_pct", 50.0f, '>');
    
    MetricSnapshot snap;
    snap.metrics["cpu.usage_pct"] = 65.5f;
    
    EXPECT_TRUE(alerta.evaluar(snap));
}

TEST(AlertaUmbralTest, OperadorMayorNoDisparaSiEstaPorDebajo)
{
    AlertaUmbral alerta("cpu.usage_pct", 50.0f, '>');
    
    MetricSnapshot snap;
    snap.metrics["cpu.usage_pct"] = 30.0f;
    
    EXPECT_FALSE(alerta.evaluar(snap));
}

TEST(AlertaUmbralTest, OperadorMenorDisparaCuandoEsInferiorAlUmbral)
{
    AlertaUmbral alerta("ram", 20.0f, '<');
    
    MetricSnapshot snap;
    snap.metrics["ram"] = 15.2f;
    
    EXPECT_TRUE(alerta.evaluar(snap));
}

TEST(AlertaUmbralTest, LanzaInvalidArgumentSiElOperadorEsInvalido)
{
    EXPECT_THROW(
        AlertaUmbral("cpu.usage_pct", 50.0f, 'X'),
        std::invalid_argument
    );
}

TEST(AlertaUmbralTest, MensajeRetornaStringNoVacio)
{
    AlertaUmbral alerta("temperatura", 38.0f, '>');
    
    std::string msg = alerta.mensaje();
    EXPECT_FALSE(msg.empty());
}