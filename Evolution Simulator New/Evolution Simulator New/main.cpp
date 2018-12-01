#include <Graphics.hpp>
#include <vector>
#include "Food.h"

int main() {
	// generates a new seed
	srand(time(NULL));

	// creates the window
	sf::RenderWindow window(sf::VideoMode(800, 800), "The Arena", sf::Style::Close | sf::Style::Titlebar);

	// controls how often food spawns (foodRate of 2.0 doubles food spawn rate, 4.0 quadruples, etc)
	float foodRate = 1;

	// stores all the food on the map. eaten food gets deleted.
	std::vector<Food> foodVector;





	// tracks the time since the window begins, incremented every loop
	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		deltaTime += clock.restart().asSeconds();

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

		if (deltaTime > .3 / foodRate) {
			foodVector.emplace_back();
			deltaTime = 0;
		}

		window.clear(sf::Color::White);

		for (int i = 0; i < foodVector.size(); i++) {
			foodVector.at(i).Draw(window);
		}

		window.display();
	}
	return 0;
}