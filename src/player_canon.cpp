#include <player_canon.hpp>

PlayerCanon::PlayerCanon(int width, int heith, int x, int y){
  this->width = width;
  this->height = height;
  this->position.x = x;
	this->position.y = y;
  this->handle = esat::SpriteFromFile("../data/CANON.png");
}

PlayerCanon::~PlayerCanon(){
  this->width = 0;
  this->height = 0;
  this->position.x = 0;
	this->position.y = 0;
  this->handle = NULL;
	this->shots.clear();

}

void PlayerCanon::set_pos(int x, int y){
	this->position.x = x;
	this->position.y = y;
}

void PlayerCanon::clear_shots(){

	shots.clear();

}

std::vector<Shot> PlayerCanon::get_shots(){
	return shots;
}

void PlayerCanon::shot(){
  esat::Vec2 aux = position;
	aux.x +=(width/2);
  shots.push_back(Shot(1,3, aux));
}

void PlayerCanon::move(){

  if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) && position.x >= 0){
		position.x-= 1;
	}
	if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) 
			&& position.x+width <= 800){
		position.x+= 1;
	}
	if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
		shot();
	}
	for(int i = 0; i < shots.size(); i++){

		shots.at(i).move();

	}

}

void PlayerCanon::draw(){

	esat::DrawSprite(handle, position.x, position.y);
	esat::DrawSetStrokeColor(255,255,255);
	
	int i = 0;
	while(i < shots.size()){

		shots.at(i).draw();

		if(shots.at(i).get_pos().y < 0){
			erase_shot(i);	
			i--;	
		}

		i++;
	}

}

void PlayerCanon::erase_shot(int i){

	shots.erase(shots.begin()+i);

}

esat::Vec2 PlayerCanon::get_pos(){

	return position;

}
/*bool PlayerCanon::check_collision(Enemy &enemys){

	for(int i = 0; i < enemys.get_shots().size(); i++){

		if(enemys.get_shots().at(i).get_pos().x >= position.x &&
				enemys.get_shots().at(i).get_pos().x <= position.x+width &&
				enemys.get_shots().at(i).get_pos().y >= position.y &&
				enemys.get_shots().at(i).get_pos().y <= position.y+height){

			enemys.erase_shot(i);
			return true;

		}

	}
	return false;
}*/
