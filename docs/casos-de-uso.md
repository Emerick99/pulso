# Casos de Uso - Proyecto Pulso

Este documento define los actores y las funcionalidades principales del agente de monitoreo **Pulso**.

## 1. Actores del Sistema
- **Administrador de Sistemas (SysAdmin):** Responsable de configurar el agente y visualizar las métricas consolidadas.
- **Agente Pulso:** Actor automatizado que recolecta y envía datos de rendimiento en segundo plano.

## 2. Casos de Uso Principales

### CU-01: Registro de Métricas de CPU
- **Actor:** Agente Pulso
- **Descripción:** El agente captura el porcentaje de uso de la CPU en intervalos definidos.
- **Flujo Principal:**
  1. El agente inicia el ciclo de captura.
  2. Consulta el estado del procesador mediante llamadas al sistema.
  3. Almacena temporalmente el valor capturado para su envío.

### CU-02: Envío de Alertas por Consumo de RAM
- **Actor:** Administrador de Sistemas
- **Descripción:** Notifica al administrador cuando el uso de memoria excede un umbral crítico.
- **Flujo Principal:**
  1. El sistema detecta que la RAM superó el límite configurado.
  2. Se genera un registro de alerta de alta prioridad.
  3. El administrador recibe la notificación en el panel central.

### CU-03: Visualización de Estado de Red
- **Actor:** Administrador de Sistemas
- **Descripción:** Permite ver el tráfico de entrada y salida de las interfaces de red.
- **Flujo Principal:**
  1. El Administrador selecciona el servidor a monitorear.
  2. El sistema recupera los datos de tráfico de la base de datos.
  3. Se despliega una gráfica con el ancho de banda utilizado.

### CU-04: Configuración de Intervalos de Captura
- **Actor:** Administrador de Sistemas
- **Descripción:** Define la frecuencia con la que el agente recolecta información.
- **Flujo Principal:**
  1. El Administrador accede a la configuración del agente.
  2. Modifica el tiempo de escaneo (polling interval).
  3. El agente reinicia su ciclo con el nuevo parámetro.

### CU-05: Reporte de Disponibilidad (Uptime)
- **Actor:** Agente Pulso
- **Descripción:** Reporta el tiempo que el servidor ha estado operativo sin interrupciones.
- **Flujo Principal:**
  1. El agente calcula el tiempo desde el arranque del sistema.
  2. Envía el reporte de "Uptime" al servidor central.
  3. El sistema actualiza el indicador de disponibilidad.