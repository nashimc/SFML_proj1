#include <iostream>
#include "game.hpp"

// try an remove args of Render constructors
Game::Game(){
	initVariables();		// create window with nullptr first
	initWindow();

	pl = new Player(&playerVec);
	en = new Enemy(points, health, &enemies);
	ren = new Render(window, &playerVec, &enemies);	
	
}

Game::~Game(){

	delete pl;
	delete ren;	
	delete window;
	
	pl = NULL;
	ren = NULL;
	window = NULL;
	
}

void Game::initVariables(){
	window = nullptr;

	// Game logic
	points = 0;
	health = 100;

	mouseHeld = false;

}

void Game::initWindow(){
	videoMode.width = 1200;			// accessing 
	videoMode.height = 800;			// accessing 

	window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);		// window properties

	window->setFramerateLimit(60);		// FPS limit
}

const bool Game::isRunning() const{
	return window->isOpen();
}

// eventualy serperate this
void Game::pollEvents(){
	// Used internally in this->update()
	while (window->pollEvent(event)){ // 
            switch (event.type){
                
                case sf::Event::Closed:
                    window->close();
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape){
                        window->close();
                    break;
                    }
                
                default:
                    break;   
            }
        }
}

void Game::updateMousePositions(){
	// Updates the mouse position relative to window (Vector2i)
	mousePosWindow = sf::Mouse::getPosition(*window);
	mousePosView = window->mapPixelToCoords(mousePosWindow);
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

	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
	// 	playerVec[0].move(5.f, 0.f)
	// }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		playerVec[0].move(-5.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		playerVec[0].move(5.f, 0.f);
	}
}

void Game::update(){

	// Calling polling of event/update functions
	pollEvents();	
	updateMousePositions();				// track mouse positions
	checkInputs();
	
	en->updateEnemy();
	
}


void Game::render(){
	ren->render();

}

// Debug: move this to destructor
// void Game::deleteOnClose(){
// 	delete window;
// 	delete ren;
// }
