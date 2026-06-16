# Sistema de almacenamiento en memoria

## Diseño
El módulo `storage.cpp` gestiona el historial de métricas **exclusivamente en memoria principal**, sin escribir en disco. Esto permite acceso muy rápido a los datos, ideal para consultas recientes y cálculos en tiempo real. No hay archivos intermedios ni base de datos externa; todo se mantiene en estructuras dinámicas mientras el agente está activo.

## Capacidad y política de retención
- **Capacidad máxima**: almacena hasta 1 000 registros de métricas.
- **Política de rotación**: cuando se alcanza el límite, se descartan los registros más antiguos para dar espacio a los nuevos (comportamiento tipo cola).

## Métodos disponibles

| Nombre del método         | Parámetros                                  | Valor de retorno                          | Descripción                                                                 |
|--------------------------|---------------------------------------------|-------------------------------------------|-----------------------------------------------------------------------------|
| `agregar_medicion()`     | `tipo, valor, marca_tiempo`                 | `void`                                    | Inserta una nueva medición en el historial.                                |
| `getHistorial()`         | `tipo, desde, hasta`                        | `vector<Medicion>`                        | Devuelve todas las entradas de un tipo entre dos instantes.                 |
| `getPromedio()`          | `tipo, ventana_segundos`                    | `double`                                  | Calcula el promedio sobre una ventana de tiempo deslizante.                 |
| `exportToCSV()`          | `ruta_salida`                               | `bool`                                    | Escribe todo el contenido actual en formato CSV en la ruta indicada.        |
| `limpiar()`              | —                                           | `void`                                    | Borra todo el historial almacenado.                                         |

## Consultas
Se soportan consultas por **tipo de métrica** (CPU, RAM, disco, red) y por **intervalo de tiempo**. Las consultas se resuelven en tiempo lineal respecto al tamaño del historial, lo que sigue siendo muy rápido por el límite de capacidad.

## Exportación
El método `exportToCSV()` genera un archivo con encabezados claros: `tiempo,tipo,valor`. Es la única forma de conservar los datos fuera del proceso mientras se ejecuta.

## Limitaciones
- **Volatilidad**: al reiniciar o detener el agente, **todo el historial se pierde**, ya que no persiste en disco.
- **Tamaño fijo**: no se puede ampliar la capacidad máxima sin modificar el código fuente.
- **Sin índices complejos**: búsquedas muy grandes podrían ser más lentas.
-
