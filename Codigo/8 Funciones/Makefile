CC = gcc
CFLAGS = -Wall -Wextra

rotor: rotor_enigma.o rotores.o utils_array.o
	$(CC) $(CFLAGS) -o rotor rotor_enigma.c rotores.c utils_array.c

rotor_enigma.o: rotor_enigma.c
	$(CC) $(CFLAGS) -c rotor_enigma.c

rotores.o: rotores.c rotores.h
	$(CC) $(CFLAGS) -c rotores.c

utils_array.o: utils_array.c utils_array.h
	$(CC) $(CFLAGS) -c utils_array.c
