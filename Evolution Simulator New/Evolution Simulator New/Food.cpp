#include "Food.h"
#include <stdlib.h>
#include <time.h>



Food::Food() {
	/* initialize random seed: */

	body.setRadius(2.0f);
	// this gives a green color with some variation
	body.setFillColor(sf::Color(rand() % 100, rand() % 156 + 100, rand() % 100));
	body.setOutlineThickness(1.0f);
	body.setOutlineColor(sf::Color::Black);

	body.setOrigin(sf::Vector2f(body.getRadius(), body.getRadius()));
	body.setPosition(sf::Vector2f(rand() % 784 + 8, rand() % 784 + 8));
}


Food::~Food() {

}
