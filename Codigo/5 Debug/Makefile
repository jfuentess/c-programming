CC = gcc
CFLAGS = -Wall -Wextra

sum_v1: main.o sum_power2_v1.o
	$(CC) $(CFLAGS) -o sum_v1 main.o sum_power2_v1.o

sum_v2: main.o sum_power2_v2.o
	$(CC) $(CFLAGS) -o sum_v2 main.o sum_power2_v2.o -lm

sum_power2_v1.o: sum_power2_v1.c
	$(CC) $(CFLAGS) -c sum_power2_v1.c

sum_power2_v2.o: sum_power2_v2.c
	$(CC) $(CFLAGS) -c sum_power2_v2.c -lm

clean:
	rm *.o sum_v1 sum_v2
