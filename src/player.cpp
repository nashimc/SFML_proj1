#include "player.hpp"


Player::Player(sf::CircleShape* player)
:	player(player)
{
	initPlayer();
}

Player::~Player(){

	player = NULL; 
}

void Player::initPlayer(){
	player->setRadius(30);
	player->setPosition(600, 700);	
	player->setFillColor(sf::Color::Green);
	player->setOutlineColor(sf::Color::Green);
	player->setOutlineThickness(1.f);
}


