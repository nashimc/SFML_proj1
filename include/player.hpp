#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Player{
private:
	sf::CircleShape* player;
	

public:
	Player(sf::CircleShape* player);
	virtual ~Player();

	void initPlayer();

	sf::CircleShape* getPlayer();
};