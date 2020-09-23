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
	projectile.setPosition(*playerPosX + 25, *playerPosY);
	projectile.setOutlineThickness(1.f);
	if (chosenWeapon == 1){
		projectile.setRadius(5);
		projectile.setFillColor(sf::Color::Red);
		projectile.setOutlineColor(sf::Color::Red);
	}	
	if (chosenWeapon == 2){
		projectile.setRadius(10);
		projectile.setFillColor(sf::Color::Blue);
		projectile.setOutlineColor(sf::Color::Blue);
	}
	if (chosenWeapon == 3){
		projectile.setRadius(10);
		projectile.setFillColor(sf::Color::White);
		projectile.setOutlineColor(sf::Color::White);
	}		
	
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


void Weapon::cycleWeaponForward(){
	chosenWeapon += 1;
	if (chosenWeapon > 3){
		chosenWeapon = 1;
	}
}

void Weapon::cycleWeaponBackward(){
	chosenWeapon -= 1;
	if (chosenWeapon < 1){
		chosenWeapon = 3;
	}
}


// // idea 1	- push_back and pop different projectile for diff weapons
// // 			- cycle weapons
// void Weapon::changeWeapon(){
// 	// weaponSlot.push_back()...
// }