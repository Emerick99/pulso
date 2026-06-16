# Seguridad al desplegar el agente Pulso

## Modelo de amenazas
El agente Pulso combina dos características que requieren atención: lee información sensible del sistema desde `/proc` y expone un servidor HTTP para consultas. Los principales riesgos son:
- Acceso no autorizado a métricas que revelan carga, memoria y procesos.
- Abuso del servicio para lanzar ataques de denegación de servicio.
- Exposición de detalles internos que facilitan otros ataques.
- En sistemas mal configurados, lecturas indebidas a través de rutas relativas o controladas.

## Usuario con mínimo privilegio
El agente **no debe ejecutarse como usuario root**. Ejecutarlo con privilegios elevados amplía el impacto de cualquier fallo; un atacante podría ganar acceso completo al sistema. Basta con una cuenta estándar que tenga permiso de lectura sobre los archivos de `/proc` y rutas de disco, sin derechos de escritura en ubicaciones críticas.

## Acceso de red
Por defecto, el servicio HTTP debe **escuchar solo en `localhost` (127.0.0.1)** si no se requiere acceso desde otras máquinas. Si se abre a la red, se reduce el control y se expone a cualquier host que pueda llegar al puerto. En entornos de producción, se recomienda filtrar el tráfico con cortafuegos o usar un proxy inverso.

## Autenticación HTTP
⚠️ **Actualmente el agente NO implementa autenticación HTTP**: cualquier cliente que pueda conectarse al puerto puede leer las métricas. Esto es una advertencia importante: no exponga el servicio a redes públicas sin controles adicionales como VPN, IP permitidas o un proxy con autenticación.

## Capacidades de Linux necesarias
Para leer `/proc` y otros archivos del sistema, el proceso necesita solo capacidades básicas de lectura de archivos y directorios. No requiere capacidades como `CAP_SYS_ADMIN` ni `CAP_NET_ADMIN`. Restringir las capacidades al mínimo necesario reduce el riesgo de escalada.

## Recomendaciones de endurecimiento
1. Ejecutar el agente con un usuario dedicado, sin shell interactivo.
2. Configurar el servidor HTTP para enlazar solo a `127.0.0.1` o `::1`.
3. Usar reglas de cortafuegos para permitir conexiones solo desde orígenes confiables.
4. No abrir el servicio a internet sin una capa previa de seguridad.
5. Revisar periódicamente los permisos de los archivos de configuración.
6. Actualizar regularmente para incorporar mejoras de seguridad.
7. Si se requiere acceso remoto, hacerlo a través de un túnel cifrado.
8.
