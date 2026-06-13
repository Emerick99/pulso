# Guía de Despliegue en Producción con systemd

## Introducción

Pulso puede ejecutarse como un servicio administrado por systemd, permitiendo que el sistema se inicie automáticamente al arrancar el servidor, se reinicie ante fallos y pueda ser monitoreado mediante las herramientas estándar de Linux.

## 1. Compilar para producción

Antes del despliegue se recomienda compilar el proyecto en modo Release.

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

La compilación generará un binario optimizado para entornos productivos.

## 2. Crear usuario del sistema

Por razones de seguridad, Pulso no debe ejecutarse como root.

Crear un usuario dedicado:

```bash
sudo useradd --system --no-create-home --shell /usr/sbin/nologin pulso
```

Verificar:

```bash
id pulso
```

## 3. Crear directorios necesarios

Crear un directorio para la aplicación:

```bash
sudo mkdir -p /opt/pulso
sudo chown pulso:pulso /opt/pulso
```

Copiar el binario compilado:

```bash
sudo cp build/pulso /opt/pulso/
sudo chown pulso:pulso /opt/pulso/pulso
```

## 4. Crear el archivo de unidad systemd

Crear el archivo:

```bash
sudo nano /etc/systemd/system/pulso.service
```

Contenido completo:

```ini
[Unit]
Description=Pulso Monitoring Service
After=network.target

[Service]
Type=simple
User=pulso
Group=pulso
WorkingDirectory=/opt/pulso
ExecStart=/opt/pulso/pulso
Restart=always
RestartSec=5

[Install]
WantedBy=multi-user.target
```

Guardar el archivo y salir.

## 5. Instalar el servicio

Recargar systemd:

```bash
sudo systemctl daemon-reload
```

Habilitar el servicio para iniciar automáticamente:

```bash
sudo systemctl enable pulso
```

Iniciar el servicio:

```bash
sudo systemctl start pulso
```

## 6. Verificar el estado

Consultar el estado actual:

```bash
sudo systemctl status pulso
```

Consultar registros:

```bash
sudo journalctl -u pulso
```

Seguir los registros en tiempo real:

```bash
sudo journalctl -u pulso -f
```

## 7. Actualizar el binario

Cuando exista una nueva versión:

Detener el servicio:

```bash
sudo systemctl stop pulso
```

Reemplazar el binario:

```bash
sudo cp build/pulso /opt/pulso/pulso
```

Iniciar nuevamente:

```bash
sudo systemctl start pulso
```

Verificar:

```bash
sudo systemctl status pulso
```

## 8. Seguridad

Se recomienda ejecutar Pulso utilizando un usuario sin privilegios para minimizar riesgos de seguridad.

Buenas prácticas:

* No ejecutar el servicio como root.
* Utilizar un usuario dedicado (`pulso`).
* Limitar permisos de escritura únicamente a los directorios necesarios.
* Mantener actualizado el sistema operativo.
* Revisar periódicamente los registros mediante `journalctl`.

Si el servicio requiere acceso especial a recursos del sistema, deben otorgarse únicamente las capacidades necesarias y evitar privilegios excesivos.

## Conclusión

El uso de systemd permite administrar Pulso como un servicio profesional de Linux, facilitando el arranque automático, la recuperación ante fallos, el monitoreo y las actualizaciones controladas en entornos de producción.
