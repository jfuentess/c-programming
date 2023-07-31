#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "variables.h"
#include "funciones.h"

/*-Compilación: gcc main.c -lSDL2 -lSDL2_ttf -lSDL2_mixer -o juego
  -Ejecución  : ./juego */

int main(int argc, const char *argv[]){
    
    srand(time(NULL)); // semilla 

    window_menu = SDL_CreateWindow("MENU", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 450, 570, 0);
    // se crea la ventana del menu en cel centro de tamaño 450 ancho y 570 alto

    if(TTF_Init()==-1){//se comprueba que se inicializo bien la bibloteca ttf
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }

    font= TTF_OpenFont("utils/comic.ttf", 30);//cargamos el tipo de fuente y su tamaño 
    if (!font) {//se comprueba si se cargo bien la fuente 
        printf("TTF_OpenFont: %s\n", TTF_GetError());
    }

    screen_surface_menu = SDL_GetWindowSurface(window_menu);//

    SDL_Color colortexto = {25,25,112};

    texto1 = TTF_RenderText_Solid(font, "Iniciar", colortexto);      //se escribira en pantalla
    texto2 = TTF_RenderText_Solid(font, "Instrucciones", colortexto);//

    inicializar();//funcion declarada en funciones.h

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){ 
    //(frecuencia,formato de salida,canales,cantidad de bytes usados )
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(2);
    }
    //funciones declaras en funciones.h
    musica_juego();
    cargar_imagen();

    //ciclo del menu 
      while (running_menu) {
        while (SDL_PollEvent(&event)) {//consultar eventos 
            if (event.type == SDL_QUIT){// si se presiona la x de la ventana se cierra
                running_menu = 0;
            }else if(event.type==SDL_MOUSEBUTTONDOWN){//eventos del mouse

                if(event.button.button==SDL_BUTTON_LEFT){//evento del boton izquierdo del mouse
                    SDL_GetMouseState(&m_Y,&m_X); //posicion actual del mouse 

                    if ((m_X>=430)&&(m_X<=460)&&(m_Y>=170)&&(m_Y<=260)){ //si se presiona dentro de ese rango de las coordenadas x e y del mouse dara inicio al juego
                        
                        SDL_DestroyWindow(window_menu);//al iniciar el juego se destruye la ventana del menu
                        //funciones declaradas en funciones.h//
                        modo();
                        juego();
                    
                    }else if((m_X>=470)&&(m_X<=500)&&(m_Y>=120)&&(m_Y<=311)){// se abriran las intrucciones 
                       const SDL_MessageBoxButtonData buttons[] = {0, 0, "VAMOS AL JUEGO" };//boton
                         const SDL_MessageBoxColorScheme colorScheme = {//colores
                          {
                            { 0,   57,   230 },//color ventana
                            {   255, 255, 0 },//color del mensaje
                            { 255, 255, 255 },//borde del boton
                            {  18, 135, 219},// fondo del boton
                            { 220,   20, 60 }//boton seleccionado
                          }
                        };

                        const SDL_MessageBoxData messageboxdata = {
                            SDL_MESSAGEBOX_INFORMATION, 
                            NULL, //ventana
                            "Instrucciones", //titulo ventana
                            "P   PAUSA\nM   Patrones al azar\n+   Aumentar velocidad\n-   Disminur velocidad\nR   Reiniciar la partida\n->   Avanza una generacion ", //mensaje
                            SDL_arraysize(buttons), //numero de boton
                            buttons, 
                            &colorScheme //color
                        };
                        int buttonid;
                        if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
                            SDL_Log("error displaying message box");
                            return 1;
                        }
                    }
                }
            }
            SDL_BlitScaled( fondo, NULL, screen_surface_menu, NULL);//se realiza una copia a escala de toda la supeficie fondo a toda la superficie de la pantalla 
            //imprimir texto
            SDL_BlitSurface(texto1, NULL, screen_surface_menu, &destino1);// se realizara una copia de toda la superficie texto a la superficie destino
            SDL_BlitSurface(texto2, NULL, screen_surface_menu, &destino2);
            SDL_UpdateWindowSurface(window_menu);//se copia la superficie de la ventana a la pantalla (dibujar)
        }
    }
      cerrar();

	return 0;
}
