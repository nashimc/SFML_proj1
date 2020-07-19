#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Render : public sf::RectangleShape{
private:
	sf::RenderWindow* window;
	std::vector<RectangleShape>* enemies;

public:
	Render(sf::RenderWindow* window, std::vector<RectangleShape>* enemies);
	virtual ~Render();

	void renderEnemies();

	void render();
};