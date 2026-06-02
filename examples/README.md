# Ejemplos de integración con Prometheus

Este directorio contiene archivos de configuración de ejemplo
para integrar **pulso** con Prometheus.

## Cómo usar

1. Levanta pulso en el puerto 8080.
2. Ejecuta Prometheus apuntando a este archivo:

```bash
docker run -p 9090:9090 \
  -v $(pwd)/examples/prometheus.yml:/etc/prometheus/prometheus.yml \
  prom/prometheus
```

3. Abre Prometheus en `http://localhost:9090`.

## Query PromQL de ejemplo

Para visualizar el uso de CPU:

```promql
pulso_cpu_usage
```