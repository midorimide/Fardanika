#include "GameMap.h"
#include "MouseHelper.h"
#include <SFML/Graphics.hpp>

sf::View panView(sf::View view, sf::Vector2f panVector) {
	view.move(panVector);
	sf::Vector2f viewCenter = view.getCenter();
	sf::Vector2f viewSize = view.getSize();
	sf::Vector2f viewSizeHalfed(viewSize.x / 2, viewSize.y / 2);

	sf::Vector2f bottomRightOverflow = viewCenter + viewSizeHalfed - GameMap::getSize();
	view.move(-std::max(0.f, bottomRightOverflow.x), -std::max(0.f, bottomRightOverflow.y));

	sf::Vector2f topLeftOverflow = viewCenter - viewSizeHalfed;
	view.move(-std::min(0.f, topLeftOverflow.x), -std::min(0.f, topLeftOverflow.y));

	return view;
}

int main() {
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Fardanika", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);

	MouseHelper::reset();
	GameMap::initDefaultMap();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseMoved) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
					window.setView(panView(window.getView(), -sf::Vector2f(MouseHelper::getLastMouseMoveOffset())));
				}
				MouseHelper::updatePreviousMousePosition();
			}
		}
		window.clear();
		GameMap::drawMap(window);
		window.display();
	}

	return 0;
}
