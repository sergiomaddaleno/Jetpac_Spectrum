
TListEnemies *stackWind, *stackBush, *stackBall, *stackDust, *stackBird, *stackCross; 

//Para dibujar todas las explosiones
void drawExplosionSprites(TCoords position) {

    if (contExp > 0 && contExp < 2) {
        esat::DrawSprite(g_explosion1_sprite, position.x, position.y);
    }
    if (contExp > 1 && contExp < 3) {
        esat::DrawSprite(g_explosion2_sprite, position.x, position.y);
    }
    if (contExp > 2 && contExp < 4) {
        esat::DrawSprite(g_explosion3_sprite, position.x, position.y);
    }
    if (contExp > 3 && contExp < 5) {
        esat::DrawSprite(g_explosion3_empty1_sprite, position.x, position.y);
    }
    if (contExp > 4 && contExp < 8) {
        esat::DrawSprite(g_explosion3_empty2_sprite, position.x, position.y);
    }
    contExp++;
}

//posibles movimientos
void moveEnemy(TEnemies *enemy) {
    switch (enemy->direction) {
        case 0: // right and down
            enemy->position.x += enemy->speed;
            enemy->position.y += enemy->speedY;
            break;

        case 1: // right and up
            enemy->position.x += enemy->speed;
            enemy->position.y -= enemy->speedY;
            break;

        case 2: // left and up
            enemy->position.x -= enemy->speed;
            enemy->position.y -= enemy->speedY;
            break;

        case 3: // left and down
            enemy->position.x -= enemy->speed;
            enemy->position.y += enemy->speedY;
            break;

        case 4: // no change
            break;

        case 5: // down
            enemy->position.y += enemy->speedY;
            break;

        case 6: // up
            enemy->position.y -= enemy->speedY;
            break;

        case 7: // right
            enemy->position.x += enemy->speed;
            break;

        case 8: // left
            enemy->position.x -= enemy->speed;
            break;
    }
}

//Cambia posicion cuando llega a uno de los bordes
void ChangePosition(TCoords &position, int windowWidth, int windowHeight) {
    if (position.x >= windowWidth) {
        position.x = 0;
    }
    else if (position.x <= 0) {
        position.x = windowWidth;
    }
}

//Cambia direccion cuando llega a la parte superior o inferior
void ChangeDirection(TCoords& position, int windowHeight, int& direction) {
    //parte arriba
    if (position.y < 20 && direction == 2) {
        direction = 3;
    } else if (position.y < 20 && direction == 1) {
        direction = 0;
    }

    //parte abajo
    if (position.y > windowHeight - 100 && direction == 0) {
        direction = 1;
    } else if (position.y > windowHeight - 100 && direction == 3) {
        direction = 2;
    }
}

//Cuando un enemigo colisiona con una de las plataformas cambia la direccion
void ChangeDirectionPlatform(TEnemies *enemy, TPlatform *platform) {
    if (CollisionEnemiesStructure(enemy, platform)) {
           
            if (enemy->direction == 0) {
                enemy->direction = 1;
            }else{enemy->direction = 2;}

            if (enemy->direction == 1) {
                enemy->direction = 0; 
            }else{enemy->direction = 3; 
            }    
    }
}

//Caundo el player colisiona con algun enemigo, se reestablece su posicion
void PlayerReset(TPlayer *player, TEnemies *enemy) {

    if (player->inmortal == false){
        CollisionPlayerEnemy(player, enemy);
        
    }
    if(player->alive==false && playerLife>=0){
        
        player->position.x = kWindowWidth - 300;
        player->position.y = kWindowHeight - 120;
        cont++;
        if (cont >= 250) {
            playerLife = playerLife - 1;  
            life1 = life1 - 1;
            player->alive = true;
            player->movePlayer = true;
            player->inmortal = true;
        }
    }

    if(cont == 250){
        cont3++;
    }

    if (cont3 == 500) {
        player->inmortal = false;
        cont = 0;
        cont3 = 0;
    }
}

//--------------------------------------------------------------------------------------------------------------------

void InitWindandFalcon() {
    CreateListEnemies(&stackWind);
    srand(time(NULL));

    int randomNumber;

    for (int i = 0; i < numEnemies; i++) {
        randomNumber = rand() % 4; // Generar un número entre 0 y 3
        
        if (randomNumber == 0) {
            randomNumber = 0;
        } else if (randomNumber == 1) {
            randomNumber = 3;
        } else if (randomNumber == 2) {
            randomNumber = 7;
        } else {
            randomNumber = 8;
        }

        g_Wind.numb=i;
        g_Wind.position.x = 0;
        g_Wind.position.y = 70 + rand() % (kWindowHeight-70);
        g_Wind.size.x = 63;
        g_Wind.size.y = 36;
        g_Wind.speed = 3;
        g_Wind.speedY = 1;
        g_Wind.direction = randomNumber;
        g_Wind.active = true;
        g_Wind.collision = false;
        g_Wind.sprite = g_wind1_left_sprite;
        InsertListEnemies(&stackWind, g_Wind);
    }
}


void ModifyStackWindandFalcon(TNodeEnemies **list){
    
    srand(time(NULL));
    int RandNum = rand()%kWindowHeight;
    int randomNumber = rand() % 4; // Generar un número aleatorio entre 0 y 3

    
    if (randomNumber == 0) {
        randomNumber = 0;
    } else if (randomNumber == 1) {
        randomNumber = 3;
    } else if (randomNumber == 2) {
        randomNumber = 7;
    } else {
        randomNumber = 8;
    }
    int randColor = rand()%2; //generar un nuevo color aleatorio
	TNodeEnemies *p;
	if(!IsemptyListEnemies(*list)){
		for(p=*list;p!=nullptr;p=p->prox){         
            
            //Movimientos del wind
            moveEnemy(&p->info);

            //Si el wind pasa de los distintos bordes del mapa
            ChangePosition(p->info.position, kWindowWidth, kWindowHeight);

            if(p->info.position.y > kWindowHeight-64){ //cuando llega al suelo
                p->info.position.y = 70 + rand() % (kWindowHeight-70);
            }

            if(p->info.active){ 
                //printf("stack  %d %d %d %d\n", p->info.numb, p->info.cont, p->info.active, p->info.collision); 
                //wind
                if(levelCount==0 || levelCount==8){
                    //dibuja wind
                    if(p->info.direction==0 || p->info.direction==7) {

                        esat::DrawSprite(g_wind1_right_sprite, p->info.position.x, p->info.position.y); 
                    }else{

                        esat::DrawSprite(g_wind1_left_sprite, p->info.position.x, p->info.position.y);
                    }

                    //animacion de wind
                    ++animation4%=20;
                    if(p->info.direction == 0 || p->info.direction == 7){
                        if (animation4<5)                    {esat::DrawSprite(g_wind1_right_sprite, p->info.position.x, p->info.position.y);}
                        if (animation4>=10 && animation4<20) {esat::DrawSprite(g_wind2_right_sprite, p->info.position.x, p->info.position.y);}
                    }else{
                        if (animation4<5)                    {esat::DrawSprite(g_wind1_left_sprite, p->info.position.x, p->info.position.y);}
                        if (animation4>=10 && animation4<20) {esat::DrawSprite(g_wind2_left_sprite, p->info.position.x, p->info.position.y);}
                    }
                }

                //ship 
                if(levelCount==6 || levelCount==14){

                    if(p->info.direction==0 || p->info.direction==7) {

                        esat::DrawSprite(g_millenniumFalcon_right_sprite, p->info.position.x, p->info.position.y); 
                    }else{

                        esat::DrawSprite(g_millenniumFalcon_left_sprite, p->info.position.x, p->info.position.y);
                    }
                }

                //collision player con wind
                PlayerReset(pPlayer, &p->info);

                //Compruebo si hay colision de wind con plataforma  
                if(CollisionWindStructure(&p->info, pPlatform_2) || CollisionWindStructure(&p->info, pPlatform_3) ||
                   CollisionWindStructure(&p->info, pPlatform_4) || p->info.position.y > kWindowHeight-70){
                    p->info.active=false;
                    p->info.direction=4;
                }
            }

            if(p->info.active==false){ //cuando hay una colision
                
               drawExplosionSprites(p->info.position);

                if(contExp==8){ //cuando termina colision activo de nuevo el wind
                    p->info.active=true;
                    p->info.position.x = 0;
                    p->info.position.y = 70 + rand() % (kWindowHeight-70);
                    p->info.direction = randomNumber;
                    contExp=0;
                }
                
            }
        }
    }
}

//--------------------------------------------------------------------------------------------------------------------

void InitBush() {
    CreateListEnemies(&stackBush);
    srand(time(NULL));

    for(int i = 0; i < numEnemies; i++) {
        int startPos = rand() % kWindowHeight + 32;
        int startDir = rand() % 4; 
        int startPosX = rand() % kWindowWidth;

        g_Bush.position.x = 0;
        g_Bush.position.y = startPos;
        g_Bush.size.x = 63;
        g_Bush.size.y = 36;
        g_Bush.speed = 3;
        g_Bush.speedY = 3;
        g_Bush.direction = startDir;
        g_Bush.active = true;
        g_Bush.sprite = g_bush1_sprite;
        InsertListEnemies(&stackBush, g_Bush);
    }
}


void ModifyStackBush(TNodeEnemies **list){

    srand(time(NULL));
    int RandNum = rand()%kWindowHeight;
    
	TNodeEnemies *p;
	if(!IsemptyListEnemies(*list)){
		for(p=*list;p!=nullptr;p=p->prox){ 

            //Posibles direcciones del bush
            moveEnemy(&p->info);

            //Si el bush pasa de los distintos bordes del mapa
            ChangePosition(p->info.position, kWindowWidth, kWindowHeight);

            //Limite del mapa parte inferior y superior del bush
            ChangeDirection(p->info.position, kWindowHeight, p->info.direction);
            
            if(p->info.active){ 

                esat::DrawSprite(p->info.sprite, p->info.position.x, p->info.position.y);
                ++animation4%=15;
                if (animation4<5)                    {esat::DrawSprite(g_bush1_sprite, p->info.position.x, p->info.position.y);}
                if (animation4>=10 && animation4<15) {esat::DrawSprite(g_bush2_sprite, p->info.position.x, p->info.position.y);}
            }

            //collision player con bush
            PlayerReset(pPlayer, &p->info);

            //bush collision con las estructuras
            ChangeDirectionPlatform(&p->info, pPlatform_4);
            ChangeDirectionPlatform(&p->info, pPlatform_3);
            ChangeDirectionPlatform(&p->info, pPlatform_2);

        }

    }
}

//--------------------------------------------------------------------------------------------------------------------

void InitBall(){

    CreateListEnemies(&stackBall);
    srand(time(NULL));

    for(int i = 0; i < numEnemies; i++) {

        int startPos = rand()%kWindowHeight-200;
        int startDir = rand()%4;

        g_Ball.position.x = 50;
        g_Ball.position.y = startPos;
        g_Ball.size.x = 65;
        g_Ball.size.y = 52;
        g_Ball.speed = 3;
        g_Ball.speedY = 3;
        g_Ball.direction = startDir;
        g_Ball.active = true;
        g_Ball.sprite = g_ball1_sprite;
        InsertListEnemies(&stackBall, g_Ball);
    }
}

void ModifyStackBall(TNodeEnemies **list){

    srand(time(NULL));
    int RandNum = rand()%kWindowHeight;
    
	TNodeEnemies *p;
	if(!IsemptyListEnemies(*list)){
		for(p=*list;p!=nullptr;p=p->prox){ 

            //Posibles direcciones del ball
            moveEnemy(&p->info);

            //Si el ball pasa de los distintos bordes del mapa
            ChangePosition(p->info.position, kWindowWidth, kWindowHeight);

            //Limite del mapa parte inferior y superior del ball
            ChangeDirection(p->info.position, kWindowHeight, p->info.direction);

            if(p->info.active){
                esat::DrawSprite(p->info.sprite, p->info.position.x, p->info.position.y);
                ++animation3%=60;
                if (animation3<10)                  {p->info.sprite = g_ball1_sprite;}
                if (animation3>=20 && animation3<60) {p->info.sprite = g_ball2_sprite;}
            }

            //collision player con ball
            PlayerReset(pPlayer, &p->info);

            //ball collision con las estructuras
            ChangeDirectionPlatform(&p->info, pPlatform_4);
            ChangeDirectionPlatform(&p->info, pPlatform_3);
            ChangeDirectionPlatform(&p->info, pPlatform_2);

        }
    }
}

//--------------------------------------------------------------------------------------------------------------------

void InitBird(int numBirds){
    CreateListEnemies(&stackBird);
    srand(time(NULL));

    for(int i = 0; i < numEnemies; i++) {
        
        int startPos = rand()%4;

        int numPosX;
        if (rand() % 2 == 0) {
            numPosX = 10;
        } else {
            numPosX = kWindowWidth - 70;
        }

        if (startPos == 0) {startPos = 50;} 
            else if(startPos == 1){startPos = 200;} 
            else if (startPos == 2){startPos = 300;} 
            else {startPos = 600;}

        g_Bird.position.x = numPosX;
        g_Bird.position.y = startPos;
        g_Bird.size.x = 65;
        g_Bird.size.y = 52;
        g_Bird.speed = 3;
        g_Bird.speedY = 5;
        g_Bird.direction = 5;
        g_Bird.active = true;
        g_Bird.startDirection = true;
        g_Bird.topDirection = false;
        g_Bird.sprite = g_bird_left_sprite;
        InsertListEnemies(&stackBird, g_Bird);
    }
}

void ModifyStackBird(TNodeEnemies **list){

    int numPos, numPosX;
    srand(time(NULL));
    int RandNum = rand()%kWindowHeight;
    int Startmove = rand()%25;
    int startPos = 200 - rand()%kWindowHeight;
    int flyDir, downDir;

    if (rand() % 2 == 0) {
        numPos = 5;
        numPosX = 10;
        flyDir = 2;
        downDir = 3;
    }else{
        numPos = 6;
        numPosX = kWindowWidth-70;
        flyDir = 1;
        downDir = 0;
    }
    
	TNodeEnemies *p;
	if(!IsemptyListEnemies(*list)){
		for(p=*list;p!=nullptr;p=p->prox){ 
            //Posibles direcciones del bird
            moveEnemy(&p->info);

            //Si el bird pasa de los distintos bordes del mapa
            ChangePosition(p->info.position, kWindowWidth, kWindowHeight);

            //Limite del mapa parte superior del bird
            if (p->info.position.y < 70){
                p->info.topDirection=true;
            }
            if(p->info.topDirection){
                p->info.direction = downDir;
                if(p->info.position.y > kWindowHeight-50){
                    p->info.active = false;
                }
            }

            //direccion vertical inicial, luego cambia a su otra direccion en diagonal cuando el cont=700
            if(p->info.startDirection){
                cont++;
                p->info.direction = numPos;
                if(p->info.position.y >= 668 ){ 
                    p->info.position.y = 668; // pos max
                }
                else if(p->info.position.y <= 60 ){ 
                    p->info.position.y = 60; // pos min
                }

            }/*else{
                if(p->info.position.y <= 100 ){ 
                    p->info.position.y = 100; // pos min
                }
                else if(p->info.position.y >= kWindowHeight-100 ){ 
                    p->info.position.y = kWindowHeight-100; // pos max
                }
            }*/

            if(cont == 700){
                p->info.startDirection = false;
                cont=0;
            }

            if(p->info.startDirection == false){
                if((p->info.direction == 5 || p->info.direction == 6)){
                    p->info.direction = flyDir;
                }
            }

            if(p->info.active){ 
                
                //dibuja bird
                if(p->info.direction==2 || p->info.direction==3) {

                    //switch(randColor){
                        /*case 0: */esat::DrawSprite(g_bird_left_sprite, p->info.position.x, p->info.position.y);
                        //case 1: esat::DrawSprite(g_wind1_right_green_sprite, p->info.position.x, p->info.position.y);
                    //}
                }else{
                    //switch(randColor){
                        /*case 0: */esat::DrawSprite(g_bird_right_sprite, p->info.position.x, p->info.position.y);
                        //case 1: esat::DrawSprite(g_wind1_left_green_sprite, p->info.position.x, p->info.position.y);
                    //}
                }

                //collision player con bird
                PlayerReset(pPlayer, &p->info);
            }

            if(p->info.active==false){ //cuando hay una colision
                
                drawExplosionSprites(p->info.position);

                if(contExp==8){ //cuando termina colision activo de nuevo el wind
                    p->info.active=true;
                    p->info.position.x = numPosX;
                    p->info.position.y = 200 - startPos;
                    p->info.direction = rand() % 5;
                    p->info.startDirection = true;
                    contExp=0;
                }
                
            }

        }
    }
}

//--------------------------------------------------------------------------------------------------------------------

void InitDustandFrog(){

    CreateListEnemies(&stackDust);
    srand(time(NULL));

    for(int i = 0; i < numEnemies; i++) {

        int startPos = rand()%kWindowHeight-200;
        int startDir = rand()%4;

        g_Dust.position.x = 50;
        g_Dust.position.y = startPos;
        g_Dust.size.x = 65;
        g_Dust.size.y = 52;
        g_Dust.speed = 3;
        g_Dust.speedY = 3;
        g_Dust.direction = startDir;
        g_Dust.active = true;
        g_Dust.sprite = g_dust_sprite;
        InsertListEnemies(&stackDust, g_Dust);
    }
}

void ModifyStackDustandFrog(TNodeEnemies **list){

    srand(time(NULL));
    int RandNum = rand()%kWindowHeight;
    
	TNodeEnemies *p;
	if(!IsemptyListEnemies(*list)){
		for(p=*list;p!=nullptr;p=p->prox){ 

            //Posibles direcciones del dust
            moveEnemy(&p->info);

            //Si el ball pasa de los distintos bordes del mapa
            ChangePosition(p->info.position, kWindowWidth, kWindowHeight);

            //Limite del mapa parte inferior y superior del dust
            ChangeDirection(p->info.position, kWindowHeight, p->info.direction);

            //MoveEnemyTowardsPlayer(&p->info, pPlayer->position);

            if(p->info.active){

                //dust
                if(levelCount == 4 || levelCount == 12){
                    esat::DrawSprite(p->info.sprite, p->info.position.x, p->info.position.y);
                }
                //frog
                if(levelCount == 7 || levelCount == 15){
                    esat::DrawSprite(g_frog_sprite, p->info.position.x, p->info.position.y);
                }
            }

            //collision player con dust
            PlayerReset(pPlayer, &p->info);
        }
    }
}

//--------------------------------------------------------------------------------------------------------------------

void InitCross(){

    CreateListEnemies(&stackCross);
    srand(time(NULL));

    for(int i = 0; i < numEnemies; i++) {

        int randomNumber = rand() % 4;
        int randY;
        bool randGravity;

        if (rand() % 2 == 0) {
            randGravity = true;
            randY = 2;
        }else{
            randGravity = false;
            randY = 1;
        }

        if (randomNumber == 0) {randomNumber = 0;} 
            else if(randomNumber == 1){randomNumber = 3;} 
            else if (randomNumber == 2){randomNumber = 7;} 
            else {randomNumber = 8;}

        int startPos = rand()%kWindowHeight-200;
        int startDir = rand()%4;

        g_Cross.position.x = 50;
        g_Cross.position.y = startPos;
        g_Cross.size.x = 65;
        g_Cross.size.y = 52;
        g_Cross.speed = 4;
        g_Cross.speedY = 0;
        g_Cross.direction = randomNumber;
        g_Cross.gravity = randGravity;
        g_Cross.localGravity = true;;
        g_Cross.active = true;
        g_Cross.cont;
        g_Cross.sprite = g_cross_sprite;
        InsertListEnemies(&stackCross, g_Cross);
    }
}

void ModifyStackCross(TNodeEnemies **list){

    srand(time(NULL));
    int RandNum = rand()%kWindowHeight;
    int randDir;
    bool randBool;

    int randomNumber = rand() % 4;
        int randY;
        bool randGravity;

        if (rand() % 2 == 0) {
            randGravity = true;
            randY = 2;
        }else{
            randGravity = false;
            randY = 1;
        }

        if (randomNumber == 0) {randomNumber = 0;} 
            else if(randomNumber == 1){randomNumber = 3;} 
            else if (randomNumber == 2){randomNumber = 7;} 
            else {randomNumber = 8;}

	TNodeEnemies *p;
	if(!IsemptyListEnemies(*list)){
		for(p=*list;p!=nullptr;p=p->prox){ 
            randDir = rand()%20;

            if(p->info.gravity){
                p->info.localGravity = true;
                p->info.position.y = p->info.position.y +1;
            }

            //Posibles direcciones del cross
            moveEnemy(&p->info);

            //Para que rebote con el suelo y luego vuelva a bajar 
            if(p->info.position.y > kWindowHeight-75){
                p->info.localGravity = false;
            }
            if(p->info.localGravity == false){
                p->info.cont++;
                p->info.gravity = false;
                p->info.position.y--;       
                if(p->info.cont==150){
                    p->info.gravity = true;
                    p->info.cont = 0;   
                } 
            }

            if(randDir == 5){
                randBool = true;
            }
            if(randBool && p->info.position.y < kWindowHeight/2){
                p->info.gravity = false;
                if(p->info.direction==7 || p->info.direction==1 || p->info.direction==0){
                    p->info.position.y = p->info.position.y - 2; 
                    p->info.position.x--; 
                    p->info.gravity = false;
                }else{
                    p->info.position.x = p->info.position.x + 1; 
                    p->info.gravity = true;
                    
                }
            } 

            //Parte superior
            if(p->info.position.y < 64){
                p->info.gravity = true;
            }

            //Si el cross pasa de los distintos bordes del mapa
            ChangePosition(p->info.position, kWindowWidth, kWindowHeight);

            if(p->info.active){
                esat::DrawSprite(p->info.sprite, p->info.position.x, p->info.position.y);
            }

            //cross collision con las estructuras
            ChangeDirectionPlatform(&p->info, pPlatform_4);
            ChangeDirectionPlatform(&p->info, pPlatform_3);
            ChangeDirectionPlatform(&p->info, pPlatform_2);

            //collision player con cross
            PlayerReset(pPlayer, &p->info);

            if(p->info.active==false){ //cuando hay una colision
                
               drawExplosionSprites(p->info.position);

                if(contExp==8){ //cuando termina colision activo de nuevo el wind
                    p->info.active=true;
                    p->info.position.x = 0;
                    p->info.position.y++;
                    p->info.direction = randomNumber;
                    contExp=0;
                }
                
            }

        }
    }
}