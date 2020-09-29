#include <enemys.hpp>

Enemy::Enemy(int width, int height, int x, int y, char *path){
  this->width = width;
  this->height = height;
  this->position.x = x;
  this->position.y = y;
  this->handle = esat::SpriteFromFile(path);
 // this->direction = 1;
}

int Enemy::direction = 1;

Enemy::~Enemy(){}

esat::Vec2 Enemy::get_pos(){
  return position;
}

int Enemy::get_width(){
  return width;
}

int Enemy::get_height(){
  return height;
}

bool Enemy::get_alive(){
  return alive;
}

void Enemy::set_alive(bool alive){
  this->alive = alive;
}

void Enemy::clear_shots(){

  shots.clear();

}

void Enemy::set_position(int x, int y){

  this->position.x = x;
  this->position.y = y;

}

bool Enemy::is_on_bottom(){
  return position.y >=500;
}

bool Enemy::check_collision(PlayerCanon &player){

 for(int i = 0; i < player.get_shots().size(); i++){
    if(player.get_shots().at(i).get_pos().x >= get_pos().x && 
        player.get_shots().at(i).get_pos().x <= get_pos().x+get_width() &&
        player.get_shots().at(i).get_pos().y >= get_pos().y && 
        player.get_shots().at(i).get_pos().y <= get_pos().y+get_height()){

      player.erase_shot(i);
      set_alive(false); 
      return true;
    }
  }
  return false;
  

}

void Enemy::move_horizontal(float distance){

  position.x +=(float)distance*(float)direction;

}
void Enemy::move_shots(){

  for(int i = 0; i < shots.size(); i++){

    shots.at(i).move();

  }

}

void Enemy::move_down(){

  position.y +=30;

}

void Enemy::draw(){
  if(alive){
    esat::DrawSprite(handle, position.x, position.y);
  }
}

void Enemy::draw_shots(){

  esat::DrawSetStrokeColor(255,255,255);
	int i = 0;
	while(i < shots.size()){

		shots.at(i).draw();

		if(shots.at(i).get_pos().y < 0){
			shots.erase(shots.begin()+i);	
			i--;	
		}

		i++;
	}

}

void Enemy::shot(){

  if((rand() % 10000) == 1 ){
    esat::Vec2 aux = position;
	  aux.x +=(width/2);
    shots.push_back(Shot(1,3, aux, true));
  }

}

bool Enemy::is_on_limit(){

  if(position.x <= 0 || position.x+width >= 800){
    direction *= -1;
    return true;
  }
  return false;

}

void Enemy::erase_shot(int i){

	shots.erase(shots.begin()+i);

}

std::vector<Shot> Enemy::get_shots(){

  return shots;

}

bool Enemy::check_collision_canon(PlayerCanon &player){

  for(int i = 0; i < get_shots().size(); i++){

		if(get_shots().at(i).get_pos().x >= player.get_pos().x &&
				get_shots().at(i).get_pos().x <= player.get_pos().x+width &&
				get_shots().at(i).get_pos().y >= player.get_pos().y &&
				get_shots().at(i).get_pos().y <= player.get_pos().y+height){

			erase_shot(i);
			return true;

		}

	}
	return false;

}