#include <iostream>
#include "game.hpp"



Game::Game(){
	this->initVariables();		// create window with nullptr first
	this->initWindow();

	ren = new Render{window, &enemies};	
}

Game::~Game(){

}

void Game::initVariables(){
	this->window = nullptr;

	// Game logic
	this->points = 0;
	this->health = 100;

	this->mouseHeld = false;




}

void Game::initWindow(){
	this->videoMode.width = 800;			// accessing 
	this->videoMode.height = 600;			// accessing 

	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);		// window properties

	this->window->setFramerateLimit(60);		// FPS limit
}

const bool Game::isRunning() const{
	return this->window->isOpen();
}


void Game::pollEvents(){
	// Used internally in this->update()
	while (this->window->pollEvent(this->event)){ // 
            switch(this->event.type){
                
                case sf::Event::Closed:
                    this->window->close();
                    break;

                case sf::Event::KeyPressed:
                    if(this->event.key.code == sf::Keyboard::Escape){
                        this->window->close();
                    break;
                    }
                
                default:
                    break;   
            }
        }
}

void Game::updateMousePositions(){
	// Updates the mouse position relative to window (Vector2i)
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::checkInputs(){
	// Check if enemies clicked
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if (mouseHeld == false){
			mouseHeld = true;
			deleted = false;

			for (int i = 0; i < enemies.size(); ++i){
				if (enemies[i].getGlobalBounds().contains(mousePosView)){
					deleted = true;
					enemies.erase(enemies.begin() + i); // + i needed to erase i-th element

					points = points + 1;
					std::cout << "Points: " << points << std::endl;
				}
			}
		}
	}
	else{
		mouseHeld = false;
	}
}

void Game::update(){

	// Calling polling of event/update functions
	pollEvents();
	updateMousePositions();
	checkInputs();
	
	en.updateEnemies();
	
}


void Game::render(){
	ren->render();

}

// Debug: move this to destructor
void Game::deleteOnClose(){
	delete this->window;
	delete this->ren;
}
