#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Player{
private:
	sf::CircleShape player;
	std::vector<sf::CircleShape>* playerVec;

	

public:
	Player(std::vector<sf::CircleShape>* playerVec);
	virtual ~Player();

	void initPlayer();
	sf::CircleShape* getPlayer();
	void movePlayer();
	void updatePlayer();
};