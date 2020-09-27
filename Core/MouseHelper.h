#pragma once
#include <SFML\Graphics.hpp>

class MouseHelper {

public:
	static const sf::Vector2i& getPreviousMousePosition();
	static const sf::Vector2i& getLastMouseMoveOffset();
	static void updatePreviousMousePosition();
	static void reset();
};

