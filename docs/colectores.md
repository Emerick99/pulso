# Guía de Collectors

## 1. Introducción

Los collectors son componentes encargados de obtener métricas del sistema y exponerlas para su procesamiento o visualización. Cada collector tiene una responsabilidad específica y puede ejecutarse de manera independiente del resto.

## 2. Collectors implementados

Actualmente se encuentran implementados los siguientes collectors:

| Collector | Descripción                                                  |
| --------- | ------------------------------------------------------------ |
| CPU       | Obtiene información de uso y carga del procesador.           |
| RAM       | Obtiene métricas de memoria utilizada y disponible.          |
| Disco     | Obtiene información sobre uso y capacidad de almacenamiento. |

## 3. Cómo agregar un nuevo collector

1. Crear un nuevo archivo para el collector dentro del directorio destinado a collectors.
2. Implementar la lógica necesaria para obtener la métrica requerida.
3. Definir una interfaz o estructura compatible con los collectors existentes.
4. Registrar el nuevo collector en el punto de inicialización de la aplicación.
5. Verificar que el collector pueda ejecutarse sin afectar a los demás.
6. Agregar pruebas, si el proyecto las utiliza.
7. Ejecutar la aplicación y comprobar que las métricas del nuevo collector se generen correctamente.
8. Actualizar esta documentación indicando el nombre y propósito del nuevo collector.

## 4. Buenas prácticas

* Mantener una única responsabilidad por collector.
* Evitar dependencias innecesarias entre collectors.
* Documentar claramente el propósito de cada collector.
* Validar errores y excepciones durante la recolección de métricas.
* Mantener nombres descriptivos y consistentes con el resto del proyecto.
