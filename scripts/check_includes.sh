#!/bin/bash

ERRORS_FOUND=0

echo "🔍 Iniciando verificación de #includes circulares..."

echo "-> Comprobando que ningún archivo .cpp incluya a otro .cpp..."
CPP_INCLUDES=$(grep -rIn '#include ".*\.cpp"' src/ 2>/dev/null)

if [ ! -z "$CPP_INCLUDES" ]; then
    echo "❌ ERROR: Se detectaron archivos .cpp incluyendo otros .cpp directamente:"
    echo "$CPP_INCLUDES"
    ERRORS_FOUND=1
fi

echo "-> Comprobando dependencias inversas entre src/core y src/collectors..."
if [ -d "src/core" ]; then
    CORE_CIRCULAR=$(grep -rIn '#include ".*collectors/.*"' src/core/ 2>/dev/null)
    
    if [ ! -z "$CORE_CIRCULAR" ]; then
        echo "❌ ERROR: Inclusión circular detectada. src/core/ no debe incluir src/collectors/:"
        echo "$CORE_CIRCULAR"
        ERRORS_FOUND=1
    fi
fi

if [ $ERRORS_FOUND -eq 0 ]; then
    echo "✅ ÉXITO: No se detectaron patrones de includes circulares. Todo en orden."
    exit 0
else
    echo "❌ FALLO: El repositorio contiene errores de inclusión que rompen la arquitectura."
    exit 1
fi