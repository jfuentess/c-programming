
void updateScreen(prt *particles, SDL_Rect *gamecoords,int quantity, SDL_Rect *points, int c_points, int gamemode,SDL_Renderer *ren, SDL_Texture *backgroundTexture, SDL_Rect back_pos, SDL_Rect *mouseRect){
  //update render
  
  SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
  SDL_RenderClear(ren);
  SDL_RenderCopy(ren, backgroundTexture, NULL, NULL);
  
  for(int i=0;i<quantity;i++){
    SDL_SetRenderDrawColor(ren,0, abs(particles[i].dy+1)*125, abs(particles[i].dx+1)*125, 255);
    SDL_RenderFillRect(ren, &(particles[i].coords));
  }
  if(gamemode==2){
    for(int i=0;i<c_points;i++){
      SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
      SDL_RenderFillRect(ren, &points[i]);
    }
    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
    SDL_RenderFillRect(ren, mouseRect);
  }
  SDL_RenderPresent(ren);
  SDL_Delay(10);
}

int render(prt *particles , SDL_Rect *gamecoords, int quantity, SDL_Rect *points){
  int saves;

  SDL_Window *w=NULL;
  SDL_Renderer *ren=NULL;
  SDL_Surface *s=NULL;
  
  //MENU
  SDL_Surface *menuimg = NULL;
  SDL_Surface *menumodes = NULL;
  SDL_Surface *menucredits = NULL;
  SDL_Surface *backgroundSurface = NULL;
  SDL_Texture *backgroundTexture = NULL;

  SDL_Rect back_pos;
  back_pos.x=1200;
  back_pos.y=620;
  
  //MUSICA
  Mix_Music *menumusic = (Mix_Music*)malloc(sizeof(Mix_Music*));
  Mix_Chunk *hit = (Mix_Chunk*)malloc(sizeof(Mix_Chunk*));

  //rendering
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
    printf("SDL_Init error%s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    return -1;
  }
  
  //crear ventana
  w = SDL_CreateWindow("Colisiones",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
  if(w ==NULL){
    printf("SDL_CreateWindow error %s\n", SDL_GetError());
  }
  //crear renderer(para dibujar en pantalla)
  ren = SDL_CreateRenderer(w,-1,SDL_RENDERER_ACCELERATED);
  if(ren==NULL){
    fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(w);
    SDL_Quit();
    return EXIT_FAILURE;
  }
  

  //crear surface
  s=SDL_GetWindowSurface(w);

 //Cargar imagenes del menu
  menuimg=SDL_LoadBMP("screens/menu.bmp");
  menumodes=SDL_LoadBMP("screens/menu_modes.bmp");
  menucredits=SDL_LoadBMP("screens/credits.bmp");
  
  //Cargar fondo del juego
  backgroundSurface = SDL_LoadBMP("screens/fondo.bmp");
  backgroundTexture = SDL_CreateTextureFromSurface(ren, backgroundSurface);
  
  //Cargar sonidos
  menumusic = Mix_LoadMUS("music/menu.mp3");
  if(menumusic == NULL)
    printf("ERROR AL CARGAR MUSIC Menu\n");
  hit=Mix_LoadWAV("music/hit.wav");
  if(hit == NULL)
    printf("ERROR AL CARGAR MUSIC Menu\n");

  Mix_PlayMusic(menumusic,-1);
  //Presentar menu
  SDL_BlitSurface(menuimg,NULL,s,NULL);

  SDL_UpdateWindowSurface(w);
 

  //key representara la tecla presionada
  const Uint8* key =SDL_GetKeyboardState(NULL);

  int quit = 0, pause=-1;
  int menu=0, oncredits=0,ongame=0,gamemode=0;
  int c_points=0;
  int x,y;

  while(!quit){
    //Keyboard and window events
    SDL_Event event;
    if(menu==0){
      while(SDL_PollEvent(&event) != 0){
	if(event.type == SDL_QUIT){
	  quit = 1;
	}
	else if(event.type == SDL_MOUSEBUTTONDOWN){
	  SDL_GetMouseState(&x,&y);
    printf("x=%d, y=%d", x,y);
	  if(oncredits==0 && ongame==0){
	    //click newgame
	    if((x>453 && x<824) && (y>333 && y<384)){
	      ongame=1;
	      SDL_BlitSurface(menumodes,NULL,s,NULL);
	    }
	    //click credits
	    if((x>495 && x<779) && (y>434 && y<489)){
	      oncredits=1;
	      SDL_BlitSurface(menucredits,NULL,s,NULL);
	    }
	    //click return
	    if((x>564 && x<717) && (y>541 && y<589)){
	      quit=1;
	    }
	  }
	  if(ongame==1){
	    //entrar modo normal
	    if((x>52 && x<424)&&(y>173 && y<238)){
	      gamemode=1;
	      menu=1;
	      Mix_HaltMusic();
	    }
	    //entrar modo creativo
	    if((x>43 && x<464)&&(y>443 && y<509)){
	      gamemode=2;
	      menu=1;
	      Mix_HaltMusic();
	    }
	    //click return
	    if((x>985 && x<1219)&&(y>652 && y<694)){
	      ongame=0;
	      SDL_BlitSurface(menuimg,NULL,s,NULL);
	    }
	  }
	  if(oncredits==1){
	    //click return
	    if((x>985 && x<1219)&&(y>652 && y<694)){
	      oncredits=0;
	      SDL_BlitSurface(menuimg,NULL,s,NULL);
	    }
	  }
	}
      }
      SDL_UpdateWindowSurface(w);
    }
    if(menu==1){
      //mouse
      SDL_GetMouseState(&x, &y);
      SDL_Rect mouseRect = { x-5, y-5,20,25}; // Rectángulo centrado en el mouse
      
      while(SDL_PollEvent(&event)!=0){
	//pausa y exit
	if(event.type ==SDL_QUIT){
	  quit=1;
	}else if(event.type==SDL_KEYDOWN){
	  if(key[SDL_SCANCODE_Q]){
	    quit=1;
	  }
	  if(key[SDL_SCANCODE_P]){
	    pause*=-1;
	  }
	  if(key[SDL_SCANCODE_G]){
	    saves++;
	    SaveState(particles, quantity,  saves);
	  }
	}
	else if(event.type == SDL_MOUSEBUTTONDOWN){
          SDL_GetMouseState(&x,&y);
          if((x>1163 && x<1236) && (y>631 && y<707)){
            menu=0;
            Mix_HaltMusic();
            Mix_PlayMusic(menumusic,-1);
          }
        }
	if(gamemode!=0){
	  if(event.type == SDL_MOUSEBUTTONDOWN){
	    SDL_GetMouseState(&x,&y);
	    if((x>1200 && x<1280) && (y>620 && y<704)){
	      menu=0;
	    }
	  }
	}
	if(gamemode==2){
	  if(key[SDL_SCANCODE_W]){
	    for(int i=0;i<quantity;i++){
	      particles[i].coords.h+=1;
	      particles[i].coords.w+=1;
	    }
	  }
	  if(key[SDL_SCANCODE_S]){
	    for(int i=0;i<quantity;i++){
	      particles[i].coords.h-=1;
	      particles[i].coords.w-=1;
	    }
	  }
	  if(key[SDL_SCANCODE_N]){
	    quantity++;
	    prt *temp = realloc(particles, (quantity)*sizeof(prt));
	    if(particles == NULL){
	      fprintf(stderr, "Memory reallocation failed.\n");
	      exit(EXIT_FAILURE);
	    }
	    particles = temp;
	    
	    particles[quantity-1].coords.x=rand()%WIDTH;
	    particles[quantity-1].coords.y=rand()%HEIGHT;
	    particles[quantity-1].coords.w=rand()%10+11;
	    particles[quantity-1].coords.h=rand()%10+11;
	    particles[quantity-1].dx=rand()%3-1;
	    particles[quantity-1].dy=rand()%3-1;
	    particles[quantity-1].block=0;
	  }
	  //guardar posicion al pulsar click izquierdo
	  if ((event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) ||
	      (event.type == SDL_MOUSEMOTION && event.motion.state && SDL_BUTTON(SDL_BUTTON_LEFT))) {
	    //para no rayar a la derecha
	    if(event.button.x<1200){
	      points[c_points].x = event.button.x;
	      points[c_points].y = event.button.y;
	      points[c_points].w=10;
	      points[c_points].h=10;
	      c_points++;
	      points = (SDL_Rect *)realloc(points,(c_points+1)*sizeof(SDL_Rect));
	    }
	  }
	}
      }

      if(pause!=1){
	collisions(particles,  quantity,  mouseRect,  points,  c_points,  gamemode, hit);
      }
      //update render
      updateScreen(particles, gamecoords, quantity, points, c_points,  gamemode, ren, backgroundTexture, back_pos, &mouseRect);
    }
  }
  free(points);
  free(particles);
  free(gamecoords);
  Mix_HaltMusic();
  Mix_FreeMusic(menumusic);
  Mix_CloseAudio();
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(w);
  SDL_Quit();
  return 0;
}
