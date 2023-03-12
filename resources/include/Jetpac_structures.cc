//Platforms
void InitPlatforms(){

    //bottom platform
    pPlatform_1=(TPlatform*)malloc(1*sizeof(TPlatform));
    pPlatform_1->position.x = 0;
    pPlatform_1->position.y = kWindowHeight-32;
    pPlatform_1->size.x = 1120;
    pPlatform_1->size.y = 25;
    pPlatform_1->sprite = g_platform_bottom_sprite;

    //middle platform
    pPlatform_2=(TPlatform*)malloc(1*sizeof(TPlatform));
    pPlatform_2->position.x = (kWindowWidth/2)-32;
    pPlatform_2->position.y = (kWindowHeight/2)+50;
    pPlatform_2->size.x = 123;
    pPlatform_2->size.y = 26;
    pPlatform_2->sprite = g_platform_sprite;

    //left platform
    pPlatform_3=(TPlatform*)malloc(1*sizeof(TPlatform));
    pPlatform_3->position.x = 100;
    pPlatform_3->position.y = 300;
    pPlatform_3->size.x = 184;
    pPlatform_3->size.y = 27;
    pPlatform_3->sprite = g_platform2_sprite;

    //right platform
    pPlatform_4=(TPlatform*)malloc(1*sizeof(TPlatform));
    pPlatform_4->position.x = kWindowWidth-300;
    pPlatform_4->position.y = 250;
    pPlatform_4->size.x = 184;
    pPlatform_4->size.y = 27;
    pPlatform_4->sprite = g_platform3_sprite;
    
    
}

void DrawPlatforms(){

    esat::DrawSprite(pPlatform_1->sprite, pPlatform_1->position.x, pPlatform_1->position.y);
    esat::DrawSprite(pPlatform_2->sprite, pPlatform_2->position.x, pPlatform_2->position.y);
    esat::DrawSprite(pPlatform_3->sprite, pPlatform_3->position.x, pPlatform_3->position.y);
    esat::DrawSprite(pPlatform_4->sprite, pPlatform_4->position.x, pPlatform_4->position.y);
    
}

//Ships
void InitShip(){

    pShip_1=(TShip*)malloc(1*sizeof(TShip));
    pShip_1->position.x = pPlatform_3->position.x+70;
    pShip_1->position.y = pPlatform_3->position.y-57;
    pShip_1->size.x = 31;
    pShip_1->size.y = 53;
    pShip_1->active = true;
    pShip_1->speed = 6;

    switch(levelShip){
        case 0: pShip_1->sprite = g_ship_type1_1_sprite; break;
        case 1: pShip_1->sprite = g_ship_type2_1_sprite; break;
        case 2: pShip_1->sprite = g_ship_type3_1_sprite; break;
        case 3: pShip_1->sprite = g_ship_type4_1_sprite; break;
    }
    

    pShip_2=(TShip*)malloc(1*sizeof(TShip));
    pShip_2->position.x = pPlatform_2->position.x+30;
    pShip_2->position.y = pPlatform_2->position.y-57;
    pShip_2->size.x = 31;
    pShip_2->size.y = 53;
    pShip_2->active = true;
    pShip_2->speed = 6;

    switch(levelShip){
        case 0: pShip_2->sprite = g_ship_type1_2_sprite; break;
        case 1: pShip_2->sprite = g_ship_type2_2_sprite; break;
        case 2: pShip_2->sprite = g_ship_type3_2_sprite; break;
        case 3: pShip_2->sprite = g_ship_type4_2_sprite; break;
    }

    pShip_3=(TShip*)malloc(1*sizeof(TShip));
    pShip_3->position.x = pPlayer->position.x-100;
    pShip_3->position.y = pPlayer->position.y+30;
    pShip_3->size.x = 31;
    pShip_3->size.y = 53;
    pShip_3->active = true;
    pShip_3->speed = 6;

    switch(levelShip){
        case 0: pShip_3->sprite = g_ship_type1_3_sprite; break;
        case 1: pShip_3->sprite = g_ship_type2_3_sprite; break;
        case 2: pShip_3->sprite = g_ship_type3_3_sprite; break;
        case 3: pShip_3->sprite = g_ship_type4_3_sprite; break;
    }

    pShipFull=(TShip*)malloc(1*sizeof(TShip));
    pShipFull->position.x = pPlayer->position.x-100;
    pShipFull->position.y = pPlayer->position.y-75;
    pShipFull->size.x = 31;
    pShipFull->size.y = 53;
    pShipFull->active = false;
    pShipFull->speed = 1;

    switch(levelShip){
        case 0: pShipFull->sprite = g_ship_type1_full_sprite; break;
        case 1: pShipFull->sprite = g_ship_type2_full_sprite; break;
        case 2: pShipFull->sprite = g_ship_type3_full_sprite; break;
        case 3: pShipFull->sprite = g_ship_type4_full_sprite; break;
    }
}

void DrawShip(){

    if(pShip_1->active){
        esat::DrawSprite(pShip_1->sprite, pShip_1->position.x, pShip_1->position.y);
    }
    if(pShip_2->active){
        esat::DrawSprite(pShip_2->sprite, pShip_2->position.x, pShip_2->position.y);
    }
    if(pShip_2->active){
        esat::DrawSprite(pShip_3->sprite, pShip_3->position.x, pShip_3->position.y);
    }
    if(pShipFull->active){
        esat::DrawSprite(pShipFull->sprite, pShipFull->position.x, pShipFull->position.y);
    }

}

void MoveShip(){

    //Coger la parte de la nave 1 y dejarla en posicion ------------------------------------------------------------------
    if(pShip_2->position.x == 720 || (pShip_2->position.x == 735)){ //Para que deje primero la parte 2 de la nave

        if(CollisionPlayerShip1(pPlayer, pShip_1) && shipWithPlayer ){ 
            pShip_1->position.x = pPlayer->position.x + pShip_1->size.x;
            pShip_1->position.y = pPlayer->position.y + pShip_1->size.y;
    
            if(pPlayer->position.x > 690 && pPlayer->position.x < 785){
                shipWithPlayer = false;
                pShip_1->position.x = 738;
                pShip_1->position.y = pShip_1->position.y + 20;
            }
        }
    }

    //Baja la nave hasta el suelo
    if(pShip_1->position.x == 738 && shipWithPlayer == false){
        pShip_1->position.y = pShip_1->position.y + 2;
        if(pShip_1->position.y >= kWindowHeight-193){pShip_1->position.y=kWindowHeight-193; }
    }
    
    //Coger la parte de la nave 2 y dejarla en posicion ------------------------------------------------------------------
    if(CollisionPlayerShip2(pPlayer, pShip_2) && shipWithPlayer2){ 
        pShip_2->position.x = pPlayer->position.x + pShip_2->size.x;
        pShip_2->position.y = pPlayer->position.y + pShip_2->size.y;
    
        if(pPlayer->position.x > 690 && pPlayer->position.x < 785){
            shipWithPlayer2 = false;
            
            switch(levelShip){
                case 0: pShip_2->position.x = 720; break;
                case 1: pShip_2->position.x = 735; break;
                case 2: pShip_2->position.x = 720; break;
                case 3: pShip_2->position.x = 720; break;
            }
            
            pShip_2->position.y = pShip_2->position.y + 20;
        }
    }
    
    //Baja la nave hasta el suelo
    if(((pShip_2->position.x == 720) || (pShip_2->position.x == 735)) && shipWithPlayer2 == false){
        pShip_2->position.y = pShip_2->position.y + 3;
    }
    if(pShip_2->position.y >= kWindowHeight-140){pShip_2->position.y=kWindowHeight-140;}

    //Cambiar los sprites separados a uno unico
    if(pShip_2->position.y==kWindowHeight-140 && pShip_1->position.y==kWindowHeight-193){
        pShip_1->active=false;
        pShip_2->active=false;
        pShip_3->sprite=false;
        pShipFull->active=true;
    }

    if(pShipFull->active){
        CollisionPlayerFlyShip(pPlayer, pShipFull);
    }

    //Despega toda la nave
    if(changeSpriteCount==5 && shipFlying){

        pFuel->position.x = kWindowWidth + 200;
        
        pPlayer->position.y = kWindowHeight + 200;
        ++animation%=25;
        pShipFull->position.y = pShipFull->position.y - pShipFull->speed;
    
        if (animation<5)                  {esat::DrawSprite(g_fire1_sprite, pShipFull->position.x, pShipFull->position.y+165);}
        if (animation>=10 && animation<15) {esat::DrawSprite(g_fire2_sprite, pShipFull->position.x, pShipFull->position.y+165);}
        if (animation>=20 && animation<25){
            switch(levelShip){
                case 0: esat::DrawSprite(g_ship_type1_full_sprite, pShipFull->position.x, pShipFull->position.y); break;
                case 1: esat::DrawSprite(g_ship_type2_full_sprite, pShipFull->position.x, pShipFull->position.y); break;
                case 2: esat::DrawSprite(g_ship_type3_full_sprite, pShipFull->position.x, pShipFull->position.y); break;
                case 3: esat::DrawSprite(g_ship_type4_full_sprite, pShipFull->position.x, pShipFull->position.y); break;
            }
        }

        if(pShipFull->position.y == -100){
            changeSpriteCount = 0;
            switch(levelShip){
                case 0: pShipFull->sprite = g_ship_type1_full_sprite; break;
                case 1: pShipFull->sprite = g_ship_type2_full_sprite; break;
                case 2: pShipFull->sprite = g_ship_type3_full_sprite; break;
                case 3: pShipFull->sprite = g_ship_type4_full_sprite; break;
            }
            shipdown=true;
        }
    }

    //Aterrizar toda lanave
    if(shipdown){

        ++animation%=15;
        pShipFull->position.y = pShipFull->position.y + pShipFull->speed;

        if (animation<5)                  {esat::DrawSprite(g_fire1_sprite, pShipFull->position.x, pShipFull->position.y+165);}
        if (animation>=10 && animation<15) {esat::DrawSprite(g_fire2_sprite, pShipFull->position.x, pShipFull->position.y+165);} 

        if(pShipFull->position.y >= kWindowHeight-195){
            pShipFull->position.y = kWindowHeight-195;
            shipdown=false;
            pPlayer->position.y = kWindowHeight-120;
            pPlayer->position.x = kWindowWidth-300;

            
            shipFlying = false;
            levelCount = levelCount + 1;
            if(levelCount==4){
                levelShip = 1;
            }
            if(levelCount==8){
                levelShip = 2;
            }
            if(levelCount==12){
                levelShip = 3;
            }
            if(levelCount==16){
                levelShip = 0;
                levelCount = 0;
            }
            InitShip();
            InitFuel();
        }
    }
    
}


