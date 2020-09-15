#include "MapGraphics.h"

constexpr int HEX_SIDE_SIZE = 10;
constexpr double PI = 3.14159265358979323846;
constexpr int WIDTH = 40;
constexpr int HEIGHT = 40;
constexpr double HEX_Y_OFFSET = HEX_SIDE_SIZE / 2.;
constexpr double HEX_HEIGHT = 4 * HEX_Y_OFFSET;
constexpr double HEX_HEIGHT2 = 3 * HEX_Y_OFFSET;
const double HEX_X_OFFSET = HEX_SIDE_SIZE * sin(PI / 3.);
const double HEX_WIDTH = 2 * HEX_X_OFFSET;

void MapGraphics::drawMap(sf::RenderWindow& window) {
    for (auto& row : initMap()) {
        for (auto& hex : row) {
            window.draw(hex);
        }
    }
}

const sf::ConvexShape& MapGraphics::getHexWireframe() {
    static sf::ConvexShape hex(6);
    static bool accessed = false;
    if (!accessed) {
        accessed = true;
        hex.setPoint(0, sf::Vector2f(0, -HEX_SIDE_SIZE));
        hex.setPoint(1, sf::Vector2f(HEX_X_OFFSET, -HEX_Y_OFFSET));
        hex.setPoint(2, sf::Vector2f(HEX_X_OFFSET, HEX_Y_OFFSET));
        hex.setPoint(3, sf::Vector2f(0, HEX_SIDE_SIZE));
        hex.setPoint(4, sf::Vector2f(-HEX_X_OFFSET, HEX_Y_OFFSET));
        hex.setPoint(5, sf::Vector2f(-HEX_X_OFFSET, -HEX_Y_OFFSET));
    }
    return hex;
}

const sf::ConvexShape& MapGraphics::getDefaultHex() {
    static sf::ConvexShape hex(getHexWireframe());
    static bool accessed = false;
    if (!accessed) {
        accessed = true;
        hex.setFillColor(sf::Color::Green);
        hex.setOutlineColor(sf::Color::Black);
        hex.setOutlineThickness(1);
    }
    return hex;
}

const std::vector<std::vector<sf::ConvexShape>> MapGraphics::initMap() {
    static std::vector<std::vector<sf::ConvexShape>> map(HEIGHT, std::vector<sf::ConvexShape>(WIDTH, getDefaultHex()));
    static bool accessed = false;
    if (!accessed) {
        accessed = true;
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                map[i][j].setPosition(j * HEX_X_OFFSET, (i * 2 + j % 2) * HEX_HEIGHT2);
            }
        }
    }
    return map;
}
