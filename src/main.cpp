/*
*Space Invaders for ESAT 2020/2021
*Author: Pablo Martin Gonzalez
*
*/

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/time.h>
#include <esat/math.h>
#include <esat/sprite.h>
#include <player_canon.hpp>
#include <enemys.hpp>
#include <iostream>
#include <vector>

void create_enemys(std::vector<Enemy> &enemys){
  float x = 213;
  float y = 100;
  char *path = "../data/enemy_type_three.png";
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 11 ; j++){
      enemys.push_back(Enemy(24,16,x,y,path));
      x += 35;
    }
    y += 30;
    x = 213;
    if(i == 0){
      path= "../data/enemy_type_two.png";
    }
    if(i == 2){
      path= "../data/enemy_type_one.png";
    }
  }
}

void draw_enemys(std::vector<Enemy> &enemys){
  for(int i = 0; i < enemys.size(); i++){
    if(enemys.at(i).get_alive()){
      enemys.at(i).draw();
    }
    enemys.at(i).draw_shots();
  }
}


void move_enemy(std::vector<Enemy> &enemys, float distance){
  bool move_down = false;
  for(int i = 0; i < enemys.size() && !move_down; i++){
    if(enemys.at(i).is_on_limit() && enemys.at(i).get_alive()){
      move_down = true;
    }
  }
  if(move_down){
    for(int i = 0; i < enemys.size(); i++){
      if( enemys.at(i).get_alive()){
        enemys.at(i).move_down();
      }
    }
  }
  for(int i = 0; i < enemys.size(); i++){
    if( enemys.at(i).get_alive()){
      enemys.at(i).move_horizontal(distance);
      enemys.at(i).shot();
    }
    enemys.at(i).move_shots();
  }
}

bool check_collisions(std::vector<Enemy> &enemys, PlayerCanon &player, int &enemys_alive){
  for(int i = 0; i < enemys.size(); i++){
    if(enemys.at(i).get_alive()){
      if(enemys.at(i).check_collision(player)){
        enemys_alive--;
      }
    }

    
    if(enemys.at(i).check_collision_canon(player)){
      std::cout<<"Muerto"<<std::endl;
      return true;

    }
  }
  return false;
}

void reset_enemys(std::vector<Enemy> &enemys, int &enemys_alive){
  enemys_alive = 55;
  float x = 213;
  float y = 100;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 11 ; j++){
      enemys.at(i*11+j).set_alive(true);
      enemys.at(i*11+j).set_position(x,y);
      enemys.at(i*11+j).clear_shots();
      x += 35;
    }
    y += 30;
    x = 213;
  }
}

void next_level(std::vector<Enemy> &enemys, float &level, int &enemys_alive){
  if(enemys_alive == 0){
    level +=0.2;
    reset_enemys(enemys, enemys_alive);
  }
}

bool is_game_over(std::vector<Enemy> &enemys){

  for(int i = 0; i < enemys.size(); i++){
    if(enemys.at(i).get_alive()){
       if(enemys.at(i).is_on_bottom()){
         return true;
       }    
    }
  }
  return false;
}

void shot_enemys(std::vector<Enemy> &enemys){

  for(int i = 0; i < enemys.size(); i++){
    if(enemys.at(i).get_alive()){
      enemys.at(i).shot();   
    }
  }

}

void reset_game(std::vector<Enemy> &enemys, PlayerCanon &canon, int &enemys_alive, float &level, bool &game_over){
  level = 0.2f;
  canon.set_pos(388, 530);
  canon.clear_shots();
  reset_enemys(enemys, enemys_alive);
  game_over = false;
}

int esat::main(int argc, char **argv){
  int enemys_alive = 55;
  float level = 0.2;
  bool game_over = false;
  esat::WindowInit(800,600);
  PlayerCanon canon(24,22, 388, 530);
  std::vector<Enemy> enemys;
  create_enemys(enemys);
  while(esat::WindowIsOpened() && 
      !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)){
    esat::DrawBegin();
    esat::DrawClear(0,0,0);
    if(!game_over){
      
      game_over = is_game_over(enemys);
      next_level(enemys, level, enemys_alive);
      canon.move();
      move_enemy(enemys, level);
      shot_enemys(enemys);
      game_over = check_collisions(enemys, canon, enemys_alive);
      canon.draw();
      draw_enemys(enemys);

      
    }else{
      esat::DrawSetStrokeColor(255,255,255);
      esat::DrawSetFillColor(255,255,255);
      esat::DrawSetTextSize(20);
      esat::DrawText(400, 300, "You lose.");
      esat::DrawText(400, 400, "Try again? Press SPACE");
      esat::DrawText(400, 400, "Press ESC for exit");
      if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Space)){
        reset_game(enemys, canon, enemys_alive, level, game_over);
      }

    }
    esat::DrawEnd();
    esat::WindowFrame();
  }


return 0;
}

