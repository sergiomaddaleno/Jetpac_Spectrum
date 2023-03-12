
//los puntos cuando hay colisión
bool PointCollision(int x1,int y1, int x2,int y2, int w2,int h2){
  return x1>=x2 && x1<=x2+w2 && y1>=y2 && y1<=y2+h2;
}

bool BoxCollision(int x1,int y1, int w1,int h1, int x2,int y2, int w2,int h2) {

  return PointCollision(x1,y1,x2,y2,w2,h2) ||
         PointCollision(x1+w1,y1,x2,y2,w2,h2) ||
         PointCollision(x1+w1,y1+h1,x2,y2,w2,h2) ||
         PointCollision(x1,y1+h1,x2,y2,w2,h2);
}

bool CollisionPlayerShip1(TPlayer *player, TShip *ship_1){

  if (BoxCollision(
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*ship_1).position.x,(*ship_1).position.y,
                  (*ship_1).size.x, (*ship_1).size.y)) {

    shipWithPlayer=true;

  return true;}
  else{return false;}
}

bool CollisionPlayerShip2(TPlayer *player, TShip *ship_2){

  if (BoxCollision(
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*ship_2).position.x,(*ship_2).position.y,
                  (*ship_2).size.x, (*ship_2).size.y)) {

    shipWithPlayer2=true;
      
  return true;}
  else{return false;}
}

void CollisionPlayerFlyShip(TPlayer *player, TShip *fullship){

  if (BoxCollision(
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*fullship).position.x,(*fullship).position.y,
                  (*fullship).size.x, (*fullship).size.y)) {

    shipFlying=true;
  }
}


bool CollisionFuelPlayer(TPlayer *player, TObjects *fuel){

  if (BoxCollision(
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*fuel).position.x,(*fuel).position.y,
                  (*fuel).size.x, (*fuel).size.y)) {

      fuelWithPlayer=true;
      
  return true;}
  else{return false;}
}

bool CollisionObjectPlayer(TPlayer *player, TObjects *object){

  if (BoxCollision(
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*object).position.x,(*object).position.y,
                  (*object).size.x, (*object).size.y)) {

      objectWithPlayer=true;
  return true;}
  else{return false;}
}

bool CollisionPlatform(TPlayer *player, TPlatform *platform){

  if (BoxCollision( 
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*platform).position.x,(*platform).position.y,
                  (*platform).size.x, (*platform).size.y)) {
      
        while (BoxCollision((*player).position.x, (*player).position.y,
                            (*player).size.x,(*player).size.y,
                            (*platform).position.x,(*platform).position.y,
                            (*platform).size.x, (*platform).size.y)){

            if ((*player).position.y < (*platform).position.y) { //para que no suba
                (*player).position.y--;
                
            }
            //para que no baje
            if ((*player).position.y + (*player).size.y > (*platform).position.y + (*platform).size.y) {
                (*player).position.y++;
            }
        }
  return true;}
  else{return false;}
}

void CollisionPlatformObject(TObjects *object, TPlatform *platform){

  if (BoxCollision( 
                  (*object).position.x, (*object).position.y,
                  (*object).size.x,(*object).size.y,
                  (*platform).position.x,(*platform).position.y,
                  (*platform).size.x, (*platform).size.y)) {
        
      object->gravity=0;
  }
}

bool CollisionWindStructure(TEnemies *wind, TPlatform *platform){

  if (BoxCollision(
                  (*wind).position.x, (*wind).position.y,
                  (*wind).size.x,(*wind).size.y,
                  (*platform).position.x,(*platform).position.y,
                  (*platform).size.x, (*platform).size.y)) {
      
  return true;}
  else{return false;}
}

bool CollisionEnemiesStructure(TEnemies *enemy, TPlatform *platform){

  if (BoxCollision(
                  (*enemy).position.x, (*enemy).position.y,
                  (*enemy).size.x,(*enemy).size.y,
                  (*platform).position.x,(*platform).position.y,
                  (*platform).size.x, (*platform).size.y)) {
      
  return true;}
  else{return false;}
}

bool CollisionPlayerEnemy(TPlayer *player, TEnemies *enemy) {
  if (BoxCollision(
                  (*player).position.x, (*player).position.y,
                  (*player).size.x,(*player).size.y,
                  (*enemy).position.x,(*enemy).position.y,
                  (*enemy).size.x, (*enemy).size.y)) {
    player->movePlayer = false;
    player->alive = false;
    return true;
  }
  return false;
}




