# Guía del Contribuidor

Esta guía explica paso a paso cómo realizar tu primer Pull Request (PR) en el proyecto.

## 1. Crear un Fork

Desde GitHub, presiona el botón **Fork** para crear una copia del repositorio en tu cuenta.

## 2. Clonar el repositorio

```bash
git clone https://github.com/TU-USUARIO/NOMBRE-REPOSITORIO.git
cd NOMBRE-REPOSITORIO
```

## 3. Instalar herramientas necesarias

### g++

Verificar instalación:

```bash
g++ --version
```

### CMake

Verificar instalación:

```bash
cmake --version
```

### clang-format

Verificar instalación:

```bash
clang-format --version
```

## 4. Instalar pre-commit

Instalar:

```bash
pip install pre-commit
```

Activar hooks:

```bash
pre-commit install
```

## 5. Crear una rama de trabajo

Actualizar la rama principal:

```bash
git checkout dev
git pull origin dev
```

Crear una rama nueva:

```bash
git checkout -b feat/mi-cambio
```

## 6. Compilar el proyecto

Crear directorio de compilación:

```bash
mkdir build
cd build
```

Generar archivos de compilación:

```bash
cmake ..
```

Compilar:

```bash
cmake --build .
```

## 7. Ejecutar pruebas

Desde el directorio build:

```bash
ctest
```

## 8. Realizar cambios

Modificar los archivos necesarios para implementar la mejora o corrección.

## 9. Verificar formato y compilación

Ejecutar:

```bash
clang-format -i archivo.cpp
```

Verificar nuevamente:

```bash
cmake --build .
ctest
```

## 10. Crear un commit

Agregar cambios:

```bash
git add .
```

Ejemplos de Conventional Commits:

```bash
git commit -m "feat: agregar calculadora de matrices"
```

```bash
git commit -m "fix: corregir validación de entrada"
```

```bash
git commit -m "docs: actualizar guía de instalación"
```

## 11. Enviar cambios a GitHub

```bash
git push origin feat/mi-cambio
```

## 12. Abrir un Pull Request

1. Ir al repositorio en GitHub.
2. Presionar **Compare & Pull Request**.
3. Verificar que el destino sea la rama **dev**.
4. Completar la descripción del PR.
5. Crear el Pull Request.

## Recomendaciones

* Mantén los cambios pequeños y enfocados.
* Sigue el estándar de Conventional Commits.
* Ejecuta las pruebas antes de enviar cambios.
* Revisa que el proyecto compile correctamente.
* Abre los PR contra la rama **dev**, no contra **main**.
