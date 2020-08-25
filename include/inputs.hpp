#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "weapon.hpp"

class Inputs{
private:

	sf::CircleShape* player;
	Weapon* wep;

public:
	Inputs(sf::CircleShape* player, Weapon* wep);
	~Inputs();

	void keyboardInputs();


};
