#include <stdio.h>
#include <string.h>

int main(void) {
    char linea[1024];
    
    while (scanf(" %1023[^\n]", linea) == 1) {
        char *token;
		int num_columna = 0;
		int es_pelicula = 0;

        token = strtok(linea, ",");
        
        while (token != NULL) {
        
			// Solución ítem 1	
			/*
			if (num_columna == 0 || num_columna == 2){
				printf("%s ", token);
			}
            
            token = strtok(NULL, ",");

			num_columna++;

			}
			
			printf("\n");
		} 
			*/	

			// Solución ítem 2
			
			if (num_columna == 1) { 
			        // Ver la columna "type"
			        if (strcmp(token, "Movie") == 0) {
			            es_pelicula = 1;
			        }
			    }
			
		    if (es_pelicula == 1 && (num_columna == 1 || num_columna == 2) ) {
		        // Si es una película, mostrar título
		        printf("%s ", token);
		    }
            
			token = strtok(NULL, ",");
            
            num_columna++;
        }

        if (es_pelicula == 1) {
        	printf("\n");
        }
 	}

    

    return 0;
}


