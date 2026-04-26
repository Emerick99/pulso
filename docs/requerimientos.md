# Requerimientos del Proyecto

## Requerimientos Funcionales

Un requerimiento funcional define las funciones específicas que un sistema debe realizar para cumplir con las expectativas de los usuarios y del negocio. Son esenciales en proyectos de software porque permiten planificar, desarrollar y evaluar el producto de manera ordenada y verificable.

| ID | Descripción | Prioridad | Estado |
|---|---|---|---|
| RF-001 | El sistema debe monitorear la disponibilidad de servidores y servicios básicos mediante ping y chequeos HTTP.| Alta | Pendiente |
| RF-002 | El sistema debe recolectar y mostrar métricas esenciales de CPU, memoria y red en tiempo real. | Alta | Pendiente
| RF-003 | El sistema debe generar alertas inmediatas cuando un servicio caiga o supere umbrales críticos definidos. | Alta | Pendiente
| RF-004 | El sistema debe ofrecer un panel web simple para visualizar el estado de la infraestructura. | Alta | Pendiente
| RF-005 | El sistema debe almacenar métricas históricas por al menos 24 horas para análisis básico de tendencias. | Media | Pendiente
| RF-006 | El sistema debe permitir la instalación y configuración sencilla de agentes en servidores monitoreados. | Alta | Pendiente
| RF-007 | El sistema debe permitir definir umbrales personalizados para CPU, memoria y red. | Media | Pendiente
| RF-008 | El sistema debe exportar reportes básicos de estado y métricas en formatos estándar (CSV o PDF). | Baja | Pendiente

## Requerimientos No Funcionales (RNF)

Los siguientes requerimientos definen las restricciones técnicas y de calidad bajo las cuales debe operar el agente **Pulso**.

| ID | Categoría | Descripción | Prioridad |
|:---:|---|---|:---:|
| **RNF-001** | **Rendimiento** | El agente debe consumir menos de **10MB de memoria RAM** durante su ejecución continua. | Alta |
| **RNF-002** | **Rendimiento** | El tiempo de respuesta para la captura de métricas de sistema debe ser inferior a **100ms**. | Alta |
| **RNF-003** | **Compatibilidad** | El agente debe ser binario único y compatible con sistemas operativos **Linux (Kernel 5.4+) y Windows 10/11**. | Alta |
| **RNF-004** | **Disponibilidad** | El agente debe ser capaz de reintentar la conexión automáticamente en caso de pérdida de red (Resiliencia). | Media |
| **RNF-005** | **Disponibilidad** | El sistema debe garantizar un tiempo de actividad (Uptime) del 99.9% para no perder métricas críticas. | Media |
| **RNF-006** | **Seguridad** | Los datos transmitidos entre el agente y el servidor deben estar cifrados mediante TLS 1.2 o superior. | Media |
| **RNF-007** | **Escalabilidad** | El agente debe poder ejecutarse en arquitecturas de procesador x86_64 y ARM64. | Baja |

## Requerimientos de Sistema

| ID | Descripción |
|---|---|
| RS-001 | |