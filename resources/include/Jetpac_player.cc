TStack *stackBullet; 

void InitPlayer(){

    pPlayer=(TPlayer*)malloc(1*sizeof(TPlayer));

    pPlayer->position.x = kWindowWidth-300;
    pPlayer->position.y = kWindowHeight-120;
    pPlayer->size.x = 56;
    pPlayer->size.y = 71;
    pPlayer->alive = true;
    pPlayer->speed = 3; //3
    pPlayer->gravity = 6;
    pPlayer->directionLeft = true;
    pPlayer->movePlayer = true;
    pPlayer->inmortal = false;

    pPlayer->sprite = g_player1_left_sprite;
}

void DrawPlayer(){

    //Dibujado de sprite posicion principal
    if(pPlayer->alive){
        esat::DrawSprite(pPlayer->sprite, pPlayer->position.x, pPlayer->position.y);
    }else{
        drawExplosionSprites(pPlayer->position);
    }

    if(pPlayer->movePlayer){
    //Animaciones del sprite del jugador
        if (esat::IsKeyPressed('A')){
            pPlayer->directionLeft = true;

            ++animation%=25;
           if (pPlayer->alive == true){
            if (animation<2)                  {pPlayer->sprite =  g_player1_left_sprite;}
            if (animation>=2 && animation<10) {pPlayer->sprite =  g_player2_left_sprite;}
            if (animation>=10 && animation<17) {pPlayer->sprite =  g_player3_left_sprite;}
            if (animation>=17 && animation<25) {pPlayer->sprite =  g_player4_left_sprite;} 
           }
        }

        if (esat::IsKeyPressed('D')){
            pPlayer->directionLeft = false;

            ++animation%=25;
           if (pPlayer->alive == true){
            if (animation<2)                  {pPlayer->sprite =  g_player1_right_sprite;}
            if (animation>=2 && animation<10) {pPlayer->sprite =  g_player2_right_sprite;}
            if (animation>=10 && animation<17) {pPlayer->sprite =  g_player3_right_sprite;}
            if (animation>=17 && animation<25) {pPlayer->sprite =  g_player4_right_sprite;} 
           }
        }

        //Animacion de volar hacia la izquierda
        if (esat::IsKeyPressed('W') && pPlayer->directionLeft == true){
            ++animation%=25;
    
           if (pPlayer->alive == true){
            if (animation<2)                  {pPlayer->sprite =  g_player1_fly_left_sprite;}
            if (animation>=2 && animation<10) {pPlayer->sprite =  g_player2_fly_left_sprite;}
            if (animation>=10 && animation<17) {pPlayer->sprite =  g_player3_fly_left_sprite;}
            if (animation>=17 && animation<25) {pPlayer->sprite =  g_player4_fly_left_sprite;}
           }
        }

        //Animacion de volar hacia la derecha
        if (esat::IsKeyPressed('W') && pPlayer->directionLeft == false){
            ++animation%=25;
    
           if (pPlayer->alive == true){
            if (animation<2)                  {pPlayer->sprite = g_player1_fly_right_sprite;}
            if (animation>=2 && animation<10) {pPlayer->sprite = g_player2_fly_right_sprite;}
            if (animation>=10 && animation<17) {pPlayer->sprite = g_player3_fly_right_sprite;}
            if (animation>=17 && animation<25) {pPlayer->sprite = g_player4_fly_right_sprite;}
           }
        }
    
        //-------------------------------------------------------------------------------------------

        //Animation explosion player
        if((pPlayer->position.y >=kWindowHeight-150 && esat::IsKeyPressed('W')) || CollisionPlatform(pPlayer, pPlatform_2) ||
            CollisionPlatform(pPlayer, pPlatform_3) || CollisionPlatform(pPlayer, pPlatform_4)){
            animationExp=true;
        }

        if(animationExp && pPlayer->directionLeft){

            pPlayer->position.y = pPlayer->position.y-5;
            esat::DrawSprite(g_explosion3_2_sprite, pPlayer->position.x+25, pPlayer->position.y+40);
            animationExp=false;
        }

        if(animationExp && pPlayer->directionLeft==false){

            pPlayer->position.y = pPlayer->position.y-5;
            esat::DrawSprite(g_explosion3_2_sprite, pPlayer->position.x-25, pPlayer->position.y+40);
            animationExp=false;
        }
    }
}

void MovePlayer(){

    //Guardar la ultima pos del player
    TCoords oldPosition = pPlayer->position;
    if(pPlayer->movePlayer){
        // Movimiento del player
        if (esat::IsKeyPressed('W')){
            pPlayer->position.y = pPlayer->position.y - pPlayer->speed;

        }else{
            pPlayer->position.y = pPlayer->position.y + pPlayer->gravity;

            //Superficie solida de la plataforma de abajo
            if((pPlayer->position.y + pPlayer->size.y) >= (pPlatform_1->position.y)){

                pPlayer->position.y = pPlayer->position.y - 6;
            }  
        }
        if (esat::IsKeyPressed('A')){
            pPlayer->position.x = pPlayer->position.x - pPlayer->speed;
        } 

        if (esat::IsKeyPressed('D')){
            pPlayer->position.x = pPlayer->position.x + pPlayer->speed;
        }

        CollisionPlatform(pPlayer, pPlatform_2);
        CollisionPlatform(pPlayer, pPlatform_3);
        CollisionPlatform(pPlayer, pPlatform_4);

        //Si el player pasa de los distintos bordes del mapa
        ChangePosition(pPlayer->position, kWindowWidth, kWindowHeight);

        //Limite del mapa parte superior del player
        if (pPlayer->position.y < 52){
            pPlayer->position.y = 53;
        }
    }
}

//Bullet----------------------------------------------------------------------------------------------------

void HandleBulletCollision(TBullet &bullet, TNodeEnemies *enemystack, int &contExp) {
    srand(time(NULL));
    
    TNodeEnemies* p;
    for (p = enemystack; p != nullptr; p = p->prox) {
        //printf("bullet %d %d %d %d\n", p->info.numb, p->info.cont, p->info.active, p->info.collision);    
        
        if(p->info.active == false && p->info.cont==0){ //provisional para resolver un bug
            p->info.active = true;}
        if(p->info.active && p->info.cont==0){
        
            if (BoxCollision(bullet.position.x, bullet.position.y,
                              bullet.size.x, bullet.size.y,
                              p->info.position.x, p->info.position.y - 36, // ajuste de la y
                              p->info.size.x, p->info.size.y)) {
                p->info.active = false;
                p->info.cont = 1;
                drawExplosionSprites(p->info.position);
                enemyDies = true; //sound
            }
        }
        if(p->info.cont >= 1){
            p->info.cont++;

            if (p->info.cont == 9) {// reactivate wind after explosion animation
                p->info.active = true;
                p->info.cont = 0;
                score1 = score1+200;
            }           
        }
        
    }

   /*TNodeEnemies* p;
    for (p = enemystack; p != nullptr; p = p->prox) {
        printf("entro %d %d %d\n", p->info.cont, p->info.active, p->info.collision);
        if (BoxCollision(bullet.position.x, bullet.position.y,
                          bullet.size.x, bullet.size.y,
                          p->info.position.x, p->info.position.y - 36, // ajuste de la y
                          p->info.size.x, p->info.size.y)) {
            p->info.active = false;
            
            drawExplosionSprites(p->info.position);

            p->info.cont++;
            if (p->info.cont == 8) {// reactivate wind after explosion animation
                p->info.position.x = 0;
                p->info.position.y = 70 + rand() % (kWindowHeight - 70);
                p->info.direction = rand() % 4;
                p->info.cont = 0;
                score1 = score1+200;
            }
            if (p->info.cont == 2) {
                printf("hola");
                p->info.active = true;
            }
        }
    }*/
}

void InitBullets(){

    CreateStack(&stackBullet);

    g_Bullet.groupNumber = 1;
    g_Bullet.speed = 15;
    g_Bullet.leftdirection = true;
    g_Bullet.firstbullet= false;
    g_Bullet.size.x = 49;
    g_Bullet.size.y = 3;

}

void ShowStackBullets(TNode **lista){
    TNode *p;

    if(!IsemptyList(*lista)){
        for(p=*lista;p!=nullptr;p=p->prox){

            if(p->info.leftdirection==true){

                p->info.position.x = p->info.position.x - p->info.speed; //mueve bala izq
                if((p->info.position.x > 0) && (p->info.position.x < pPlayer->position.x)){ 
                    //Para que no pinte las balas detras del jugador
                    esat::DrawSprite(p->info.sprite, p->info.position.x, p->info.position.y+31);
                }
            }else{ // Bala va a la derech, Para que no pinte las balas detras del jugador

                p->info.position.x = p->info.position.x + p->info.speed; //mueve bala derecha
                if((p->info.position.x > 0) && (p->info.position.x > pPlayer->position.x + 45)){
                    esat::DrawSprite(p->info.sprite, p->info.position.x, p->info.position.y+34);
                }
            }  

            if(p->info.firstbullet){
                //Llamo a la funcion de colision con los enemigos
                HandleBulletCollision(p->info, stackWind, contExp); 
                HandleBulletCollision(p->info, stackBush, contExp);  
                HandleBulletCollision(p->info, stackBall, contExp); 
                HandleBulletCollision(p->info, stackBird, contExp); 
                HandleBulletCollision(p->info, stackDust, contExp); 
                HandleBulletCollision(p->info, stackCross, contExp); 

                //ChangePosition(p->info.position, kWindowWidth, kWindowHeight);
            }
        }
    }
}


void LoadBullets(){ //carga las 12 balas en la pila

    srand(time(NULL));
    int randColor = rand() %3;

    TNode *p;

    //Al pulsar el espacio cargo las 12 balas en la stackBullet
    if(pPlayer->movePlayer){
        if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){

            if(pPlayer->directionLeft == true){
                g_Bullet.position.x = pPlayer->position.x-120;
            }else{
                g_Bullet.position.x = pPlayer->position.x+50;
            }
            g_Bullet.groupNumber++;

            g_Bullet.firstbullet=true; // bala 1 ------------------------------
            g_Bullet.position.y = pPlayer->position.y;
            g_Bullet.leftdirection = pPlayer->directionLeft;

            switch(randColor){
                case 0: g_Bullet.sprite = g_bullet_long_white_sprite; break;
                case 1: g_Bullet.sprite = g_bullet_long_red_sprite; break;
                case 2: g_Bullet.sprite = g_bullet_long_purple_sprite; break;
            }
            InsertStack(&stackBullet, g_Bullet); 

            g_Bullet.firstbullet=false;
            if(g_Bullet.leftdirection){ // bala 2 ------------------------------
                g_Bullet.position.x = g_Bullet.position.x + 60;
            }else{
                g_Bullet.position.x = g_Bullet.position.x - 30;
            }

            switch(randColor){
                case 0: g_Bullet.sprite = g_bullet_middle_white_sprite; break;
                case 1: g_Bullet.sprite = g_bullet_middle_red_sprite; break;
                case 2: g_Bullet.sprite = g_bullet_middle_purple_sprite; break;
            }
            InsertStack(&stackBullet, g_Bullet);  

            for (int i = 2; i <= 11; i++) { // demás balas ---------------------------------
                if (g_Bullet.leftdirection) {
                    g_Bullet.position.x = g_Bullet.position.x + 30;
                } else {
                    g_Bullet.position.x = g_Bullet.position.x - 30;
                }

                if (i <= 6) {
                    switch(randColor){
                        case 0: g_Bullet.sprite = g_bullet_middle_white_sprite; break;
                        case 1: g_Bullet.sprite = g_bullet_middle_red_sprite; break;
                        case 2: g_Bullet.sprite = g_bullet_middle_purple_sprite; break;
                    }

                }else{
                    switch(randColor){
                        case 0: g_Bullet.sprite = g_bullet_small_white_sprite; break;
                        case 1: g_Bullet.sprite = g_bullet_small_red_sprite; break;
                        case 2: g_Bullet.sprite = g_bullet_small_purple_sprite; break;
                    }
                }
                InsertStack(&stackBullet, g_Bullet);
            }
        }
    }
   //Si el bullet pasa de los distintos bordes del mapa vaciamos cada stack
    p = SearchList(stackBullet, g_Bullet, actual);
    
    if(p!=nullptr && p->info.firstbullet == true && (p->info.position.x >= kWindowWidth+300 || p->info.position.x <= -300)){ 
        EmptyStack(&stackBullet);
    }

}






