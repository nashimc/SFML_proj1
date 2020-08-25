#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>





class Render{
private:
	
	sf::RenderWindow* window;
	sf::CircleShape* player;
	std::vector<sf::RectangleShape>* enemies;
	std::vector<sf::CircleShape>* projectileVec;
	

public:
	Render(sf::RenderWindow* window, sf::CircleShape* player, std::vector<sf::RectangleShape>* enemies, std::vector<sf::CircleShape>* projectileVec);
	virtual ~Render();

	void renderPlayer();
	void renderEnemies();
	void renderProjectile();
	void render();
};