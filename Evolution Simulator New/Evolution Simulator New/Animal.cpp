#include "Animal.h"
#include <random>


Animal::Animal() {
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_real_distribution<> movementDistribution(-1000, 1000);

	body.setRadius(8.0f);
	// this gives a red color with some variation
	body.setFillColor(sf::Color(rand() % 106 + 150, rand() % 75, rand() % 75));
	body.setOutlineThickness(1.0f);
	body.setOutlineColor(sf::Color::Black);

	body.setOrigin(sf::Vector2f(body.getRadius(), body.getRadius()));
	body.setPosition(sf::Vector2f(rand() % 784 + 8, rand() % 784 + 8));

	velocity = sf::Vector2f(1.0f, 1.0f);
	xOffset = static_cast<float>(movementDistribution(mt)) / 10000;
	yOffset = static_cast<float>(movementDistribution(mt)) / 10000;

	myTimeSinceLastMeal = 0.0f;
	myMacroMovementDeltaTime = 0.0f;
	myMicroMovementDeltaTime = 0.0f;
}


Animal::~Animal(){
}

void Animal::Update(float deltaTime) {
	/*
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_real_distribution<float> movementDistribution(-200, 200);
	std::uniform_real_distribution<float> myDeltaTimeDistribution(25, 75);


	timeSinceLastMeal += deltaTime;
	myDeltaTime += deltaTime;

	// this conditional ensures the creature won't move outside the box
	//if (body.getPosition().x + velocity.x < 792 && body.getPosition().y + velocity.y < 792 && body.getPosition().x + velocity.x > 8 && body.getPosition().y + velocity.y > 8) {
	//	body.setPosition(sf::Vector2f(body.getPosition().x + velocity.x, body.getPosition().y + velocity.y));
	//}

	// Random motion 
	if (myDeltaTime > myDeltaTimeDistribution(mt) / 10) {
		myDeltaTime = 0.0f;
		xOffset = (-2) + static_cast <float>(rand()) / (static_cast <float>(RAND_MAX / (2 + 2)));
		yOffset = (-2) + static_cast <float>(rand()) / (static_cast <float>(RAND_MAX / (2 + 2)));
	}

	if (body.getPosition().x + xOffset < 792 && body.getPosition().y + yOffset < 792 && body.getPosition().x + xOffset > 8 && body.getPosition().y + yOffset > 8) {
		body.move(xOffset, yOffset);
	}
	*/
	std::random_device rd;
	std::mt19937 mt(rd());

	std::uniform_real_distribution<> movementDistribution(-1000, 1000);
	std::uniform_real_distribution<> movementDistribution2(-500, 500);
	std::uniform_real_distribution<> macroDirectionChangeDistribution(5, 75);
	std::uniform_real_distribution<> microDirectionChangeDistribution(1, 10);
	
	myTimeSinceLastMeal += deltaTime;
	myMacroMovementDeltaTime += deltaTime;
	myMicroMovementDeltaTime += deltaTime;

	if (myMacroMovementDeltaTime > macroDirectionChangeDistribution(mt) / 10) {
		myMacroMovementDeltaTime = 0;
		xOffset = static_cast<float>(movementDistribution(mt)) / 10000;
		yOffset = static_cast<float>(movementDistribution(mt)) / 10000;
	}

	if (myMicroMovementDeltaTime > microDirectionChangeDistribution(mt) / 10) {
		myMicroMovementDeltaTime = 0;
		xOffset += static_cast<float>(movementDistribution2(mt)) / 10000;
		yOffset += static_cast<float>(movementDistribution2(mt)) / 10000;
	}

	if (body.getPosition().x + xOffset < 792 && body.getPosition().y + yOffset < 792 && body.getPosition().x + xOffset > 8 && body.getPosition().y + yOffset > 8) {
		body.move(xOffset, yOffset);
	}
}
