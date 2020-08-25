#include "render.hpp"



Render::Render(sf::RenderWindow* window, sf::CircleShape* player, std::vector<sf::RectangleShape>* enemies, std::vector<sf::CircleShape>* projectileVec)
:	window(window),
	player(player),
	enemies(enemies),
	projectileVec(projectileVec)
{}

Render::~Render(){
	
	player = NULL;
	enemies = NULL;
	projectileVec = NULL;
	window = NULL;
	
}

void Render::renderPlayer(){
	window->draw(*player);
}

void Render::renderEnemies(){
	for (auto &i : *enemies){
		window->draw(i);
	}
}

void Render::renderProjectile(){
	for (auto &i : *projectileVec){
		window->draw(i);
	}
}

void Render::render(){
	window->clear(sf::Color(0, 0, 0));

	renderPlayer();
	renderEnemies();
	renderProjectile();

	window->display();
}