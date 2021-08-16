MY_C=gcc

all: prob piramide par_impar desp

prob: probabilidad_rand.c
	@echo "[BLD] Compilando probabilidad_rand.c"
	@$(MY_C) -o prob probabilidad_rand.c

piramide: piramide.c
	@echo "[BLD] Compilando piramide.c"
	@$(MY_C) -o piramide piramide.c

par_impar: condicional_par_impar.c
	@echo "[BLD] Compilando condicional_par_impar.c"
	@$(MY_C) -o par_impar condicional_par_impar.c

desp: menu_desplazamiento.c
	@echo "[BLD] Compilando menu_desplazamiento.c"
	@$(MY_C) -o desp menu_desplazamiento.c


clean:
	rm -f prob piramide par_impar desp
