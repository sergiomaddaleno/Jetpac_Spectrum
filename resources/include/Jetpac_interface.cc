
void InitInterface(){
    
    char score[10];
    char life[10];
    esat::DrawSetTextFont("./resources/font/Jetpac.ttf");
    esat::DrawSetTextSize(30.0f);
}

void DrawInterface(){

    esat::DrawSprite(g_1up_sprite, 100, 3);
    esat::DrawSprite(g_HI_sprite, (kWindowWidth/2)-25, 3);
    esat::DrawSprite(g_2up_sprite, kWindowWidth-180, 3);
    esat::DrawSprite(g_Life_sprite, 232, 3);

    char score[10];
    int i=score1;
    itoa(i,score,10);

    char life[10];
    int j=life1;
    itoa(j,life,10);

    esat::DrawSetFillColor(204, 204, 0); 
    esat::DrawText(100, 50, score); //score player 1

    esat::DrawText(kWindowWidth-180, 50, score); //score player 2
    esat::DrawText((kWindowWidth/2)-25, 50, score); //High score

    esat::DrawSetFillColor(255, 255, 255); 
    esat::DrawText(200, 24, life); //life
    
    //game Over
    if(pPlayer->alive==false){
    
        if(playerLife == 0){
            esat::DrawSetFillColor(255, 0, 0);
            esat::DrawText(kWindowWidth/2-70, kWindowHeight/2-100, "GAME OVER");
            pPlayer->position.x = kWindowWidth+500;
        }
    }
}

void LoadingScreen(){
    
    if(gamestart==false){
        esat::DrawSprite(g_loading_screen_1, 170, 100);
        esat::DrawSprite(g_pp_sprite, 20, kWindowHeight-120);
        esat::DrawText(140, kWindowHeight-60, "Recreated   by   Sergio   Madaleno");
        ++animation3%=25; 
        if (animation3>=20 && animation3<25) {esat::DrawSprite(g_loading_screen_2, 338, 244);}
    }
    
    if(gameselection){
        esat::DrawSprite(g_game_selection, 170, 100);
        ++animation%=25;
        if (animation>=20 && animation<25) {esat::DrawSprite(g_game_selection_1, 282, 220);}

        if(esat::IsKeyDown('1')){

            gamestart=true;
            gameselection=false;
        }
    }
}
