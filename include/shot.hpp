#ifndef SHOT_HPP
#define SHOT_HPP 1


#include <iostream>
#include <esat/window.h>
#include <esat/math.h>
#include <esat/sprite.h>
#include <esat/draw.h>


class Shot{

  int id;
  int width;
  int height;
  bool enemy_shot;
  esat::Vec2 position;
  
 public:
  
  Shot(int width, int heith, esat::Vec2 position);

  Shot(int width, int heith, esat::Vec2 position, bool enemy);

  ~Shot();

  void move();

  void draw();

  esat::Vec2 get_pos();
  

};

#endif