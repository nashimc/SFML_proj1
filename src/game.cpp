#include <iostream>
#include "game.hpp"

// try an remove args of Render constructors
Game::Game(){
	initVariables();		// create window with nullptr first
	initWindow();

	pl = new Player(&player);
	en = new Enemy(&enemies);
	wep = new Weapon(&playerPosX, &playerPosY, &projectileVec);
	input = new Inputs(&player, wep);
	ren = new Render(window, &player, &enemies, &projectileVec);	

	
}

Game::~Game(){

	delete pl;
	delete en;
	delete wep;
	delete input;
	delete ren;	
	delete window;
	
	pl = NULL;
	en = NULL;
	wep = NULL;
	input = NULL;
	ren = NULL;
	window = NULL;
	
}

void Game::initVariables(){
	window = nullptr;

	// Game logic
	points = 0;
	health = 100;

	// Controls
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

void Game::gameLogic(){
	// check enemy positions
	for (int i = 0; i < enemies.size(); ++i){

		deleted = false; 

		if ((enemies)[i].getPosition().y > 1200){ 
			enemies.erase(enemies.begin() + i);
			deleted = true;
			health = health - 10;
			if (health <= 0){
				// game over
			}
			std::cout << "Health: " << health << std::endl;;		
		}
	}

	// check projectiles
	if (!projectileVec.empty()){
		wep->moveProjectile();
		for (int i; i < projectileVec.size(); ++i){
			if (projectileVec[i].getPosition().y < 0){
				projectileVec.erase(projectileVec.begin() + i);
			}
		}
	}

}

void Game::getPositions(){
	// Updates the mouse position relative to window (Vector2i)
	mousePosWindow = sf::Mouse::getPosition(*window);
	mousePosView = window->mapPixelToCoords(mousePosWindow);

	// init 
	playerPosX = player.getPosition().x;
	playerPosY = player.getPosition().y;
}

void Game::checkInputs(){
	// // Mouse controls
	// Check if enemies clicked
	// if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	// 	if (mouseHeld == false){
	// 		mouseHeld = true;
	// 		deleted = false;

	// 		for (int i = 0; i < enemies.size(); ++i){
	// 			if (enemies[i].getGlobalBounds().contains(mousePosView)){
	// 				deleted = true;
	// 				enemies.erase(enemies.begin() + i); // + i needed to erase i-th element

	// 				points = points + 1;
	// 				std::cout << "Points: " << points << std::endl;
	// 			}
	// 		}
	// 	}
	// }
	// else{
	// 	mouseHeld = false;
	// }

	input->keyboardInputs();
}

void Game::update(){

	// Calling polling of event/update functions
	pollEvents();	
	getPositions();				// track mouse positions
	checkInputs();
	gameLogic();
	
	en->updateEnemy();
	// need an updatePlayer for player losing  - dieing etc
	
}


void Game::render(){
	ren->render();

}

// Debug: move this to destructor
// void Game::deleteOnClose(){
// 	delete window;
// 	delete ren;
// }
