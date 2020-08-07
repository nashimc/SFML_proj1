#include "enemy.hpp"

int Enemy::width = 1200;
int Enemy::height = 800;

Enemy::Enemy(int& points, int& health, std::vector<sf::RectangleShape>* enemies)
:	points(points),
	health(health),
	enemies(enemies)
{}

Enemy::~Enemy(){

	enemies = NULL;
}


void Enemy::spawnRecEnemy(){


	this->recEnemy.setSize(sf::Vector2f(32.f, 32.f));
	this->recEnemy.setPosition(static_cast<float>((rand() % static_cast<int>(1168))), 0.f);		// rand() only takes int, then converting into float

	this->recEnemy.setFillColor(sf::Color::Cyan);
	this->recEnemy.setOutlineColor(sf::Color::Cyan);
	this->recEnemy.setOutlineThickness(1.f);

	enemies->push_back(this->recEnemy);

}

void Enemy::updateEnemies(){
	
	// Updating timer for enemy spawns
	if (enemies->size() < this->maxEnemies){
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax){
			// Spawn enemy and reset timer
			this->spawnRecEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else{
			this->enemySpawnTimer += 1.f;
		}
	}
	else{
		// std::cout << "enemies.size() >= max" << std::endl;
	}

	//////////////////////////////////////////////////////////////////////////

	// Move enemies
	for (int i = 0; i < enemies->size(); ++i){

		this->deleted = false; // may need to change this to game deleted or get pointe/ref to here

		(*enemies)[i].move(0.f, 3.f);
		if ((*enemies)[i].getPosition().y > 1200){ 
			enemies->erase(enemies->begin() + i);
			health = health - 10;
			if (health <= 0){
				// game over
			}
			std::cout << "Health: " << health << std::endl;;		
		}
	}
}
