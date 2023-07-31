#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "variables.h"

void tipo_patron(int **matriz, int f, int c);
void color_activa();
void musica_juego();
void agregar_patron(int **matriz);
int **crearMatriz_original(int f, int c);
int **crearMatriz_auxiliar(int f, int c);
void liberarMatriz_original(int **matrix, int f, int c);
void liberarMatriz_auxiliar(int **mat, int f, int c);


int inicializar(){//inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        fprintf(stderr, "Error al inicializar SDL\n");
        return 1;
    }
    if (window_menu == NULL){
        printf("Error al crear la ventana\n");
        return 1;
    }
}

bool cargar_imagen(){
    bool run = true;
    fondo = SDL_LoadBMP("img/fondo.bmp");//cargar la imagen
    if (fondo == NULL){ //revisa si se cargo la imagen 
        printf("Unable to load image %s! SDL Error: %s\n", "fondo.bmp", SDL_GetError());
        run = false;
    }
}

void cerrar(){

    TTF_CloseFont(font);//liberala la memoria utilizada por la fuente 
    //libera la superficie texto 1 y 2
    SDL_FreeSurface(texto1);
    SDL_FreeSurface(texto2);
    SDL_FreeSurface(screen_surface_menu);//libera la superficie de pantalla del menu
    SDL_Quit();//limpia todos los subsistemas inicializados de SDL
    TTF_Quit();//apaga y limpia API de fuentes 
    Mix_Quit();//apagar todo lo relacionado a SDL_mixer
}

int juego(){
    int **matriz = crearMatriz_original(28, 40);
    int **arrAux = crearMatriz_auxiliar(28, 40);

    Mix_PlayMusic(musica, -1);//reproducir la musica 

    window = SDL_CreateWindow("JUEGO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 560, SDL_WINDOW_SHOWN);
    screen_surface = SDL_GetWindowSurface(window);

    tipo_patron(matriz, 28, 40);//patron en que se inicia la partida

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    while (running){//ciclo del juego
        musica_juego();//funcion para la musica 

        while (SDL_PollEvent(&evento)){//consultar eventos
            if (evento.type == SDL_QUIT)
                running = 0;
            if (evento.type == SDL_KEYDOWN){//se produce cuando se presiona una tecla

                SDL_Keycode key = evento.key.keysym.sym;//le da significado a la pulsacion de tecla

                fflush(stdin);//vacia el bufer de salida 

                if (key == SDLK_p){
                    pausa = !pausa;//al presionar la p se pausa y con la misma p se reanuda el juego
                }else if (key == SDLK_m){
                    agregar_patron(matriz);
                }else if (key == SDLK_KP_PLUS){ //+ aumentar velocidad

                    if (velocidad == 50){
                        velocidad = 200;
                    }
                    velocidad = velocidad - 50;
                }else if (key == SDLK_KP_MINUS){ //- disminuir velocidad

                    if (velocidad == 500){
                        velocidad = 200;
                    }
                    velocidad = velocidad + 50;

                }else if (key == SDLK_RIGHT){//cuando esta en pausa si se presiona avanza una generacion 
                    if (bandera == 1){
                        bandera = 0;
                    }else{
                        bandera = 1;
                    }
                }else if (key == SDLK_r){//boton de reinicio
                    contvacio++;
                    tipo_patron(matriz, 28, 40);//
                }
            }

            if (evento.type == SDL_MOUSEBUTTONDOWN){//evento del mouse
                if (evento.button.button == SDL_BUTTON_LEFT){//si se preciona el boton izquierdo

                    SDL_GetMouseState(&mouseX, &mouseY);//posicion actual del mouse
                    int i = mouseY / 20;
                    int j = mouseX / 20;

                    if (matriz[i][j] == 0){//si se hace click en una celda inactiva se activara 
                        matriz[i][j] = 1;
                    }else{
                        matriz[i][j] = 0;
                    }
                }
            }
        }

        for (int k = 0; k < 28; k++){ // Compia de la matriz original
            for (int l = 0; l < 40; l++){
                arrAux[k][l] = matriz[k][l];
            }
        }

        for (int i = 0; i < 28; ++i){
            for (int j = 0; j < 40; ++j){

                SDL_Rect r = {20 * j, 20 * i, 20, 20};//el tamaño de las celdas es de 20*20
                
                if (arrAux[i][j] == ACTIVA){//si la celda esta activa
            
                    if(pausa!=1){
                        color_activa();
                        SDL_RenderFillRect(renderer, &r);
                    }else{
                       SDL_SetRenderDrawColor(renderer, 245, 40, 145, 0.8);//cuando esta en pausa las celulas pintadas se veran de color rosado
                       SDL_RenderFillRect(renderer, &r);
                    }
                }else{
                    SDL_SetRenderDrawColor(renderer, 0, 146, 214, 0.2);//color celdas inactivas
                    SDL_RenderFillRect(renderer, &r);
                }

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1); // borde
                SDL_RenderDrawRect(renderer, &r);
            }
        }

        SDL_RenderPresent(renderer);

        if (pausa && bandera != 1){
            continue;

        }else{
            bandera = 0;
        }

        for (int k = 0; k < 28; k++){
            for (int l = 0; l < 40; l++){

                //a y b son variables auxiliares que se usan cuando se quiere sumar alguna celda que este fuera de la matriz
                int a = (k - 1) % 28;
                if (a < 0){//para darle el efecto de continuidad en infinita al programa 
                    a = 27;
                }
                int b = (l - 1) % 40;
                if (b < 0){
                    b = 39;
                }
                //sumacelvecinos se encarga de revisar las celdas vecinas a la celda que esta siendo estudiada

                sumacelvecinos = matriz[(a) % 28][(b) % 40] + matriz[k % 28][(b) % 40] + matriz[(k + 1) % 28][(b) % 40] + matriz[(a) % 28][l % 40] + matriz[(k + 1) % 28][l % 40] + matriz[(a) % 28][(l + 1) % 40] + matriz[k % 28][(l + 1) % 40] + matriz[(k + 1) % 28][(l + 1) % 40];

                // Reglas 1: Una celula muerta con exactamente 3 vecinas vivas "revive".
                if (matriz[k][l] == 0 && sumacelvecinos == 3){
                    arrAux[k][l] = 1;
                }
                // Regla 2: Una celula viva con menos de 2 o mas de 3 vecinas vivas "muere".
                else if (matriz[k][l] == 1 && (sumacelvecinos < 2 || sumacelvecinos > 3)){
                    arrAux[k][l] = 0;
                }
            }
        }


        for (int k = 0; k < 28; k++){ // Compia de la matriz original
            for (int l = 0; l < 40; l++){
                matriz[k][l] = arrAux[k][l];
            }
        }
        SDL_Delay(velocidad);//espera una cantidad en milisegundos
    }
    liberarMatriz_original(matriz, 28, 40);
    liberarMatriz_auxiliar(arrAux, 28, 40);

    SDL_FreeSurface(screen_surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}

void modo(){// ventana para elegir el modo de la partida

    const SDL_MessageBoxButtonData buttons[] = {
        {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "vacio"}, /* .flags, .buttonid, .text */
        {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "aleatorio"},
        {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 2, "nave"}, 
    };                                                       

    const SDL_MessageBoxColorScheme colorScheme = {
        {
            {0, 57, 230},    // color ventana
            {255, 255, 0},   // color del mensaje
            {255, 255, 255}, // borde del boton
            {18, 135, 219},  // fondo del boton
            {220, 20, 60}    // boton seleccionado
        }
    };

    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION,            /* .flags */
        NULL,                                  /* .window */
        "MODO",                                /* .title */
        "Eliga como quiere iniciar el juego:", /* .message */
        SDL_arraysize(buttons),                /* .numbuttons */
        buttons,                               /* .buttons */
        &colorScheme
    };

    int buttonid;

    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0){
        SDL_Log("ERROR MENSAJE CON BOTONES");
    }

    if (buttons[buttonid].text == "vacio"){ // si se preciona el boton vacio el contado correspondiente aumenta en 1
        contvacio++;
    }else if (buttons[buttonid].text == "aleatorio"){ //
        contaleatorio++;
    }else if (buttons[buttonid].text == "nave"){ //
        contnave++;
    }
}

void tipo_patron(int **matriz, int f, int c){//patron en que se inicia la partida

    if (contvacio >= 1){// modo vacio todas las celdas  estan inactivas
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < c; ++j){
                matriz[i][j] = INACTIVA;
            }
        }
    }

    if (contaleatorio >= 1){//modo aleatorio pueden haber celdas inactivas o activas
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < c; ++j){
                matriz[i][j] = rand() % 2;
            }
        }
    }

    if (contnave >= 1){// se crea una nave en la pantalla 
        for (int i = 0; i < f; ++i){
            for (int j = 0; j < c; ++j){
                matriz[i][j] = INACTIVA;
                matriz[4][8] = ACTIVA;
                matriz[5][9] = ACTIVA;
                matriz[6][7] = ACTIVA;
                matriz[6][8] = ACTIVA;
                matriz[6][9] = ACTIVA;
            }
        }
    }
}

void color_activa(){ // se le asigna un color aleatorio a una casilla activa

    color_celula = 1 + rand() % 8;

    switch (color_celula){
    case 1: // rojo
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 1);
        break;
    case 2: // naranjo
        SDL_SetRenderDrawColor(renderer, 255, 140, 0, 1);
        break;
    case 3: // amarillo
        SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255);
        break;
    case 4: // verde
        SDL_SetRenderDrawColor(renderer, 0, 177, 16, 1);
        break;
    case 5: // azul
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 1);
        break;
    case 6: // morado
        SDL_SetRenderDrawColor(renderer, 141, 0, 200, 1);
        break;
    default: // rosado
        SDL_SetRenderDrawColor(renderer, 255, 0, 182, 1);
        break;
    }
}

void musica_juego(){

    flags = MIX_INIT_OGG | MIX_INIT_MOD | MIX_INIT_MP3;

    initted = Mix_Init(flags);
    if (initted & flags != flags){
        printf("Mix_Init: Failed to init required ogg and mod support!\n");
        printf("Mix_Init: %s\n", Mix_GetError());
    }
    musica = Mix_LoadMUS("audio/jogo.mp3");// se carga el archivo de musica

    if (musica == NULL){// se revisa si se cargo bien la musica 
        printf("NO se pudo leer el archivo jogo.mp3\n");
    }
}

void agregar_patron(int **matriz){ //se agregan patrones aleatorios 

    ag_P = 1 + rand() % 8; 

    if (ag_P == 1){ // L

        matriz[3][3] = ACTIVA;
        matriz[4][3] = ACTIVA;
        matriz[5][3] = ACTIVA;
        matriz[6][3] = ACTIVA;
        matriz[6][4] = ACTIVA;
        matriz[6][5] = ACTIVA;
    
    }else if (ag_P == 2){ // T

        matriz[21][2] = ACTIVA;
        matriz[21][3] = ACTIVA;
        matriz[21][4] = ACTIVA;
        matriz[21][5] = ACTIVA;
        matriz[21][6] = ACTIVA;
        matriz[22][4] = ACTIVA;
        matriz[23][4] = ACTIVA;
        matriz[24][4] = ACTIVA;
        matriz[25][4] = ACTIVA;

    }else if (ag_P == 3){ // 0

        matriz[13][14] = ACTIVA;
        matriz[14][14] = ACTIVA;
        matriz[15][13] = ACTIVA;
        matriz[16][12] = ACTIVA;
        matriz[15][11] = ACTIVA;
        matriz[14][10] = ACTIVA;
        matriz[13][10] = ACTIVA;
        matriz[13][11] = ACTIVA;
        matriz[13][12] = ACTIVA;
        matriz[13][13] = ACTIVA;
        matriz[12][14] = ACTIVA;
        matriz[11][13] = ACTIVA;
        matriz[10][12] = ACTIVA;
        matriz[11][11] = ACTIVA;
        matriz[12][10] = ACTIVA;
   
    }else if (ag_P == 4){ // alicate

        matriz[3][22] = ACTIVA;
        matriz[2][22] = ACTIVA;
        matriz[1][22] = ACTIVA;
        matriz[4][22] = ACTIVA;
        matriz[5][22] = ACTIVA;
        matriz[3][21] = ACTIVA;
        matriz[3][20] = ACTIVA;
        matriz[3][19] = ACTIVA;
        matriz[4][18] = ACTIVA;
        matriz[4][17] = ACTIVA;
        matriz[2][18] = ACTIVA;
        matriz[2][17] = ACTIVA;
    
    }else if (ag_P == 5){ // abeja

        matriz[18][24] = ACTIVA;
        matriz[19][23] = ACTIVA;
        matriz[20][22] = ACTIVA;
        matriz[19][21] = ACTIVA;
        matriz[20][20] = ACTIVA;
        matriz[20][19] = ACTIVA;
        matriz[20][18] = ACTIVA;
        matriz[19][17] = ACTIVA;
        matriz[18][16] = ACTIVA;
        matriz[17][17] = ACTIVA;
        matriz[18][18] = ACTIVA;
        matriz[18][19] = ACTIVA;
        matriz[18][20] = ACTIVA;
        matriz[17][21] = ACTIVA;
        matriz[16][22] = ACTIVA;
        matriz[17][23] = ACTIVA;
        matriz[16][20] = ACTIVA;
        matriz[16][19] = ACTIVA;
        matriz[16][18] = ACTIVA;
    
    }else if (ag_P == 6){ // P,V,Y
        
        matriz[12][3] = ACTIVA;
        matriz[12][4] = ACTIVA;
        matriz[12][5] = ACTIVA;
        matriz[13][3] = ACTIVA;
        matriz[13][6] = ACTIVA;
        matriz[14][3] = ACTIVA;
        matriz[14][4] = ACTIVA;
        matriz[14][5] = ACTIVA;
        matriz[14][3] = ACTIVA;
        matriz[15][3] = ACTIVA;
        matriz[16][3] = ACTIVA;
        matriz[9][16] = ACTIVA;
        matriz[10][17] = ACTIVA;
        matriz[11][18] = ACTIVA;
        matriz[12][19] = ACTIVA;
        matriz[11][20] = ACTIVA;
        matriz[10][21] = ACTIVA;
        matriz[9][22] = ACTIVA;
        matriz[20][10] = ACTIVA;
        matriz[21][11] = ACTIVA;
        matriz[22][12] = ACTIVA;
        matriz[23][12] = ACTIVA;
        matriz[24][12] = ACTIVA;
        matriz[21][13] = ACTIVA;
        matriz[20][14] = ACTIVA;
    
    }else{ // corazon

        matriz[9][26] = ACTIVA;
        matriz[9][27] = ACTIVA;
        matriz[9][28] = ACTIVA;
        matriz[9][29] = ACTIVA;
        matriz[10][30] = ACTIVA;
        matriz[10][25] = ACTIVA;
        matriz[11][31] = ACTIVA;
        matriz[12][31] = ACTIVA;
        matriz[10][32] = ACTIVA;
        matriz[9][33] = ACTIVA;
        matriz[9][34] = ACTIVA;
        matriz[9][35] = ACTIVA;
        matriz[9][36] = ACTIVA;
        matriz[10][37] = ACTIVA;
        matriz[11][24] = ACTIVA;
        matriz[12][24] = ACTIVA;
        matriz[13][24] = ACTIVA;
        matriz[14][24] = ACTIVA;
        matriz[15][24] = ACTIVA;
        matriz[11][38] = ACTIVA;
        matriz[12][38] = ACTIVA;
        matriz[13][38] = ACTIVA;
        matriz[14][38] = ACTIVA;
        matriz[15][38] = ACTIVA;
        matriz[16][25] = ACTIVA;
        matriz[16][37] = ACTIVA;
        matriz[17][26] = ACTIVA;
        matriz[17][36] = ACTIVA;
        matriz[18][27] = ACTIVA;
        matriz[18][35] = ACTIVA;
        matriz[19][28] = ACTIVA;
        matriz[18][34] = ACTIVA;
        matriz[20][29] = ACTIVA;
        matriz[20][33] = ACTIVA;
        matriz[21][30] = ACTIVA;
        matriz[21][32] = ACTIVA;
        matriz[22][31] = ACTIVA;
    }
}

int **crearMatriz_original(int f, int c){
    int **v;
    v = (int **)malloc(f * sizeof(int *));
    if (v == NULL){
        printf("No hay memoria\n");
        exit(-1);
    }
    for (int i = 0; i < f; ++i){
        v[i] = (int *)malloc(c * sizeof(int));
        if (v[i] == NULL){
            printf("No hay memoria\n");
            exit(-1);
        }
    }

    return v;
}

void liberarMatriz_original(int **matrix, int f, int c){
    for (int i = 0; i < f; ++i){
        free(matrix[i]);
    }
    free(matrix);
}

int **crearMatriz_auxiliar(int f, int c){
    int **vec;//un puntero a puntero(vector de punteros)
    vec = (int **)malloc(f * sizeof(int *));//se reserva espacio para el vector de punteros(para cada una las filas)
    
    if (vec == NULL){// se revisa si funcionoel primer malloc 
        printf("No hay memoria\n");
        exit(-1);
    }
    
    for (int i = 0; i < f; ++i){
        vec[i] = (int *)malloc(c * sizeof(int));// se reserva el espacio para columnas
        if (vec[i] == NULL){
            printf("No hay memoria\n");
            exit(-1);
        }
    }

    return vec;
}

void liberarMatriz_auxiliar(int **mat, int f, int c){ //liberar memoria matriz auxiliar
    for (int i = 0; i < f; ++i){
        free(mat[i]);
    }
    free(mat);
}

#endif
