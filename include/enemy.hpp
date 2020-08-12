#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
// #include "objectdrawtrans.hpp"

class Enemy{
	
private:
	static int width;
	static int height;

	sf::RectangleShape recEnemy;
	std::vector<sf::RectangleShape>* enemies;

	int maxEnemies = 5;
	float enemySpawnTimer = 0.f; 
	float enemySpawnTimerMax = 100.f;



public:
	Enemy(std::vector<sf::RectangleShape>* enemies);
	virtual ~Enemy();
	
	void createRecEnemy();
	void spawnEnemy();
	void moveEnemy();
	void updateEnemy();

};

