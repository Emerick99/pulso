# Plan de Pruebas

## \## 1. Objetivo

## Verificar que el sistema funcione correctamente, asegurando que los módulos de monitoreo y almacenamiento trabajen sin errores.

## \## 2. Alcance

## \* \*\*En alcance\*\*: Módulo de base de datos SQLite, proceso de empaquetado `npm pack` y documentación técnica.

## \* \*\*Fuera de alcance\*\*: Interfaz gráfica de usuario y despliegue en servidores externos.

## \## 3. Tipos de prueba

## \* \[x] \*\*Unitarias\*\*: Para verificar las funciones de la base de datos.

## \* \[x] \*\*Integración\*\*: Para asegurar que el almacenamiento guarda bien las capturas.

## \* \[x] \*\*Funcionales\*\*: Para validar que el paquete final no incluya archivos basura.

## \## 4. Entornos

## 

## | Entorno | SO | Versión |C

## | :--- | :--- | :--- |

## | Local | Windows 11 | Node.js v20+ |

## | CI | Ubuntu latest | GitHub Actions |

## 

## \## 5. Responsables

## 

## | Rol | Responsable |

## | :--- | :--- |

## | Diseño de casos | Carlos Gustavo Choquecallata |

## | Ejecución manual | Carlos Gustavo Choquecallata |

## | Automatización | GitHub Actions |

## 

## \## 6. Criterios de salida

## \* \[x] Cobertura mínima de los módulos principales.

## \* \[x] Cero bugs críticos abiertos en la persistencia de datos.

## \* \[x] Todos los casos de prueba ejecutados satisfactoriamente.

## \## 7. Riesgos

## 

## | Riesgo | Probabilidad | Impacto | Mitigación |

## | :--- | :--- | :--- | :--- |

## | Corrupción de base de datos | Baja | Alto | Usar scripts de inicialización limpios |

