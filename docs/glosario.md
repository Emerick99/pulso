# Glosario

| Término | Definición |
|---|---|
| AlertaUmbral | Tipo de alerta que se activa cuando una métrica supera o cae por debajo de un valor definido. Se utiliza para detectar condiciones anómalas en el sistema. |
| Argumento de lineas de comandos | Valor o instruccion que se pasa al programa al momento de ejecutar desde la terminal |
| Build | Proceso de compilar y enlazar el código fuente de Pulso para generar el ejecutable final |
| CMake | Herramienta multiplataforma para gestionar el proceso de construcción del proyecto. Genera los archivos necesarios para compilar Pulso en distintos sistemas operativos y entornos de desarrollo |
| Compilador | Programa que traduce el código fuente escrito en C++ a código máquina ejecutable |
| Directorio de build | Carpeta separada del código fuente donde CMake genera los archivos de compilación |
| Estado del sistema | Conjunto de métricas que describe la situación actual del hardware y los procesos en ejecución |
| Flag | Opción que se le pasa al compilador para modificar su comportamiento, como activar optimizaciones o seleccionar el estándar de C++ a usar durante la construcción de Pulso|
| FormatterCSV | Componente encargado de exportar o presentar las métricas recolectadas en formato CSV (Comma-Separated Values). |
| FormatterPrometheus | Componente encargado de exponer las métricas en un formato compatible con Prometheus para monitoreo y observabilidad. |
| FormatterText | Componente encargado de mostrar las métricas en formato de texto legible para usuarios. |
| GCC (GNU Compiler Collection) | Compilador de código abierto compatible con C++ y soportado por Pulso en sistemas Linux y macOS|
| Load Average | Métrica que representa la carga promedio del sistema durante un periodo de tiempo. En Pulso se utiliza para evaluar el nivel de actividad y utilización de recursos. |
| Memoria RAM | Memoria de acceso aleatorio del sistema. Pulso monitorea su uso total, la cantidad utilizada y la disponible para informar el estado de los recursos de memoria |
| MSVC (Microsoft Visual C++) | Compilador de C++ de Microsoft, compatible con Pulso en sistemas Windows |
| Núcleo (Core) | Unidad de procesamiento individual dentro de una CPU. Pulso reporta la cantidad de núcleos activos como parte del monitoreo del procesador |
| Red | Infraestructura de comunicación del sistema. Pulso monitorea la velocidad de descarga, la velocidad de subida | 
| Proceso | Instancia de un programa en ejecución dentro del sistema operativo. Pulso informa la cantidad de procesos activos como parte del resumen del estado del sistema |
| Rendimiento | Capacidad del sistema o del programa para ejecutar tareas de manera rápida y eficiente. Pulso está diseñado con un enfoque en alto rendimiento gracias al uso de C++ |
| Sistema Operativo | Software base que administra los recursos del hardware. Pulso es compatible con Windows, Linux y macOS, y adapta su monitoreo según el sistema donde se ejecuta |
| Umbral (Threshold) | Valor de referencia utilizado para comparar métricas y determinar si debe activarse una alerta. |
| Uptime | Tiempo continuo durante el cual el sistema ha permanecido en funcionamiento sin reiniciarse. Pulso puede recolectar esta métrica para monitoreo del estado del sistema. |
