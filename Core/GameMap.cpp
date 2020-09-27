#include "GameMap.h"

static float width;
static float heigth;
static std::vector<std::vector<TileBase*>> map(GameMap::DEFAULT_MAP_HEIGHT, std::vector<TileBase*>(GameMap::DEFAULT_MAP_WIDTH));

void GameMap::drawMap(sf::RenderWindow& window) {
    for (auto& row : map) {
        for (auto& hex : row) {
            window.draw(*hex);
        }
    }
}

const std::vector<std::vector<TileBase*>>& GameMap::getMap() {
    return map;
}

void GameMap::setMap(const std::vector<std::vector<TileBase*>>& newMap) {
    map = newMap;
    const int newMapHeigth = map.size();
    const int newMapWidth = map[0].size();
    heigth = map.size() * ROW_HEIGHT + TileBase::HEX_WIREFRAME_Y_OFFSET;
    width = (newMapWidth / 2 + newMapWidth % 2) * COL_WIDTH + (1. - newMapWidth % 2) * TileBase::HEX_WIREFRAME_X_OFFSET;
}

const sf::Vector2f GameMap::getSize() {
    return sf::Vector2f(width, heigth);
}

void GameMap::initDefaultMap() {
    static std::vector<std::vector<TileBase*>> map(DEFAULT_MAP_HEIGHT, std::vector<TileBase*>(DEFAULT_MAP_WIDTH));
    static bool accessed = false;
    if (!accessed) {
        accessed = true;
        for (int i = 0; i < DEFAULT_MAP_HEIGHT; i++) {
            for (int j = 0; j < DEFAULT_MAP_WIDTH; j++) {
                switch (rand() % 4) {
                case 0:
                    map[i][j] = new CropFieldTile();
                    break;
                case 1:
                    map[i][j] = new MountainTile();
                    break;
                case 2:
                    map[i][j] = new GrassTile();
                    break;
                case 3:
                    map[i][j] = new ForestTile();
                    break;
                default:
                    map[i][j] = new GrassTile();
                    break;
                }
                map[i][j]->setPosition((j + 1) * HEX_MAP_X_OFFSET, (i * 2 + j % 2) * HEX_MAP_Y_OFFSET + TileBase::HEX_SIDE_SIZE);
            }
        }
    }
    setMap(map);
}
