#include "Food.h"
#include <stdlib.h>
#include <time.h>



Food::Food() {
	/* initialize random seed: */

	body.setRadius(5.0f);
	body.setFillColor(sf::Color(rand() % 100, rand() % 156 + 100, rand() % 100));
	body.setOutlineThickness(1.0f);
	body.setOutlineColor(sf::Color::Black);

	body.setOrigin(sf::Vector2f(body.getRadius(), body.getRadius()));
	body.setPosition(sf::Vector2f(rand() % 790 + 10, rand() % 790 + 10));
}


Food::~Food() {

}
