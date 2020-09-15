#pragma once
#include <SFML/Graphics.hpp>

class MapGraphics {

public:
	static void drawMap(sf::RenderWindow& window);

private:

	static const sf::ConvexShape& getHexWireframe();
	static const sf::ConvexShape& getDefaultHex();
	static const std::vector<std::vector<sf::ConvexShape>> initMap();
};

