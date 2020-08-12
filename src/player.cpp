#include "player.hpp"


Player::Player(std::vector<sf::CircleShape>* playerVec)
:	playerVec(playerVec)
{
	initPlayer();
}

Player::~Player(){

	playerVec = NULL; 
}

void Player::initPlayer(){
	player.setRadius(30);
	player.setPosition(600, 700);	
	player.setFillColor(sf::Color::Green);
	player.setOutlineColor(sf::Color::Green);
	player.setOutlineThickness(1.f);

	playerVec->push_back(player);

}


void Player::movePlayer(){
	
}

void Player::updatePlayer(){
	
}