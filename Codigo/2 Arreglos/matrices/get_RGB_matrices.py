## Script para generar 3 matrices que representen una imagen RGB

from skimage import io
import array

image_name=input("Ingrese la ruta del archivo .png a procesar: ")

# Abrimos la imagen .png
image_rgb=io.imread(image_name)
filas, cols, layers = image_rgb.shape

# Generamos el nombre del archivo de salida. Ahora tendrá el mismo nombre del
# archivo de entrada, pero con extensión .rgb
output_name = image_name.split('.')[0]
output_name += ".rgb"

# Escribimos el archivo de salida
with open(output_name, "wb") as file:
    # Lo primero que contendrá el archivo será una cabecera con la cantidad de
    # filas y columnas escritas como enteros (4 bytes cada uno)
    data = array.array("I", [filas, cols])  
    file.write(data.tobytes())

    # Luego escribimos fila a filas las 3 matrices RGB. Cada celda de las
    # matrices usará un byte
    for l in range(layers):
        for i in range(filas):
            data = array.array("B", image_rgb[i,:,l])  
            file.write(data.tobytes())

print("El archivo de salida tiene nombre", output_name)
print("Nota: Para visualizarlo usar el código leer_archivo_rgb.c")
