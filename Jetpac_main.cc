
#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>


#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


#include "resources/include/Jetpac_variables.cc"

#include "resources/include/TListas.cc"
#include "resources/include/TPilas.cc"

#include "resources/include/Jetpac_extra.cc"
#include "resources/include/Jetpac_sprites.cc"
#include "resources/include/Jetpac_collisions.cc"
#include "resources/include/Jetpac_objetcs.cc"
#include "resources/include/Jetpac_structures.cc"
#include "resources/include/Jetpac_interface.cc"

#include "resources/include/Jetpac_enemies.cc"
#include "resources/include/Jetpac_player.cc"


#include <esat_extra/soloud/soloud.h>
#include <esat_extra/soloud/soloud_wav.h>

using namespace SoLoud;

SoLoud::Soloud gSoloud;
SoLoud::Wav introWave;
SoLoud::Wav shootWave;
SoLoud::Wav enemyDiesWave;
SoLoud::Wav takeOffWave;
SoLoud::Wav landingWave;
SoLoud::Wav takeFuelWave;
SoLoud::Wav takeItemWave;
SoLoud::Wav fallObjectWave;

void InitAudio(){
    gSoloud.init();
    introWave.load("./resources/sound/intro.wav");
    shootWave.load("./resources/sound/shoot.wav");
    enemyDiesWave.load("./resources/sound/enemydies.wav");
    takeOffWave.load("./resources/sound/spacedep1.wav");
    landingWave.load("./resources/sound/spaceshipland.wav");
    takeFuelWave.load("./resources/sound/get_fuel.wav");
    takeItemWave.load("./resources/sound/get_item.wav");
    fallObjectWave.load("./resources/sound/fallobject.wav");
}

void InitParts(){

  InitAudio();

  InitSprites();
  InitPlatforms();
  InitPlayer();
  InitShip();
  InitFuel();
  InitObject();
  InitInterface();
  InitWindandFalcon();
  InitBush();
  InitBall();
  InitBird(5);
  InitDustandFrog();
  InitCross();
  
  InitBullets();

}

void DrawParts(){

  DrawPlatforms();
  DrawPlayer();
  DrawShip();
  DrawFuel();
  DrawInterface();

  if(levelCount==0 || levelCount==8  ||
     levelCount==6 || levelCount==14 ){ModifyStackWindandFalcon(&stackWind);}

  if(levelCount==1 || levelCount==9){ModifyStackBush(&stackBush);}

  if(levelCount==2 || levelCount==10){ModifyStackBall(&stackBall);}

  if(levelCount==3 || levelCount==11){ModifyStackBird(&stackBird);}

  if(levelCount==4 || levelCount==12  ||
     levelCount==7 || levelCount==15 ){ModifyStackDustandFrog(&stackDust);}

  if(levelCount==5 || levelCount==13){ModifyStackCross(&stackCross);}

}

void GameParts(){

  MovePlayer();
  MoveFuel();
  MoveObject();
  MoveShip();

  LoadBullets();
  ShowStackBullets(&stackBullet);

}

void GameStart(){

  LoadingScreen();
  if(Loading==200){ //200
   gameselection=true;
  }
  if(gamestart){
    DrawParts();
    GameParts();
  }
}

void SoundParts(){

  if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
    gSoloud.play((shootWave));
  }
  if(enemyDies == true){
    gSoloud.play((enemyDiesWave));
    enemyDies = false;
  }
}

int esat::main(int argc, char **argv) {
 
  esat::WindowInit(kWindowWidth,kWindowHeight);
  WindowSetMouseVisibility(true);

  InitParts();
  ReadGameData();
  
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

  	last_time = esat::Time();
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
   
    GameStart();
    WriteGameData();
    SoundParts();
    Loading++;

    esat::DrawEnd();

   do{
    current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    
   esat::WindowFrame();
  }

  ReleaseSprites();

  free(pShip_1);
  free(pShip_2);
  free(pShip_3);
  free(pShipFull);
  free(pFuel);
  free(pPlatform_1);
  free(pPlatform_2);
  free(pPlatform_3);
  free(pPlatform_4);
  free(pPlayer);

  esat::WindowDestroy();

  return 0;
}

