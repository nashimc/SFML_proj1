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
	this->player.setRadius(32);
	this->player.setPosition(600, 700);	
	this->player.setFillColor(sf::Color::Green);
	this->player.setOutlineColor(sf::Color::Green);
	this->player.setOutlineThickness(1.f);

	playerVec->push_back(player);

}


void Player::movePlayer(){
	
}