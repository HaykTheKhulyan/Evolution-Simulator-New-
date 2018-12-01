#pragma once
#include <Graphics.hpp>

/*
have different food values in the future which animals can potentially sense?
	-both intelligence and "vision" should influence this. ie a cheeseburger gives more value than lettuce (for intelligence)

have food go bad, which makes it give less food value / make animals sick?
	-some animals can handle more rotted food?

*/

class Food
{
public:
	Food();
	~Food();

	void Draw(sf::RenderWindow& window) { window.draw(body); }


private:
	sf::CircleShape body;
};

