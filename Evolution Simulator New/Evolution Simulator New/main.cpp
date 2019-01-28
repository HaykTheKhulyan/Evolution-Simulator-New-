#include <Graphics.hpp>
#include <vector>
#include "Food.h"
#include "Animal.h"
#include <stdlib.h>
#include <time.h>

int main() {
	// generates a new seed
	srand(time(NULL));

	// creates the window
	sf::RenderWindow window(sf::VideoMode(800, 800), "The Arena", sf::Style::Close | sf::Style::Titlebar);

	// controls how often food spawns (foodRate of 2.0 doubles food spawn rate, 4.0 quadruples, etc)
	float foodRate = 1;

	// starting number of animals
	int startingPopulationSize = 100;

	// stores all the food on the map
	std::vector<Food> foodVector;

	// stores each creature
	std::vector<Animal> animalVector;

	for (int i = 0; i < startingPopulationSize; i++) {
		animalVector.emplace_back();
	}



	// tracks the time since the window begins, incremented every loop
	float deltaTime = 0.0f;
	sf::Clock clock;

	// keeps track of time for food generation
	float foodCounter = 0.0f;

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		foodCounter += deltaTime;

		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}

		// updates all the animals in animalVector
		for (int i = 0; i < animalVector.size(); i++) {
			animalVector.at(i).Update(deltaTime);
		}

		// makes a new food object based on the foodRate
		if (foodCounter > 0.333) {
			foodVector.emplace_back();
			foodCounter = 0;
		}

		window.clear(sf::Color::White);

		// draws all the food objects
		for (int i = 0; i < foodVector.size(); i++) {
			foodVector.at(i).Draw(window);
		}

		// draws all the animal objects
		for (int i = 0; i < animalVector.size(); i++) {
			animalVector.at(i).Draw(window);
		}

		window.display();
	}
	return 0;
}