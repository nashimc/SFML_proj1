#pragma once

#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Weapon{

private:

	float* playerPosX;	
	float* playerPosY;

	sf::CircleShape projectile;
	std::vector<sf::CircleShape>* projectileVec;
	// float projectileMass;
	float projectileSpeed = 5.f;
	// float projectileDamage = projectileMass * projectileSpeed;


public:
	Weapon(float* playerPosX, float* playerPosY, std::vector<sf::CircleShape>* projectileVec);
	~Weapon();
	
	void weapon_1();
	void shootProjectile();
	void moveProjectile();
	void changeWeapon();


};