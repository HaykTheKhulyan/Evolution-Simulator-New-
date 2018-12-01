#include <Graphics.hpp>
#include "Food.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "The Arena", sf::Style::Close | sf::Style::Titlebar);
	srand(time(NULL));

	// controls how often food spawns (foodRate of 2.0 doubles food spawn rate, 4.0 quadruples, etc)
	float foodRate = 1.0;

	Food foodList[2500];


	for (int i = 0; i < 2500; i++) {
		Food newFood;
		foodList[i] = newFood;
	}



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

		window.clear(sf::Color::White);

		for (int i = 0; i < 2500; i++) {
			foodList[i].Draw(window);
		}

		window.display();
	}
	return 0;
}