#pragma once

#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "render.hpp"
#include "inputs.hpp"
#include "objectdrawtrans.hpp"
#include "enemy.hpp"
#include "player.hpp"
#include "weapon.hpp"

class Game{

private:
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	// Positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	// sf::Vector2f playerPos;
	float playerPosX;
	float playerPosY;

	// Controls
	bool mouseHeld;

	// Game logic
	int points;
	int health;
	bool deleted;

	// Game objects	
	sf::CircleShape player;
	std::vector<sf::RectangleShape> enemies;
	std::vector<sf::CircleShape> projectileVec;

	Player* pl;
	Enemy* en;
	Weapon* wep;
	Inputs* input;
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
	void pollEvents();				// internally used in this->update()
	void gameLogic();
	void updatePositions();			// get mouse position
	void checkInputs();				
	void update();
	void render();

	// Debug
	void deleteOnClose(); 	
};
