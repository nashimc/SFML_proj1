#include "inputs.hpp"

Inputs::Inputs(sf::CircleShape* player, Weapon* wep)
:	player(player),
	wep(wep)
{}

Inputs::~Inputs(){
	player = NULL;
	wep = NULL;
}


void Inputs::keyboardInputs(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		wep->shootProjectile();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		player->move(-5.f, 0.f);
		if (player->getPosition().x < 0){
			player->setPosition(0, 700);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		player->move(5.f, 0.f);
		if (player->getPosition().x > 1140){
			player->setPosition(1140, 700);
		}
	}
}
