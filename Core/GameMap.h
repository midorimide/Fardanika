#pragma once
#include <SFML/Graphics.hpp>
#include "MathConstants.h"
#include "TileBase.h"
#include "CropFieldTile.h"
#include "MountainTile.h"
#include "GrassTile.h"
#include "ForestTile.h"

class GameMap {

public:
	static constexpr int DEFAULT_MAP_WIDTH = 80;
	static constexpr int DEFAULT_MAP_HEIGHT = 40;
	static constexpr float COL_WIDTH = TileBase::HEX_WIDTH;
	static constexpr float ROW_HEIGHT = 6 * TileBase::HEX_WIREFRAME_Y_OFFSET;
	static constexpr float HEX_MAP_X_OFFSET = TileBase::HEX_WIREFRAME_X_OFFSET;
	static constexpr float HEX_MAP_Y_OFFSET = 3 * TileBase::HEX_WIREFRAME_Y_OFFSET;

	static void drawMap(sf::RenderWindow& window);
	static const std::vector<std::vector<TileBase*>>& getMap();
	static void setMap(const std::vector<std::vector<TileBase*>>& newMap);
	static const sf::Vector2f getSize();
	static void initDefaultMap();
};
