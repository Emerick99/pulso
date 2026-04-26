# Métricas monitoreadas por Pulso

Pulso es un monitor de infraestructura ligero cuyo objetivo es proporcionar
información clave del estado del sistema en tiempo real o con baja latencia.

A continuación se describen las métricas principales que el sistema planea monitorear, junto con su definición, unidad de medida y frecuencia
esperada de muestreo.

## Tabla de métricas

| Métrica        | Descripción                                                                 | Unidad de medida        | Frecuencia de muestreo |
|----------------|-----------------------------------------------------------------------------|--------------------------|------------------------|
| CPU            | Porcentaje de uso del procesador en un intervalo de tiempo determinado.     | Porcentaje (%)           | Cada 1 segundo         |
| RAM            | Cantidad de memoria RAM utilizada y disponible en el sistema.               | Megabytes (MB) / %       | Cada 1 segundo         |
| Disco          | Uso del almacenamiento en disco, incluyendo espacio total, usado y libre.   | Gigabytes (GB) / %       | Cada 5 segundos        |
| Red            | Cantidad de datos enviados y recibidos a través de las interfaces de red.   | Bytes/segundo (B/s)      | Cada 1 segundo         |
| Procesos       | Número total de procesos activos en el sistema.                              | Cantidad (#)             | Cada 2 segundos        |
| Carga del sistema | Promedio de carga del sistema en intervalos de 1, 5 y 15 minutos.        | Valor numérico (load avg)| Cada 5 segundos        |

## Notas adicionales

- Las frecuencias de muestreo pueden ajustarse dependiendo del entorno (desarrollo, producción, dispositivos con recursos limitados, etc.).
- Algunas métricas pueden variar ligeramente en su implementación entre Linux y Windows debido a diferencias del sistema operativo.
- Pulso prioriza un bajo consumo de recursos, por lo que evita frecuencias excesivamente altas innecesarias.
- Las métricas pueden ampliarse en el futuro para incluir:
  - Temperatura del sistema
  - Uso de GPU
  - Latencia de red
  - Estado de servicios específicos

---