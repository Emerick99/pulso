# 📁 Estructura de la carpeta src

src/
├── collectors/
│   ├── cpu/
│   │   ├── cpu_usage.cpp
│   │   └── cpu_usage.h
│   ├── memory/
│   ├── disk/
│   └── network/
├── core/
├── config/
├── alertas/
├── platform/
│   ├── linux/
│   └── windows/
├── utils/
│   └── logging/
├── main.cpp
└── CMakeLists.txt

---

## 📂 Descripción de Directorios y Archivos Fuente

### 📡 collectors/
Módulos dedicados a la recolección de métricas del sistema. Las subcarpetas representan los diferentes componentes de hardware listos para ser implementados o en desarrollo:

* cpu/: Contiene la lógica activa de recolección de métricas del procesador.
  * cpu_usage.cpp / cpu_usage.h: Implementación y cabecera encargadas de calcular el porcentaje de uso de la CPU.
* memory/: Directorio base para la recolección de métricas de memoria.
  * ram_usage.cpp: Archivo fuente destinado al cálculo del uso de la memoria RAM.
* disk/: Directorio base para métricas de almacenamiento.
* network/: Directorio base para métricas de red.

### 🧠 core/
Directorio base destinado a albergar el núcleo del sistema y el flujo principal de ejecución del monitor.
* schema.cpp: Archivo fuente ubicado en los módulos base del sistema encargado de definir la estructura o esquema de los datos recolectados.
* types.hpp: Definiciones de tipos de datos globales y estructuras comunes utilizadas en todo el proyecto.

### 🖥️ platform/
Espacio reservado para aislar las implementaciones de código dependientes del sistema operativo subyacente.
* linux/: Directorio para llamadas al sistema específicas de distribuciones Linux.
* windows/: Directorio para APIs específicas de entornos Windows.

### ⚙️ config/
Directorio base reservado para los componentes que gestionarán la configuración del sistema en tiempo de ejecución.

### 🚨 alertas/
Directorio base reservado para el futuro módulo encargado de evaluar métricas y disparar notificaciones o alertas del sistema.

### 🧰 utils/
Contiene funciones utilitarias y herramientas de soporte reutilizables para el proyecto.
* logging/: Subsistema de registro diseñado para el control y salida de mensajes del sistema (logs).

---

## 🧩 Principios de Diseño

* Modularidad: Cada componente tiene una única responsabilidad delimitada.
* Extensibilidad: Estructura de directorios preparada para la adición de nuevos recolectores de métricas.
* Portabilidad: Aislamiento planificado para el código dependiente de plataformas específicas.
