#pragma once
#include "MathConstants.h"
#include <SFML\Graphics.hpp>

class TileBase : public sf::ConvexShape {

public:
	static constexpr int HEX_SIDE_SIZE = 40;
	static constexpr float HEX_WIREFRAME_X_OFFSET = HEX_SIDE_SIZE * SIN_PI_DIV_3;
	static constexpr float HEX_WIREFRAME_Y_OFFSET = HEX_SIDE_SIZE * COS_PI_DIV_3;
	static constexpr float HEX_WIDTH = 2 * HEX_WIREFRAME_X_OFFSET;
	static constexpr float HEX_HEIGHT = 4 * HEX_WIREFRAME_Y_OFFSET;
protected:
	TileBase();
private:
	static const sf::ConvexShape& getDrawTileWireframe();
	static const sf::ConvexShape& getDefaultTile();
};

