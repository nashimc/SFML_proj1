#pragma once

#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "render.hpp"
#include "objectdrawtrans.hpp"
#include "enemy.hpp"
#include "player.hpp"

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
	std::vector<sf::CircleShape> playerVec;
	std::vector<sf::RectangleShape> enemies;

	Player* pl;
	Enemy* en;
	Render* ren;

	

public:
	// Constructor + Destructor
	Game();
	virtual ~Game();

	// Init
	void initVariables();
	void initWindow();

	// Accessors
	const bool isRunning() const;

	// Funcs
	void pollEvents();			// internally used in this->update()
	void updateMousePositions();
	void checkInputs();
	void update();
	void render();

	// Debug
	void deleteOnClose(); 	
};