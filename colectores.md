# Colectores en Pulso

## ¿Qué es un colector?
Un colector es el componente encargado de **obtener, leer y organizar** las métricas de uso de recursos del sistema operativo. Funciona de forma independiente: cada uno se especializa en un tipo de recurso —como procesador, memoria o disco— y extrae los valores necesarios desde archivos o interfaces del sistema.

Su objetivo es entregar información limpia y estructurada al resto de módulos de Pulso, sin necesidad de que otros componentes sepan cómo se lee cada dato. Se diseñan para ser fáciles de mantener y ampliar, de modo que agregar un nuevo tipo de medición no afecta el funcionamiento de los ya existentes.

---

## Colectores implementados

| Nombre          | Archivo de referencia          | Métricas que devuelve |
|-----------------|--------------------------------|------------------------|
| `CpuCollector`  | `src/collectors/cpu.cpp`       | Porcentaje de uso total, tiempo de usuario/sistema, número de núcleos |
| `RamCollector`  | `src/collectors/ram.cpp`       | Memoria total, en uso, libre, disponible y almacenada en búferes |
| `DiskCollector` | `src/collectors/disk.cpp`      | Espacio total, usado, libre, porcentaje de ocupación y operaciones de lectura/escritura |

---

## Cómo agregar un nuevo colector
1. Define la clase heredando de `BaseCollector` en la carpeta `src/collectors/`
2. Implementa el método `collect()` para leer y calcular los valores necesarios
3. Agrega la declaración en el archivo de cabecera correspondiente
4. Registra el nuevo colector en la fábrica o lista de instanciación
5. Compila el proyecto con CMake para verificar que no haya errores
6. Actualiza esta documentación para incluirlo en la tabla anterior

---

## Fuentes de datos en Linux

| Ruta / archivo         | Información que provee |
|------------------------|------------------------|
| `/proc/stat`           | Estadísticas del procesador, tiempos por modo, interrupciones |
| `/proc/meminfo`        | Detalles completos de memoria RAM y áreas reservadas |
| `/proc/net/dev`        | Tráfico de red por interfaz: bytes, paquetes, errores |
| `/proc/diskstats`      | Actividad de discos: lecturas, escrituras, tiempos de servicio |
