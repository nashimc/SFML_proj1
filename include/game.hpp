#pragma once

#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>




class Game{
private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	// Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// Game logic
	int points;
	int health;
	bool deleted;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	// Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;



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
	void spawnEnemy();

	void pollEvents();		// internally used in this->update()
	void updateMousePositions();
	void updateEnemies();
	void update();
	void renderEnemies(sf::RenderTarget& target);
	void render();
};