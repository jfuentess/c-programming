/*
  
  Código para computar el conjunto de Mandelbrot

  Nota 1: El código disponible en este archivo corresponde a una modificación
  del código disponible en https://rosettacode.org/wiki/Mandelbrot_set#C

  Nota 2: El archivo que se genera corresponde a una imagen en formato PPM. Para
  convertir la imagen a una imagen en formato PNG, ejecute el siguiente comando:
        convert -normalize pic.ppm pic.png

  Compilación:
     - Alternativa 1: gcc -o mandelbrot mandelbrot.c
     - Alternativa 2: make maldelbrot
 */

#include <stdlib.h>
 #include <stdio.h>
 #include <math.h>


void mandelbrot(char *filename, int Xmax, int Ymax, int IterationMax, double
		EscapeRadius) {

  double Cx,Cy;
  const double CxMin=-2.5;
  const double CxMax=1.5;
  const double CyMin=-2.0;
  const double CyMax=2.0;
  double PixelWidth=(CxMax-CxMin)/Xmax;
  double PixelHeight=(CyMax-CyMin)/Ymax;
  
  const int MaxColor=255; 

  // Arreglo de colores para cada pixel
  static unsigned char color[3];

  /* Z=Zx+Zy*i  ;   Z0 = 0 */
  double Zx, Zy;
  double Zx2, Zy2; /* Zx2=Zx*Zx;  Zy2=Zy*Zy  */

  int iter;
  double er2=EscapeRadius*EscapeRadius;
  
  // Creamos el archivo de salida en modo binario. El archivo de salida
  // corresponde a una imagen en formato PPM
  FILE * fp;
  fp= fopen(filename,"wb");

  // Escribimos la cabecera del archivo de salida en ASCII
  fprintf(fp,"P6\n #\n %d\n %d\n %d\n", Xmax, Ymax, MaxColor);
  
  // Computamos la imagen y la escribimos en el archivo de salida
  for(int y=0; y < Ymax; y++) {
    
    Cy = CyMin + y*PixelHeight;
    if (fabs(Cy)< PixelHeight/2) Cy=0.0;

    for(int x=0; x<Xmax; x++) {
      Cx=CxMin + x*PixelWidth;
      // Valos inicial Z=0
      Zx=0.0;
      Zy=0.0;
      Zx2=Zx*Zx;
      Zy2=Zy*Zy;

      for (iter=0; iter < IterationMax && ((Zx2+Zy2)<er2); iter++) {
	Zy=2*Zx*Zy + Cy;
	Zx=Zx2-Zy2 +Cx;
	Zx2=Zx*Zx;
	Zy2=Zy*Zy;
      }
      
      /* Asignamos el color a cada pixel en RGB (24 bit = 3 bytes) */
      if (iter==IterationMax) { /* Interior del conjunto de Mandelbrot */
	color[0]=241; // Red
	color[1]=196; // Green
	color[2]=15;  // Blue                         
      }
      else { /* Exterior del conjunto de Mandelbrot */
	color[0]=46; // Red
	color[1]=64; // Green 
	color[2]=83; // Blue
      }
      
      // Escribimos el pixel en el archivo de salida
      fwrite(color,1,3,fp);
    }
  }
  // Cerramos el archivo de salida
  fclose(fp);
}

int main(int argc, char* argv[]) {

  if (argc != 6) {
    printf("Uso:   %s <ancho> <alto> <cantidad itaraciones> <radio> <imagen salida .ppm>\n", argv[0]);
    printf("Ejemplo: %s 1920 1920 300 3 pic.ppm\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Ancho de la imagen
  const int Xmax = atoi(argv[1]);
  // Alto de la imagen
  const int Ymax = atoi(argv[2]);
  // Cantidad de iteraciones que se iterará cada pixel
  const int IterationMax = atoi(argv[3]);
  // Valor de escape / radio del círculo
  const double EscapeRadius = atof(argv[4]);
  // Nombre del archivo/imagen PPM de salida
  char *filename = argv[5];
  
  mandelbrot(filename, Xmax, Ymax, IterationMax, EscapeRadius);

  return EXIT_SUCCESS;
}
