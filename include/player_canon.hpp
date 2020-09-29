/*
*Class PlayerCanon for SpaceInvaders
*Author: Pablo Martín Gonzalez
*/

#ifndef PLAYER_CANON_HPP
#define PLAYER_CANON_HPP 1

#include <iostream>
#include <vector>
#include <esat/window.h>
#include <esat/math.h>
#include <esat/sprite.h>
#include <shot.hpp>
#include <esat/input.h>
//#include <enemys.hpp>


class PlayerCanon{

  int id;
  int width;
  int height;
  esat::Vec2 position;
  esat::SpriteHandle handle;
  std::vector<Shot> shots;
  
 public:

  PlayerCanon(int width, int heith, int x, int y);

  ~PlayerCanon();

  void set_pos(int x, int y);
  
  void clear_shots();

  std::vector<Shot> get_shots();

  esat::Vec2 get_pos();

  void move();

  void shot();

  void draw();

  void erase_shot(int i);

  //bool check_collision(Enemy &enemys);

};


#endif