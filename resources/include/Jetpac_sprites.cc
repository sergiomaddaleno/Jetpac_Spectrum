
void InitSprites(){
    //player sprites left
    g_player1_left_sprite=esat::SpriteFromFile("./resources/img/player_1_left.png");
    g_player2_left_sprite=esat::SpriteFromFile("./resources/img/player_2_left.png");
    g_player3_left_sprite=esat::SpriteFromFile("./resources/img/player_3_left.png");
    g_player4_left_sprite=esat::SpriteFromFile("./resources/img/player_4_left.png");

    //player sprites right
    g_player1_right_sprite=esat::SpriteFromFile("./resources/img/player_1_right.png");
    g_player2_right_sprite=esat::SpriteFromFile("./resources/img/player_2_right.png");
    g_player3_right_sprite=esat::SpriteFromFile("./resources/img/player_3_right.png");
    g_player4_right_sprite=esat::SpriteFromFile("./resources/img/player_4_right.png");

    //player fly sprites left
    g_player1_fly_left_sprite=esat::SpriteFromFile("./resources/img/player_fly_1_left.png");
    g_player2_fly_left_sprite=esat::SpriteFromFile("./resources/img/player_fly_2_left.png");
    g_player3_fly_left_sprite=esat::SpriteFromFile("./resources/img/player_fly_3_left.png");
    g_player4_fly_left_sprite=esat::SpriteFromFile("./resources/img/player_fly_4_left.png");

    //player fly sprites right
    g_player1_fly_right_sprite=esat::SpriteFromFile("./resources/img/player_fly_1_right.png");
    g_player2_fly_right_sprite=esat::SpriteFromFile("./resources/img/player_fly_2_right.png");
    g_player3_fly_right_sprite=esat::SpriteFromFile("./resources/img/player_fly_3_right.png");
    g_player4_fly_right_sprite=esat::SpriteFromFile("./resources/img/player_fly_4_right.png");

    //platform sprites
    g_platform_sprite=esat::SpriteFromFile("./resources/img/platform_1.png");
    g_platform2_sprite=esat::SpriteFromFile("./resources/img/platform_2.png");
    g_platform3_sprite=esat::SpriteFromFile("./resources/img/platform_3.png");
    g_platform_bottom_sprite=esat::SpriteFromFile("./resources/img/platform_bottom.png");

    //ships sprites
    g_ship_type1_1_sprite=esat::SpriteFromFile("./resources/img/ship_1.png");
    g_ship_type1_2_sprite=esat::SpriteFromFile("./resources/img/ship_2.png");
    g_ship_type1_3_sprite=esat::SpriteFromFile("./resources/img/ship_3.png");
    g_ship_type1_full_sprite=esat::SpriteFromFile("./resources/img/full_ship_1.png");

    g_ship_type2_1_sprite=esat::SpriteFromFile("./resources/img/ship_1_2.png");
    g_ship_type2_2_sprite=esat::SpriteFromFile("./resources/img/ship_2_2.png");
    g_ship_type2_3_sprite=esat::SpriteFromFile("./resources/img/ship_3_2.png");
    g_ship_type2_full_sprite=esat::SpriteFromFile("./resources/img/full_ship_2.png");

    g_ship_type3_1_sprite=esat::SpriteFromFile("./resources/img/ship_1_3.png");
    g_ship_type3_2_sprite=esat::SpriteFromFile("./resources/img/ship_2_3.png");
    g_ship_type3_3_sprite=esat::SpriteFromFile("./resources/img/ship_3_3.png");
    g_ship_type3_full_sprite=esat::SpriteFromFile("./resources/img/full_ship_3.png");

    g_ship_type4_1_sprite=esat::SpriteFromFile("./resources/img/ship_1_4.png");
    g_ship_type4_2_sprite=esat::SpriteFromFile("./resources/img/ship_2_4.png");
    g_ship_type4_3_sprite=esat::SpriteFromFile("./resources/img/ship_3_4.png");
    g_ship_type4_full_sprite=esat::SpriteFromFile("./resources/img/full_ship_4.png");

    //object sprites
    g_fuel_sprite=esat::SpriteFromFile("./resources/img/fuel.png");
    g_nuclear_sprite=esat::SpriteFromFile("./resources/img/nuclear.png");

    g_diamond_sprite=esat::SpriteFromFile("./resources/img/diamond_1.png");
    g_diamond_blue_sprite=esat::SpriteFromFile("./resources/img/diamond_1_blue.png");
    g_diamond_purple_sprite=esat::SpriteFromFile("./resources/img/diamond_1_purple.png");
    g_diamond_red_sprite=esat::SpriteFromFile("./resources/img/diamond_1_red.png");

    g_gold_sprite=esat::SpriteFromFile("./resources/img/gold.png");
    g_triangle_sprite=esat::SpriteFromFile("./resources/img/triangle.png");

    //Interface sprites
    g_1up_sprite=esat::SpriteFromFile("./resources/img/1up.png");
    g_2up_sprite=esat::SpriteFromFile("./resources/img/2up.png");
    g_HI_sprite=esat::SpriteFromFile("./resources/img/hi.png");
    g_Life_sprite=esat::SpriteFromFile("./resources/img/life_player.png");

    g_loading_screen_1=esat::SpriteFromFile("./resources/img/loading_screen_1.png");
    g_loading_screen_2=esat::SpriteFromFile("./resources/img/loading_screen_2.png");
    g_game_selection=esat::SpriteFromFile("./resources/img/game_selection.png");
    g_game_selection_1=esat::SpriteFromFile("./resources/img/game_selection_1.png");

    //Ships with fuel
    g_ship_type1_fuel1_sprite=esat::SpriteFromFile("./resources/img/full_ship_1_fuel1.png");
    g_ship_type1_fuel2_sprite=esat::SpriteFromFile("./resources/img/full_ship_1_fuel2.png");
    g_ship_type1_fuel3_sprite=esat::SpriteFromFile("./resources/img/full_ship_1_fuel3.png");
    g_ship_type1_fuel4_sprite=esat::SpriteFromFile("./resources/img/full_ship_1_fuel4.png");
    g_ship_type1_fuel5_sprite=esat::SpriteFromFile("./resources/img/full_ship_1_fuel5.png");

    g_ship_type2_fuel1_sprite=esat::SpriteFromFile("./resources/img/full_ship_2_fuel1.png");
    g_ship_type2_fuel2_sprite=esat::SpriteFromFile("./resources/img/full_ship_2_fuel2.png");
    g_ship_type2_fuel3_sprite=esat::SpriteFromFile("./resources/img/full_ship_2_fuel3.png");
    g_ship_type2_fuel4_sprite=esat::SpriteFromFile("./resources/img/full_ship_2_fuel4.png");
    g_ship_type2_fuel5_sprite=esat::SpriteFromFile("./resources/img/full_ship_2_fuel5.png");

    g_ship_type3_fuel1_sprite=esat::SpriteFromFile("./resources/img/full_ship_3_fuel1.png");
    g_ship_type3_fuel2_sprite=esat::SpriteFromFile("./resources/img/full_ship_3_fuel2.png");
    g_ship_type3_fuel3_sprite=esat::SpriteFromFile("./resources/img/full_ship_3_fuel3.png");
    g_ship_type3_fuel4_sprite=esat::SpriteFromFile("./resources/img/full_ship_3_fuel4.png");
    g_ship_type3_fuel5_sprite=esat::SpriteFromFile("./resources/img/full_ship_3_fuel5.png");

    g_ship_type4_fuel1_sprite=esat::SpriteFromFile("./resources/img/full_ship_4_fuel1.png");
    g_ship_type4_fuel2_sprite=esat::SpriteFromFile("./resources/img/full_ship_4_fuel2.png");
    g_ship_type4_fuel3_sprite=esat::SpriteFromFile("./resources/img/full_ship_4_fuel3.png");
    g_ship_type4_fuel4_sprite=esat::SpriteFromFile("./resources/img/full_ship_4_fuel4.png");
    g_ship_type4_fuel5_sprite=esat::SpriteFromFile("./resources/img/full_ship_4_fuel5.png");

    //Bullet sprites
    g_bullet_small_white_sprite=esat::SpriteFromFile("./resources/img/bullet_small_white.png");
    g_bullet_middle_white_sprite=esat::SpriteFromFile("./resources/img/bullet_middle_white.png");
    g_bullet_long_white_sprite=esat::SpriteFromFile("./resources/img/bullet_long_white.png");

    g_bullet_small_red_sprite=esat::SpriteFromFile("./resources/img/bullet_small_red.png");
    g_bullet_middle_red_sprite=esat::SpriteFromFile("./resources/img/bullet_middle_red.png");
    g_bullet_long_red_sprite=esat::SpriteFromFile("./resources/img/bullet_long_red.png");

    g_bullet_small_purple_sprite=esat::SpriteFromFile("./resources/img/bullet_small_purple.png");
    g_bullet_middle_purple_sprite=esat::SpriteFromFile("./resources/img/bullet_middle_purple.png");
    g_bullet_long_purple_sprite=esat::SpriteFromFile("./resources/img/bullet_long_purple.png");

    //Fire sprites
    g_fire1_sprite=esat::SpriteFromFile("./resources/img/fire_1.png");
    g_fire2_sprite=esat::SpriteFromFile("./resources/img/fire_2.png");

    //Enemies sprites
    g_wind1_left_sprite=esat::SpriteFromFile("./resources/img/wind_1_left.png");
    g_wind1_right_sprite=esat::SpriteFromFile("./resources/img/wind_1_right.png");
    g_wind2_left_sprite=esat::SpriteFromFile("./resources/img/wind_2_left.png");
    g_wind2_right_sprite=esat::SpriteFromFile("./resources/img/wind_2_right.png");

    g_wind1_left_green_sprite=esat::SpriteFromFile("./resources/img/wind_1_left_green.png");
    g_wind1_right_green_sprite=esat::SpriteFromFile("./resources/img/wind_1_right_green.png");
    g_wind2_left_green_sprite=esat::SpriteFromFile("./resources/img/wind_2_left_green.png");
    g_wind2_right_green_sprite=esat::SpriteFromFile("./resources/img/wind_2_right_green.png");

    g_bush1_sprite=esat::SpriteFromFile("./resources/img/bush_1.png");
    g_bush2_sprite=esat::SpriteFromFile("./resources/img/bush_2.png");

    g_ball1_sprite=esat::SpriteFromFile("./resources/img/ball_1.png");
    g_ball2_sprite=esat::SpriteFromFile("./resources/img/ball_2.png");

    g_bird_left_sprite=esat::SpriteFromFile("./resources/img/bird_left.png");
    g_bird_right_sprite=esat::SpriteFromFile("./resources/img/bird_right.png");

    g_dust_sprite=esat::SpriteFromFile("./resources/img/dust.png");

    g_cross_sprite=esat::SpriteFromFile("./resources/img/cross.png");

    g_millenniumFalcon_right_sprite=esat::SpriteFromFile("./resources/img/ship_right.png");
    g_millenniumFalcon_left_sprite=esat::SpriteFromFile("./resources/img/ship_left.png");

    g_frog_sprite=esat::SpriteFromFile("./resources/img/frog.png");
    g_sprite=esat::SpriteFromFile("./resources/img/spriteb.png");

    //Explosion sprites
    g_explosion1_sprite=esat::SpriteFromFile("./resources/img/explosion_1.png");
    g_explosion2_sprite=esat::SpriteFromFile("./resources/img/explosion_2.png");
    g_explosion3_sprite=esat::SpriteFromFile("./resources/img/explosion_3.png");

    g_explosion3_empty1_sprite=esat::SpriteFromFile("./resources/img/explosion_3_empty.png");
    g_explosion3_empty2_sprite=esat::SpriteFromFile("./resources/img/explosion_3_empty2.png");

    g_explosion1_2_sprite=esat::SpriteFromFile("./resources/img/explosion1_2.png");
    g_explosion2_2_sprite=esat::SpriteFromFile("./resources/img/explosion2_2.png");
    g_explosion3_2_sprite=esat::SpriteFromFile("./resources/img/explosion3_2.png");

    g_pp_sprite=esat::SpriteFromFile("./resources/img/pepe.png");

}


void ReleaseSprites(){
    //player sprites left
    esat::SpriteRelease(g_player1_left_sprite);
    esat::SpriteRelease(g_player2_left_sprite);
    esat::SpriteRelease(g_player3_left_sprite);
    esat::SpriteRelease(g_player4_left_sprite);

    //player sprites right
    esat::SpriteRelease(g_player1_right_sprite);
    esat::SpriteRelease(g_player2_right_sprite);
    esat::SpriteRelease(g_player3_right_sprite);
    esat::SpriteRelease(g_player4_right_sprite);
    
    //player fly sprites left
    esat::SpriteRelease(g_player1_fly_left_sprite);
    esat::SpriteRelease(g_player2_fly_left_sprite);
    esat::SpriteRelease(g_player3_fly_left_sprite);
    esat::SpriteRelease(g_player4_fly_left_sprite);

    //player fly sprites right
    esat::SpriteRelease(g_player1_fly_right_sprite);
    esat::SpriteRelease(g_player2_fly_right_sprite);
    esat::SpriteRelease(g_player3_fly_right_sprite);
    esat::SpriteRelease(g_player4_fly_right_sprite);

    //platform sprites
    esat::SpriteRelease(g_platform_sprite);
    esat::SpriteRelease(g_platform2_sprite);
    esat::SpriteRelease(g_platform3_sprite);
    esat::SpriteRelease(g_platform_bottom_sprite);

    //ships sprites
    esat::SpriteRelease(g_ship_type1_1_sprite);
    esat::SpriteRelease(g_ship_type1_2_sprite);
    esat::SpriteRelease(g_ship_type1_3_sprite);
    esat::SpriteRelease(g_ship_type1_full_sprite);

    esat::SpriteRelease(g_ship_type2_1_sprite);
    esat::SpriteRelease(g_ship_type2_2_sprite);
    esat::SpriteRelease(g_ship_type2_3_sprite);
    esat::SpriteRelease(g_ship_type2_full_sprite);

    esat::SpriteRelease(g_ship_type3_1_sprite);
    esat::SpriteRelease(g_ship_type3_2_sprite);
    esat::SpriteRelease(g_ship_type3_3_sprite);
    esat::SpriteRelease(g_ship_type3_full_sprite);

    esat::SpriteRelease(g_ship_type4_1_sprite);
    esat::SpriteRelease(g_ship_type4_2_sprite);
    esat::SpriteRelease(g_ship_type4_3_sprite);
    esat::SpriteRelease(g_ship_type4_full_sprite);

    //object sprites
    esat::SpriteRelease(g_fuel_sprite);
    esat::SpriteRelease(g_nuclear_sprite);

    esat::SpriteRelease(g_diamond_sprite);
    esat::SpriteRelease(g_diamond_blue_sprite);
    esat::SpriteRelease(g_diamond_purple_sprite);
    esat::SpriteRelease(g_diamond_red_sprite);

    esat::SpriteRelease(g_gold_sprite);
    esat::SpriteRelease(g_triangle_sprite);

    //Interface sprites
    esat::SpriteRelease(g_1up_sprite);
    esat::SpriteRelease(g_2up_sprite);
    esat::SpriteRelease(g_HI_sprite);
    esat::SpriteRelease(g_Life_sprite);

    esat::SpriteRelease(g_loading_screen_1);
    esat::SpriteRelease(g_loading_screen_2);
    esat::SpriteRelease(g_game_selection);
    esat::SpriteRelease(g_game_selection_1);

    //Ships with fuel
    esat::SpriteRelease(g_ship_type1_fuel1_sprite);
    esat::SpriteRelease(g_ship_type1_fuel2_sprite);
    esat::SpriteRelease(g_ship_type1_fuel3_sprite);
    esat::SpriteRelease(g_ship_type1_fuel4_sprite);
    esat::SpriteRelease(g_ship_type1_fuel5_sprite);

    esat::SpriteRelease(g_ship_type2_fuel1_sprite);
    esat::SpriteRelease(g_ship_type2_fuel2_sprite);
    esat::SpriteRelease(g_ship_type2_fuel3_sprite);
    esat::SpriteRelease(g_ship_type2_fuel4_sprite);
    esat::SpriteRelease(g_ship_type2_fuel5_sprite);

    esat::SpriteRelease(g_ship_type3_fuel1_sprite);
    esat::SpriteRelease(g_ship_type3_fuel2_sprite);
    esat::SpriteRelease(g_ship_type3_fuel3_sprite);
    esat::SpriteRelease(g_ship_type3_fuel4_sprite);
    esat::SpriteRelease(g_ship_type3_fuel5_sprite);

    esat::SpriteRelease(g_ship_type4_fuel1_sprite);
    esat::SpriteRelease(g_ship_type4_fuel2_sprite);
    esat::SpriteRelease(g_ship_type4_fuel3_sprite);
    esat::SpriteRelease(g_ship_type4_fuel4_sprite);
    esat::SpriteRelease(g_ship_type4_fuel5_sprite);

    //Bullet sprites
    esat::SpriteRelease(g_bullet_small_white_sprite);
    esat::SpriteRelease(g_bullet_middle_white_sprite);
    esat::SpriteRelease(g_bullet_long_white_sprite);

    esat::SpriteRelease(g_bullet_small_red_sprite);
    esat::SpriteRelease(g_bullet_middle_red_sprite);
    esat::SpriteRelease(g_bullet_long_red_sprite);    

    esat::SpriteRelease(g_bullet_small_purple_sprite);
    esat::SpriteRelease(g_bullet_middle_purple_sprite);
    esat::SpriteRelease(g_bullet_long_purple_sprite);  

    //Fire sprites
    esat::SpriteRelease(g_fire1_sprite);
    esat::SpriteRelease(g_fire2_sprite);

    //Enemies sprites
    esat::SpriteRelease(g_wind1_left_sprite);
    esat::SpriteRelease(g_wind1_right_sprite);
    esat::SpriteRelease(g_wind2_left_sprite);
    esat::SpriteRelease(g_wind2_right_sprite);

    esat::SpriteRelease(g_wind1_left_green_sprite);
    esat::SpriteRelease(g_wind1_right_green_sprite);
    esat::SpriteRelease(g_wind2_left_green_sprite);
    esat::SpriteRelease(g_wind2_right_green_sprite);

    esat::SpriteRelease(g_bush1_sprite);
    esat::SpriteRelease(g_bush2_sprite);

    esat::SpriteRelease(g_ball1_sprite);
    esat::SpriteRelease(g_ball2_sprite);
    
    esat::SpriteRelease(g_bird_left_sprite);
    esat::SpriteRelease(g_bird_right_sprite);

    esat::SpriteRelease(g_dust_sprite);

    esat::SpriteRelease(g_cross_sprite);

    esat::SpriteRelease(g_millenniumFalcon_right_sprite);
    esat::SpriteRelease(g_millenniumFalcon_left_sprite);

    esat::SpriteRelease(g_frog_sprite);
    esat::SpriteRelease(g_sprite);

    //Explosion sprites
    esat::SpriteRelease(g_explosion1_sprite);
    esat::SpriteRelease(g_explosion2_sprite);
    esat::SpriteRelease(g_explosion3_sprite);

    esat::SpriteRelease(g_explosion3_empty1_sprite);
    esat::SpriteRelease(g_explosion3_empty2_sprite);

    esat::SpriteRelease(g_explosion1_2_sprite);
    esat::SpriteRelease(g_explosion2_2_sprite);
    esat::SpriteRelease(g_explosion3_2_sprite);

    esat::SpriteRelease(g_pp_sprite);
}
