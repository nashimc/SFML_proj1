#include "weapon.hpp"

// needs pos of player
Weapon::Weapon(float* playerPosX, float* playerPosY, std::vector<sf::CircleShape>* projectileVec)
:	playerPosX(playerPosX),
	playerPosY(playerPosY),
	projectileVec(projectileVec)
{}

Weapon::~Weapon(){
	playerPosX = NULL;
	playerPosY = NULL;
	projectileVec = NULL;
}

void Weapon::weapon_1(){
	projectile.setRadius(6);
	projectile.setPosition(*playerPosX + 25, *playerPosY);	
	projectile.setFillColor(sf::Color::Red);
	projectile.setOutlineColor(sf::Color::Red);
	projectile.setOutlineThickness(1.f);

	projectileVec->push_back(projectile);

}

// needs pos of player to fire from
void Weapon::shootProjectile(){
	weapon_1();	
}


void Weapon::moveProjectile(){
	for (int i = 0; i < projectileVec->size(); ++i){
		(*projectileVec)[i].move(0.f, -projectileSpeed);
	}
}

// // idea 1	- push_back and pop different projectile for diff weapons
// // 			- cycle weapons
// void Weapon::changeWeapon(){
// 	// weaponSlot.push_back()...
// }