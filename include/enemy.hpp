#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Enemy : public sf::RectangleShape{
private:
	int width;
	int height;
	int& points;
	int& health;
	sf::Vector2f& mousePosView;
	
	bool mouseHeld = false;
	bool deleted;

	sf::RectangleShape recEnemy;
	std::vector<RectangleShape>* enemies;

	int maxEnemies = 5;
	float enemySpawnTimer = 0.f; 
	float enemySpawnTimerMax = 100.f;



public:
	Enemy(int width, int height, int& points, int& health, sf::Vector2f& mousePosView, std::vector<sf::RectangleShape>* enemies);
	virtual ~Enemy();
	void spawnRecEnemy();
	void updateEnemies();




};

