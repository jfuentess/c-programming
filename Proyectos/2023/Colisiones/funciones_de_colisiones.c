
#define down 1
#define up 1<<1
#define left 1<<2
#define right 1<<3

int rectIntersection(prt* rect1,prt* rect2) {
    int x1=rect1->coords.x;
    int y1=rect1->coords.y;
    int w1=rect1->coords.w;
    int h1=rect1->coords.h;
    int dx1=rect1->dx;
    int dy1=rect1->dy;

    int x2=rect2->coords.x;
    int y2=rect2->coords.y;
    int w2=rect2->coords.w;
    int h2=rect2->coords.h;
    int dx2=rect2->dx;
    int dy2=rect2->dy;

    return (((x1+w1 >= x2) &&                 //detects if the particle j is inside particle i in the current frame
	     (x1 <= x2+w2) &&
	     (y1+h1 >= y2) &&
	     (y1 <= y2+h2))
	    || ((x1+dx1+w1 >= x2) &&          //detects if particle j is inside i after i moves
		(x1+dx1 <= x2+w2) &&
		(y1+dy1+h1 >= y2) &&
		(y1+dy1 <= y2+h2))
	    || ((x1+w1 >= x2+dx2) &&          //detects if particle j is inside i after j moves
		(x1 <= x2+dx2+w2) &&
		(y1+h1 >= y2+dy2) &&
		(y1 <= y2+dy2+h2))
	    || ((x1+dx1+w1 >= x2+dx2) &&      //detects if particle j is inside i after both moves
		(x1+dx1 <= x2+dx2+w2) &&
		(y1+dy1+h1 >= y2+dy2) &&
		(y1+dy1 <= y2+dy2+h2)));      //If at least of those are true then it returns true
}

void sidetouch(prt* prt1, prt* prt2){
  if((prt1->coords.x + prt1->coords.w <= prt2->coords.x)&&(prt2->dx <= 0)){ //if the particle 1 is at the left of prt 2 then prt 1 can't move to the right
    prt1->block |= (right);
  }
  if((prt1->coords.x >= prt2->coords.x + prt2->coords.w)&&(prt2->dx >= 0)){ //if the particle 1 is at the right of prt 2 then prt 1 can't move to the left
    prt1->block |= (left);
  }
  if((prt1->coords.y >= prt2->coords.y + prt2->coords.h)&&(prt2->dy >= 0)){ //if the particle 1 is down of prt 2 then prt 1 can't move to the down
    prt1->block |= (up);
  }
  if((prt1->coords.y + prt1->coords.h <= prt2->coords.y)&&(prt2->dy <= 0)){ //if the particle 1 is up  of prt 2 then prt 1 can't move to the up
    prt1->block |= (down);
  }
}

void blockedpath(prt* prt1, prt* prt2) {
  //checks if the opposite side that is touching particle 2 of the particle 1 is blocked and blocks the side of prt 2 thats touching prt 1
  
  if(prt1->coords.x + prt1->coords.w <= prt2->coords.x){ //if left of prt 1 is blocked then block left for prt 2 when |(prt1)(prt2)
    if(prt1->block & (left)) { 
      prt2->block |= (left);
    }
  }
  if(prt1->coords.x >= prt2->coords.x + prt2->coords.w) { //if right of prt 1 is blocked then block rigth for prt 2 when (prt2)(prt1)|
    if(prt1->block & (right)) {
      prt2->block |= (right);
    }
  }
  if(prt1->coords.y + prt1->coords.h <= prt2->coords.y) { //if down of prt 1 is blocked then block up for prt 2
    if(prt1->block & (up)) {
      prt2->block |= (up);
    }
  }
  if(prt1->coords.y >= prt2->coords.y + prt2->coords.h) { //if down of prt 1 is blocked then block down for prt 2
    if(prt1->block & (down)) {
      prt2->block |= (down);
    }
  }
}

int collisions(prt *particles,int quantity, SDL_Rect mouseRect, SDL_Rect *points, int c_points, int gamemode, Mix_Chunk *hit){
  int collcount=0;
  prt Mouse={mouseRect,0,0,0,0};

  //collision detection
  srand(time(NULL));
  for(int i=0;i<quantity;i++){
    
    //....wall collision.....//
    
    if(particles[i].coords.x>=WIDTH-particles[i].coords.w){
      particles[i].block|=(right);
      collcount++;
    }
    if(particles[i].coords.y>=HEIGHT-particles[i].coords.h){
      particles[i].block|=(down);
      collcount++;
    }
    if(particles[i].coords.x<=0){
      particles[i].block|=(left);
      collcount++;
    }
    if(particles[i].coords.y<=0){
      particles[i].block|=(up);
      collcount++;
    }

    //......................//
    if(gamemode==2){
      if(rectIntersection(&(Mouse),&(particles[i]))){
	Mix_PlayChannel(-1,hit,0);
	sidetouch(&(particles[i]),&(Mouse));
	if(particles[i].block==up){
	  particles[i].coords.y=mouseRect.y+mouseRect.h;
	} else  if(particles[i].block==down){
	  particles[i].coords.y=mouseRect.y-particles[i].coords.h;
	} else  if(particles[i].block==left){
	  particles[i].coords.x=mouseRect.x+mouseRect.w;
	} else	if(particles[i].block==right){
	  particles[i].coords.x=mouseRect.x-particles[i].coords.w;
	}
      }
      
      for(int j=0;j<c_points;j++){
	prt Point = {points[j],0,0,0,0};
	if(rectIntersection(&(particles[i]),&(Point))){
	  Mix_PlayChannel(-1,hit,0);
	  sidetouch(&(particles[i]),&(Point));
	}
      }
    }
    //......................in-particles collision.....................//
    
    for(int j=i+1;j<quantity;j++){
      if(rectIntersection(&(particles[j]),&(particles[i]))){
	Mix_PlayChannel(-1,hit,0);
	collcount++;
	//..........in-particle detection of side of collision and movement blocking.........//
	
	if(particles[i].mass<particles[j].mass){
	  sidetouch(&(particles[i]),&(particles[j])); //detects in which side of the particle i is being touched and block that movement direction
	}
	else{
	  if(particles[i].mass>particles[j].mass){
	    sidetouch(&(particles[j]),&(particles[i])); //detects in which side of the particle j is being touched and block that movement direction
	  }
	  else{
	    if(particles[i].mass==particles[j].mass){
	      sidetouch(&(particles[i]),&(particles[j])); //detects in which side of the particle i is being touched and block that movement direction
	      sidetouch(&(particles[j]),&(particles[i])); //detects in which side of the particle j is being touched and block that movement direction
	    }
	  }
	}
      }
    }
  }
  for(int i=0;i<quantity;i++){
    for(int j=0;j<quantity;j++){
      if(i!=j){
	if(particles[j].mass>particles[i].mass){
	  if(rectIntersection(&(particles[j]),&(particles[i]))){ //after detecting the sides of collisions of the particles with lesser mass,
	    blockedpath(&(particles[i]),&(particles[j]));        //we have to ensure that the particles with bigger mass can't clip into the particles with lower masses that can't move in certain directions that are touching it
	  }
	}
      }
    }
    
    if(particles[i].block!=0){
      if(((~(particles[i].block) & right)==(right))&&((~(particles[i].block) & left)==(left))){ //if right and left aren't blocked the the direction in the x axis after a collition is random
	particles[i].dx=randDir;
      }else{
	if(((~(particles[i].block) & right)==(right))&&((~(particles[i].block) & left)!=(left))){ //if only left is blocked then the particle will go to the right
	  particles[i].dx=1;
	}else{
	  if(((~(particles[i].block) & right)!=(right))&&((~(particles[i].block) & left)==(left))){ //if only right is blocked then the particle will go to the left
	    particles[i].dx=-1;
	  }else{
	    particles[i].dx=0; //if both right and left are blocked the particle won't move in the x axis
	  }
	}
      }
      if(((~(particles[i].block) & up)==(up))&&((~(particles[i].block) & down)==(down))){ //if up and down aren't blocked the the direction in the y axis after a collition is random
	particles[i].dy=randDir;
      }else{
	if(((~(particles[i].block) & up)==(up))&&((~(particles[i].block) & down)!=(down))){ //if only down is blocked then the particle will go up
	  particles[i].dy=-1;
	}else{
	  if(((~(particles[i].block) & up)!=(up))&&((~(particles[i].block) & down)==(down))){ //if only up is blocked then the particle will go down
	    particles[i].dy=1;
	  }else{
	    particles[i].dy=0; //if up right and down are blocked the particle won't move in the y axis
	  }
	}
      }
    }
    particles[i].coords.x+=particles[i].dx; //update positions
    particles[i].coords.y+=particles[i].dy;
    particles[i].block=0;
  }
  return collcount;
}
