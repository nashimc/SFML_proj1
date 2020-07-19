#include "render.hpp"



Render::Render(sf::RenderWindow* window, std::vector<RectangleShape>* enemies )
:	window{window},
	enemies{enemies}
{}

Render::~Render(){}

void Render::renderEnemies(){
	for (auto &i : *enemies){
		window->draw(i);
	}
}

void Render::render(){
	window->clear(sf::Color(0, 0, 0));

	renderEnemies();

	window->display();
}