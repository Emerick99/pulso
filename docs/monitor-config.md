# Propuesta: struct MonitorConfig

## ¿Qué se propone?

Se propone la creación de la estructura MonitorConfig para almacenar la configuración del monitoreo del sistema.

## ¿Para qué sirve?

Esta estructura permitirá definir parámetros como el intervalo de lectura y qué métricas del sistema se desean monitorear, facilitando la configuración del comportamiento del sistema de monitoreo.

## Estructura propuesta

Se sugiere que la estructura contenga:

- interval_ms (int): intervalo de tiempo en milisegundos entre lecturas
- cpu (bool): indica si se monitorea el uso de CPU
- ram (bool): indica si se monitorea el uso de memoria RAM
- disk (bool): indica si se monitorea el uso de disco

## Comportamiento esperado

- Contar con un constructor con valores por defecto
- Ubicarse en include/pulso/config.hpp
- Incluir documentación mediante comentarios en el código

## Nota

Esta es solo una propuesta en documentación. No se está implementando código fuente aún.

# Configuración general del monitoreo
[general]
intervalo_recoleccion = 5    # Intervalo entre lecturas en segundos
nivel_registro = "info"     # Nivel de detalle: debug, info, advertencia, error

# Configuración de alertas
[alertas]
habilitado = true            # Activar/desactivar sistema de alertas
intervalo_revision = 60      # Revisar condiciones cada 60 segundos

# Umbrales para CPU
[alertas.cpu]
max = 90                     # Alerta si el uso supera el 90%
lecturas_consecutivas = 3    # Activar después de 3 mediciones seguidas

# Umbrales para memoria RAM
[alertas.ram]
max = 85                     # Alerta si el uso supera el 85%

# Umbrales para disco
[alertas.disco]
max = 90                     # Alerta si el uso supera el 90%
ruta = "/"                    # Ruta del disco a monitorear
