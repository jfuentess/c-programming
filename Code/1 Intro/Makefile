MY_C=gcc

all: mandelbrot c2k ec lim ops primer signo tipos

mandelbrot: mandelbrot.c
	@echo "[BLD] Compilando mandelbrot.c"
	@$(MY_C) -o mandelbrot mandelbrot.c

c2k: celsius2Kelvin.c
	@echo "[BLD] Compilando celsius2Kelvin.c"
	@$(MY_C) -o c2k mandelbrot.c

ec: elemento_central.c
	@echo "[BLD] Compilando elemento_central.c"
	@$(MY_C) -o ec mandelbrot.c

lim: limites.c
	@echo "[BLD] Compilando limites.c"
	@$(MY_C) -o lim limites.c

ops: operadores.c
	@echo "[BLD] Compilando operadores.c"
	@$(MY_C) -o ops operadores.c

primer: primer_programa.c
	@echo "[BLD] Compilando primer_programa.c"
	@$(MY_C) -o primer primer_programa.c

signo: signed_unsigned.c
	@echo "[BLD] Compilando signed_unsigned.c"
	@$(MY_C) -o signo signed_unsigned.c

tipos: tipos_de_datos.c
	@echo "[BLD] Compilando tipos_de_datos.c"
	@$(MY_C) -o tipos tipos_de_datos.c

clean:
	rm -f mandelbrot c2k ec lim ops primer signo tipos
