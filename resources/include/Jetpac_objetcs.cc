
//Fuel
void InitFuel(){

    srand(time(NULL));

    int numRandX = rand()%kWindowWidth;
    int numRandY = rand()%200;
    
    pFuel=(TObjects*)malloc(1*sizeof(TObjects));
    pFuel->position.x = numRandX;
    pFuel->position.y = numRandY;
    pFuel->size.x = 64;
    pFuel->size.y = 37;
    pFuel->gravity = 2;
    pFuel->speedY = 2;
    pFuel->active = false;
    pFuel->sprite = g_fuel_sprite;

}

void DrawFuel(){

    srand(time(NULL));
    //Para que apareza cuando estén las piezas de las naves juntas, aparece y va bajando
    if(pShipFull->active == true){

        pFuel->active = true;
        if(pFuel->active){
            esat::DrawSprite(pFuel->sprite, pFuel->position.x, pFuel->position.y);
            pFuel->position.y = pFuel->position.y + pFuel->gravity;
        }
    }
}

void MoveFuel(){

    srand(time(NULL));

    int num2RandX = rand()%kWindowWidth;

    CollisionPlatformObject(pFuel, pPlatform_4);
    CollisionPlatformObject(pFuel, pPlatform_2);
    CollisionPlatformObject(pFuel, pPlatform_3);

    //si colisiona el fuel con el player lo recoge
     if(CollisionFuelPlayer(pPlayer, pFuel) && fuelWithPlayer){ 
        pFuel->position.x = pPlayer->position.x +20;
        pFuel->position.y = pPlayer->position.y +30;
    
        if(pPlayer->position.x > 700 && pPlayer->position.x < 740){
            fuelWithPlayer = false;
            pFuel->position.x = 720;
            pFuel->position.y = pFuel->position.y + 40;
            pFuel->gravity = 2;
        }
    }

    //Baja el fuel hasta el suelo
    if(pFuel->position.x == 720 && fuelWithPlayer == false){
        
        pFuel->position.y = pFuel->position.y + pFuel->gravity;
    }

    //para que se quede quieto en el suelo y detecte para rellenar la nave de fuel
    if(pFuel->position.y >= kWindowHeight-70){
        pFuel->position.y=kWindowHeight-70;
    } 

    //Rellenar fuel sprite
    if(pShipFull->active == true && pFuel->position.x == 720 && pFuel->position.y==kWindowHeight-70){
            
        pFuel->position.x = num2RandX-32;
        //printf("%d", num2RandX);
        pFuel->position.y = -600;
  
        //printf("%d\n", changeSpriteCount);

        switch(changeSpriteCount){
            case 0: switch(levelShip){
                        case 0: pShipFull->sprite = g_ship_type1_fuel1_sprite; changeSpriteCount=1; break;
                        case 1: pShipFull->sprite = g_ship_type2_fuel1_sprite; changeSpriteCount=1; break;
                        case 2: pShipFull->sprite = g_ship_type3_fuel1_sprite; changeSpriteCount=1; break;
                        case 3: pShipFull->sprite = g_ship_type4_fuel1_sprite; changeSpriteCount=1; break;
                    } break;
            case 1: switch(levelShip){
                        case 0: pShipFull->sprite = g_ship_type1_fuel2_sprite; changeSpriteCount=2; break;
                        case 1: pShipFull->sprite = g_ship_type2_fuel2_sprite; changeSpriteCount=2; break;
                        case 2: pShipFull->sprite = g_ship_type3_fuel2_sprite; changeSpriteCount=2; break;
                        case 3: pShipFull->sprite = g_ship_type4_fuel2_sprite; changeSpriteCount=2; break;
                    } break;
            case 2: switch(levelShip){
                        case 0: pShipFull->sprite = g_ship_type1_fuel3_sprite; changeSpriteCount=3; break;
                        case 1: pShipFull->sprite = g_ship_type2_fuel3_sprite; changeSpriteCount=3; break;
                        case 2: pShipFull->sprite = g_ship_type3_fuel3_sprite; changeSpriteCount=3; break;
                        case 3: pShipFull->sprite = g_ship_type4_fuel3_sprite; changeSpriteCount=3; break;
                    } break;
            case 3: switch(levelShip){
                        case 0: pShipFull->sprite = g_ship_type1_fuel4_sprite; changeSpriteCount=4; break;
                        case 1: pShipFull->sprite = g_ship_type2_fuel4_sprite; changeSpriteCount=4; break;
                        case 2: pShipFull->sprite = g_ship_type3_fuel4_sprite; changeSpriteCount=4; break;
                        case 3: pShipFull->sprite = g_ship_type4_fuel4_sprite; changeSpriteCount=4; break;
                    } break;
            case 4: switch(levelShip){
                        case 0: pShipFull->sprite = g_ship_type1_fuel5_sprite; changeSpriteCount=5; break;
                        case 1: pShipFull->sprite = g_ship_type2_fuel5_sprite; changeSpriteCount=5; break;
                        case 2: pShipFull->sprite = g_ship_type3_fuel5_sprite; changeSpriteCount=5; break;
                        case 3: pShipFull->sprite = g_ship_type4_fuel5_sprite; changeSpriteCount=5; break;
                    } break;

        }
    }

}

void InitObject(){
    srand(time(NULL));

    int numRandX = rand()%kWindowWidth;
    int numRandY = rand()%200;
    
    pObject=(TObjects*)malloc(1*sizeof(TObjects));
    pObject->position.x = numRandX;
    pObject->position.y = -400;
    pObject->size.x = 64;
    pObject->size.y = 37;
    pObject->gravity = 2;
    pObject->active = false;
    pObject->sprite = g_nuclear_sprite;

}

void MoveObject(){
    srand(time(NULL));
    int numRandX = rand()%kWindowWidth;
    int numRandY = rand()%200;


    CollisionPlatformObject(pObject, pPlatform_4);
    CollisionPlatformObject(pObject, pPlatform_2);
    CollisionPlatformObject(pObject, pPlatform_3);

    if(pObject->position.y > kWindowHeight-70){
        pObject->position.y = pObject->position.y -2 ;
    }

    //Para que apareza cuando estén las piezas de las naves juntas, aparece y va bajando
    if(pShipFull->active == true){

        pObject->active = true;
    }
        if(pObject->active==true){

            switch (randobject){
                case 0: esat::DrawSprite(pObject->sprite, pObject->position.x, pObject->position.y); break;
                case 1: esat::DrawSprite(g_diamond_red_sprite, pObject->position.x, pObject->position.y); break;
                case 2: esat::DrawSprite(g_gold_sprite, pObject->position.x, pObject->position.y); break;
                case 3: esat::DrawSprite(g_triangle_sprite, pObject->position.x, pObject->position.y); break;
            }

            if(randobject==1){
                ++animation%=25;
                if (animation<2)                  {esat::DrawSprite(g_diamond_blue_sprite, pObject->position.x, pObject->position.y);}
                if (animation>=2 && animation<10) {esat::DrawSprite(g_diamond_red_sprite, pObject->position.x, pObject->position.y);}
                if (animation>=10 && animation<17) {esat::DrawSprite(g_diamond_purple_sprite, pObject->position.x, pObject->position.y);}
                if (animation>=17 && animation<25) {esat::DrawSprite(g_diamond_sprite, pObject->position.x, pObject->position.y);}
            }
            pObject->position.y = pObject->position.y + pObject->gravity;
        }

        if(CollisionObjectPlayer(pPlayer, pObject)==true){
            
            randobject = randobject +1;
            pObject->position.y = -400;
            pObject->position.x = numRandX;
            pObject->gravity = 2;
            score1 = score1 + 200;
        }

        if(randobject==4){
            randobject=0;
        }
    
}
