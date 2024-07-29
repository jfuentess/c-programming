int validador(int argc, char *argv[]) {
  char *punto = strrchr(argv[1], '.'); //guarda la posicion del punto de extension de archivo
  
  if (strcmp(punto + 1, "txt") == 0) {             //revisa si lo siguiente es igual a txt
    return 3;
  } else if (strcmp(punto + 1, "csv") == 0) {      //revisa si lo siguiente es igual a csv
    return 2;
  } else if (strcmp(punto + 1, "bin") == 0) {      //revisa si lo siguiente es igual a bin
    return 1;
  }
  free(punto);
  return 0;
}

int validarx(int a) {
  if (a == 3 || a == 6 || a == 9) {        //transforma los numeros del 1 al 9 a direcciones en el eje x
    return 1;
  }
  else if (a == 1 || a == 4 || a == 7) {
    return -1;
  }
  else {
    return 0;
  }
}
int validary(int a) {                    //transforma los numeros del 1 al 9 a direcciones en el eje y
  if (a == 1 || a == 2 || a == 3) {
    return 1;
  }
  else if (a == 7 || a == 8 || a == 9) {
    return -1;
    }
  else {
    return 0;
  }
}

int countBIN(FILE *archivo){          
  int quantity=0;
  int array[3] = {0};
  while (fread(array, sizeof(int), 3, archivo) == 3) { //revisa si puede leer datos del tamaño de 3 enteros hasta que no pueda y va sumando las veces que lo hace
    quantity++;
  }
  return quantity;
}

int countCSV(FILE *archivo){
  char buffer[1000];
  int quantity;
  while (fgets(buffer, sizeof(buffer), archivo) != NULL) { //guarda los datos en el buffer
    strtok(buffer, ","); //va quitando , hasta que no queden y va sumando las veces que lo hace
    quantity++;
  }
  return quantity;
}
int countTXT(FILE *archivo){
  int quantity = 0;
  char buffer[1024];
  
  while (fgets(buffer, sizeof(buffer), archivo) != NULL) { //guarda los datos en el buffer hasta que no pueda y va sumando las veces que se encuentran () juntos
    char *inicio = strchr(buffer, '('); //busca el primer ( guardado
    char *fin = strchr(buffer, ')'); //busca el primer ) guardado
    while (inicio != NULL && fin != NULL) { 
      quantity++;
      inicio = strchr(fin + 1, '('); //busca el siguiente (
      fin = strchr(fin + 1, ')'); //busca el siguiente )
    }
  }
  return quantity;
}

int countPRT(FILE *archivo,int tipo){ //redirige a las funciones correspondientes de conteo de particulas
  int quantity=0;   
    //TXT
    if (tipo == 3) {
      quantity=countTXT(archivo);
    }
    
    //CSV
    if (tipo == 2) {
        quantity=countCSV(archivo);
    }

    //BIN
    if (tipo == 1) {
      quantity=countBIN(archivo);
    }
    return quantity;
}

int dir2int(int dx, int dy){ //transforma direcciones en el eje x e y en numeros del 1 al 9
  if(dx==1){
    if(dy==1){
      return 3;
    } else if(dy==0){
      return 6;
    } else if(dy==-1){
      return 9;
    }
  }else if(dx==0){
    if(dy==1){
      return 2;
    } else if(dy==0){
      return 5;
    } else if(dy==-1){
      return 8;
    }
  }else if(dx==-1){
    if(dy==1){
      return 1;
    } else if(dy==0){
      return 4;
    } else if(dy==-1){
      return 7;
    }
  }
  return 0;
}


void SaveState(prt *particles,int quantity, int saves){
  int size=14+saves/10;
  char *name= (char*)malloc(size);  //crea un arreglo del tamaño del nombre del arrchivo
  sprintf(name,"savestate_%d.bin",saves); //se introduce el numero de guardado
  FILE *save = fopen(name,"wb");
  for(int i=0;i<quantity;i++){
    int dir=dir2int(particles[i].dx,particles[i].dy);
    fwrite(&(particles[i].coords.x), sizeof(int),1,save); //se guarda x de la particula i
    fwrite(&(particles[i].coords.y), sizeof(int),1,save); //se guarda y de la particula i
    fwrite(&(dir), sizeof(int),1,save); //se guarda la direccion de la particula i
  }

  free(name);
  fclose(save);
}
