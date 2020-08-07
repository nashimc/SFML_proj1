#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class ObjectDrawTrans : public sf::Drawable, public sf::Transformable{
private:

public:
		ObjectDrawTrans();
		~ObjectDrawTrans();

};