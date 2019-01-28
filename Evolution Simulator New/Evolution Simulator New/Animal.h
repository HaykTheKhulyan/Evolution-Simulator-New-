#pragma once
#include <Graphics.hpp>

/*

capabilities:
breeding
variability
movement
dying

*/

class Animal
{
public:
	Animal();
	~Animal();

	void Draw(sf::RenderWindow& window) { window.draw(body); }
	void Update(float deltaTime);

	sf::Vector2f getPosition() { return body.getPosition(); }

private:
	sf::CircleShape body;

	sf::Vector2f velocity;

	float xOffset;
	float yOffset;

	float myTimeSinceLastMeal;
	float myMacroMovementDeltaTime;
	float myMicroMovementDeltaTime;

};

