#pragma once
#include <SFML\Graphics.hpp>
#include <Windows.h>

class ResourceLoader {

public:
	static sf::Image loadImage(WORD name);
};

