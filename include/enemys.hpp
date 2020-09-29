/*
*Class Enemy for SpaceInvaders
*Author: Pablo Martín Gonzalez
*/

#ifndef ENEMYS_HPP
#define ENEMYS_HPP 1

#include <iostream>
#include <vector>
#include <esat/window.h>
#include <esat/math.h>
#include <esat/sprite.h>
#include <shot.hpp>
#include <esat/input.h>
#include <player_canon.hpp>
#include <cstdlib>

class Enemy{

  int id;
  int width;
  int height;
  esat::Vec2 position;
  esat::SpriteHandle handle;
  bool alive;
  std::vector<Shot> shots;
  static int direction;

 public:
  
  Enemy(int width, int height, int x, int y, char *path);

  ~Enemy();

  esat::Vec2 get_pos();

  int get_width();

  int get_height();

  bool get_alive();

  void set_alive(bool alive);

  void set_position(int x, int y);

  void clear_shots();

  std::vector<Shot> get_shots();

  bool is_on_bottom();

  bool check_collision(PlayerCanon &player);
  
  void move_horizontal(float distance);
  
  void move_shots();

  void move_down();

  void draw();

  void shot();

  bool is_on_limit();

  void erase_shot(int i);

  void draw_shots();

  bool check_collision_canon(PlayerCanon &player);

};

#endif