#pragma once

#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "enemy.hpp"




class Game{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	// Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// Controls
	bool mouseHeld;

	// Game logic
	int points;
	int health;
	bool deleted;

	// Game objects	
	std::vector<sf::RectangleShape> enemies;

	Enemy En{800, 600, points, health, mousePosView, &enemies};

public:
	// Constructor + Destructor
	Game();
	virtual ~Game();

	// Init
	void initVariables();
	void initWindow();
	// sf::RectangleShape initEnemies();

	// Accessors
	const bool isRunning() const;

	// Funcs
	

	void pollEvents();		// internally used in this->update()
	void updateMousePositions();
	void spawnRecEnemy();
	void spawnCircEnemy();
	void checkInputs();
	void update();
	void renderEnemies(sf::RenderTarget& target);
	void render();
};