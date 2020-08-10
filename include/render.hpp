#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "player.hpp"



class Render{
private:
	
	sf::RenderWindow* window;
	std::vector<sf::RectangleShape>* enemies;
	std::vector<sf::CircleShape>* playerVec;

public:
	Render(sf::RenderWindow* window, std::vector<sf::CircleShape>* playerVec, std::vector<sf::RectangleShape>* enemies);
	virtual ~Render();

	void renderPlayer();
	void renderEnemies();
	void render();
};