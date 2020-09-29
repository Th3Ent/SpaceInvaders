#include <shot.hpp>

Shot::Shot(int width, int height, esat::Vec2 position){

  this->width = width;
  this->height = height;
  this->position = position;
  this->enemy_shot = false;

}

Shot::Shot(int width, int height, esat::Vec2 position, bool enemy_shot){

  this->width = width;
  this->height = height;
  this->position = position;
  this->enemy_shot = enemy_shot;

}

Shot::~Shot(){

  this->width = 0;
  this->height = 0;
  this->position;
  this->enemy_shot;

}

void Shot::move(){
  if(enemy_shot){
    position.y += 2;
  }else{
    position.y -= 2;
  }
}
void Shot::draw(){
  if(enemy_shot){
    esat::DrawLine(position.x, position.y, position.x, position.y-height);
  }else{
    esat::DrawLine(position.x, position.y, position.x, position.y+height);
  }
}

esat::Vec2 Shot::get_pos(){

  return position;

}