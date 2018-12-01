#include "Animal.h"



Animal::Animal() {
	body.setRadius(8.0f);
	// this gives a red color with some variation
	body.setFillColor(sf::Color(rand() % 106 + 150, rand() % 75, rand() % 75));
	body.setOutlineThickness(1.0f);
	body.setOutlineColor(sf::Color::Black);

	body.setOrigin(sf::Vector2f(body.getRadius(), body.getRadius()));
	body.setPosition(sf::Vector2f(rand() % 784 + 8, rand() % 784 + 8));

	velocity = sf::Vector2f(0.01f, 0.01f);
	timeSinceLastMeal = 0.0f;
}


Animal::~Animal(){
}

void Animal::Update(float deltaTime) {
	timeSinceLastMeal += deltaTime;

	if (body.getPosition().x + velocity.x < 792 && body.getPosition().y + velocity.y < 792 && body.getPosition().x + velocity.x > 8 && body.getPosition().y + velocity.y > 8) {
		body.setPosition(sf::Vector2f(body.getPosition().x + velocity.x, body.getPosition().y + velocity.y));
	}



}
