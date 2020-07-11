#include "game.hpp"

#include <iostream>

Game::Game(){
	this->initVariables();		// create window with nullptr first
	this->initWindow();
	// this->initEnemies();
	// this->spawnEnemy();
}

Game::~Game(){
	// delete this->window;
	
}

void Game::initVariables(){
	this->window = nullptr;

	// Game logic
	this->points = 0;
	this->health = 100;
	this->enemySpawnTimer = 0;
	this->enemySpawnTimerMax = 100.f;
	this->maxEnemies = 5;
	this->mouseHeld = false;
}

void Game::initWindow(){
	this->videoMode.width = 800;			// accessing sf::VideoMode variables
	this->videoMode.height = 600;			// accessing sf::VideoMode variables

	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);		// window properties

	this->window->setFramerateLimit(60);		// FPS limit
}

const bool Game::isRunning() const{
	return this->window->isOpen();
}

void Game::spawnEnemy(){
	this->enemy.setSize(sf::Vector2f(32.f, 32.f));
	this->enemy.setPosition(
							static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
							0.f
							);		// rand() only takes int, then converting into float

	this->enemy.setFillColor(sf::Color::Green);
	this->enemy.setOutlineColor(sf::Color::Black);
	this->enemy.setOutlineThickness(1.f);

	// Spawn enemy
	this->enemies.push_back(this->enemy);
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

void Game::updateEnemies(){

	// Updating timer for enemy spawns
	if (this->enemies.size() < this->maxEnemies){
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax){
			// Spawn enemy and reset timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else{
			this->enemySpawnTimer += 1.f;
		}
	}
	else{
		std::cout << "enemies.size() >= max" << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////

	// Move enemies
	for (int i = 0; i < this->enemies.size(); i++){

		this->deleted = false;

		this->enemies[i].move(0.f, 3.f);

		if (this->enemies[i].getPosition().y > this->window->getSize().y){
			this->enemies.erase(this->enemies.begin() + i);
			this->health = this->health - 10;
			if (this->health <= 0){
				// game over
			}
			std::cout << "Health: " << this->health << std::endl;;		
		}
	}

	////////////////////////////////////////////////////////////////////////////

	// Check if enemies clicked
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if (this->mouseHeld == false){
			this->mouseHeld = true;
			this->deleted = false;

			for (int i = 0; i < this->enemies.size(); ++i){
				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)){
					this->deleted = true;
					this->enemies.erase(this->enemies.begin() + i);

					this->points = points + 1;
					std::cout << "Points: " << this->points << std::endl;
				}
			}
		}
	}
	else{
		this->mouseHeld = false;
	}
}


	


void Game::update(){

	// Calling polling of event/update functions
	this->pollEvents();

	int enemySize = this->enemies.size();

	// std::cout << enemySize << std::endl;
	
	this->updateMousePositions();

	// std::cout << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;
	
	// std::cout << "enemies vector size = " << enemies.size() << ", enemy spawn timer = " << this->enemySpawnTimer << std::endl;
	

	this->updateEnemies();
}

void Game::renderEnemies(sf::RenderTarget& target){
	for (sf::RectangleShape &i : this->enemies){
		target.draw(i);
	}
}

void Game::render(){
	this->window->clear(sf::Color(0, 0, 0));


	// Draw objects
	this->renderEnemies(*this->window);		// dereference this->window
	

	this->window->display();
	

	
}