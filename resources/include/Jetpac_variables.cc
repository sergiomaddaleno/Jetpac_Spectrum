struct TCoords{
  int x,y;
};

struct TBullet{
  TCoords position, size;
  int groupNumber;
  int speed;
  bool leftdirection;
  bool firstbullet; //Para saber si es la primera bala de un grupo y borrarla
  bool active;
  esat::SpriteHandle sprite;
};

struct TPlayer{
  TCoords position, size;
  TBullet bullet;
  bool alive;
  int speed;
  int gravity;
  bool directionLeft;
  bool movePlayer;
  bool inmortal;
  esat::SpriteHandle sprite;
};

struct TPlatform{
  TCoords position;
  TCoords size;
  esat::SpriteHandle sprite; 
};

struct TShip{
  TCoords position, size;
  int speed;
  bool active;
  esat::SpriteHandle sprite; 
};

struct TObjects{
  TCoords position, size;
  float speedY;
  float gravity;
  bool active;
  esat::SpriteHandle sprite;
};

struct TEnemies{
  TCoords position, size;
  int numb; //numero de enemigo secuencial
  float speedY;
  float speed;
  bool active;
  bool collision;
  int direction;
  bool gravity;
  bool localGravity;
  bool startDirection;
  bool topDirection;
  int cont; //para control de mov de cada enemigo
  esat::SpriteHandle sprite;
};

const int kWindowWidth=224*5, kWindowHeight=256*3;
unsigned char fps=60;
double current_time,last_time;

FILE *fSave;

bool gamestart=false, gameselection=false; 
int Loading=0, levelCount=0, levelShip=0;
int score1=0, life1=3;
bool resetGame=false;
int numEnemies=5;
int animation, animation2, animation3, animation4, animationExp=false;
bool shipWithPlayer=false, shipWithPlayer2=false, fuelWithPlayer=false, objectWithPlayer=false;
int changeSpriteCount=0;
int playerLife=3;
bool shipdown=false, shipFlying=false;
int numOfWind=5;
bool bulletShot=false; //Controla cuando se ha disparado una bala (se ha cargado en una stack)
int contExp, contExp2; //contador para a animar la explosion
int cont, cont2, cont3; //cuando muere el player por algun enemigo
int randobject;

//sound variables
bool getitem=false;
bool enemyDies=false;

esat::SpriteHandle g_player1_left_sprite, g_player2_left_sprite, g_player3_left_sprite, g_player4_left_sprite,
                   g_player1_right_sprite, g_player2_right_sprite, g_player3_right_sprite ,g_player4_right_sprite,
                   g_player1_fly_left_sprite, g_player2_fly_left_sprite, g_player3_fly_left_sprite, g_player4_fly_left_sprite,
                   g_player1_fly_right_sprite, g_player2_fly_right_sprite, g_player3_fly_right_sprite, g_player4_fly_right_sprite,

                   g_platform_sprite, g_platform2_sprite, g_platform3_sprite, g_platform_bottom_sprite, 

                   g_ship_type1_1_sprite, g_ship_type1_2_sprite, g_ship_type1_3_sprite, g_ship_type1_full_sprite,
                   g_ship_type2_1_sprite, g_ship_type2_2_sprite, g_ship_type2_3_sprite, g_ship_type2_full_sprite,
                   g_ship_type3_1_sprite, g_ship_type3_2_sprite, g_ship_type3_3_sprite, g_ship_type3_full_sprite,
                   g_ship_type4_1_sprite, g_ship_type4_2_sprite, g_ship_type4_3_sprite, g_ship_type4_full_sprite,
                   
                   g_fuel_sprite, g_nuclear_sprite, g_diamond_sprite, g_diamond_red_sprite, g_diamond_purple_sprite, g_diamond_blue_sprite,
                   g_gold_sprite, g_triangle_sprite,

                   g_1up_sprite, g_2up_sprite, g_HI_sprite, g_Life_sprite, g_loading_screen_1, g_loading_screen_2, g_game_selection, g_game_selection_1,

                   g_ship_type1_fuel1_sprite, g_ship_type1_fuel2_sprite, g_ship_type1_fuel3_sprite, g_ship_type1_fuel4_sprite, g_ship_type1_fuel5_sprite,
                   g_ship_type2_fuel1_sprite, g_ship_type2_fuel2_sprite, g_ship_type2_fuel3_sprite, g_ship_type2_fuel4_sprite, g_ship_type2_fuel5_sprite,
                   g_ship_type3_fuel1_sprite, g_ship_type3_fuel2_sprite, g_ship_type3_fuel3_sprite, g_ship_type3_fuel4_sprite, g_ship_type3_fuel5_sprite,
                   g_ship_type4_fuel1_sprite, g_ship_type4_fuel2_sprite, g_ship_type4_fuel3_sprite, g_ship_type4_fuel4_sprite, g_ship_type4_fuel5_sprite,
                   
                   g_bullet_small_white_sprite, g_bullet_middle_white_sprite, g_bullet_long_white_sprite,
                   g_bullet_small_red_sprite, g_bullet_middle_red_sprite, g_bullet_long_red_sprite,
                   g_bullet_small_purple_sprite, g_bullet_middle_purple_sprite, g_bullet_long_purple_sprite,
                   
                   g_fire1_sprite, g_fire2_sprite,
                   
                   g_wind1_left_sprite, g_wind1_right_sprite, g_wind2_left_sprite, g_wind2_right_sprite,
                   g_wind1_left_green_sprite, g_wind1_right_green_sprite, g_wind2_left_green_sprite, g_wind2_right_green_sprite,

                   g_bush1_sprite, g_bush2_sprite, g_ball1_sprite, g_ball2_sprite, 

                   g_bird_left_sprite, g_bird_right_sprite,

                   g_dust_sprite,

                   g_cross_sprite,

                   g_millenniumFalcon_right_sprite, g_millenniumFalcon_left_sprite,

                   g_frog_sprite, g_sprite, g_pp_sprite,

                   g_explosion1_sprite, g_explosion2_sprite, g_explosion3_sprite, g_explosion1_2_sprite, g_explosion2_2_sprite, g_explosion3_2_sprite,
                   g_explosion3_empty1_sprite, g_explosion3_empty2_sprite
                   
                   ;

TEnemies g_Wind, g_Bush, g_Ball, g_Dust, g_Bird, g_Cross;
TBullet g_Bullet, *pBullet;
TPlatform *pPlatform_1, *pPlatform_2, *pPlatform_3, *pPlatform_4;
TPlayer *pPlayer=nullptr;
TShip *pShip_1, *pShip_2, *pShip_3, *pShipFull;
TObjects *pFuel, *pObject;



