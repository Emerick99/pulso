import statistics

def calcular_media(datos: list[float]) -> float:
    if not datos:
        raise ValueError("La lista no puede estar vacía.")
    return statistics.mean(datos)

def calcular_mediana(datos: list[float]) -> float:
    if not datos:
        raise ValueError("La lista no puede estar vacía.")
    return statistics.median(datos)

def calcular_desviacion_estandar(datos: list[float]) -> float:
    if not datos:
        raise ValueError("La lista no puede estar vacía.")
    return statistics.pstdev(datos)

if __name__ == "__main__":
    datos = [10, 20, 30, 40, 50]
    print("Media:", calcular_media(datos))
    print("Mediana:", calcular_mediana(datos))
    print("Desviación estándar:", calcular_desviacion_estandar(datos))