#include "render.hpp"



Render::Render(sf::RenderWindow* window, std::vector<sf::CircleShape>* playerVec, std::vector<sf::RectangleShape>* enemies)
:	window(window),
	enemies(enemies),
	playerVec(playerVec)
{}

Render::~Render(){
	
	playerVec = NULL;
	enemies = NULL;
	window = NULL;
	
}

void Render::renderPlayer(){
	for (auto &i : *playerVec){
		window->draw(i);
	}
}

void Render::renderEnemies(){
	for (auto &i : *enemies){
		window->draw(i);
	}
}

void Render::render(){
	window->clear(sf::Color(0, 0, 0));

	renderPlayer();
	renderEnemies();

	window->display();
}