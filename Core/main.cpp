#include <SFML/Graphics.hpp>

constexpr int HEX_SIDE_SIZE = 10;
constexpr double PI = 3.14159265358979323846;
constexpr int WIDTH = 40;
constexpr int HEIGHT = 40;
constexpr double HEX_Y_OFFSET = HEX_SIDE_SIZE / 2.;
constexpr double HEX_HEIGHT = 4 * HEX_Y_OFFSET;
constexpr double HEX_HEIGHT2 = 3 * HEX_Y_OFFSET;
const double HEX_X_OFFSET = HEX_SIDE_SIZE * sin(PI / 3.);
const double HEX_WIDTH = 2 * HEX_X_OFFSET;

sf::ConvexShape getHexWireframe() {
    sf::ConvexShape hex(6);
    hex.setPoint(0, sf::Vector2f(0, -HEX_SIDE_SIZE));
    hex.setPoint(1, sf::Vector2f(HEX_X_OFFSET, -HEX_Y_OFFSET));
    hex.setPoint(2, sf::Vector2f(HEX_X_OFFSET, HEX_Y_OFFSET));
    hex.setPoint(3, sf::Vector2f(0, HEX_SIDE_SIZE));
    hex.setPoint(4, sf::Vector2f(-HEX_X_OFFSET, HEX_Y_OFFSET));
    hex.setPoint(5, sf::Vector2f(-HEX_X_OFFSET, -HEX_Y_OFFSET));
    return hex;
}

const sf::ConvexShape HEX_WIREFRAME = getHexWireframe();

sf::ConvexShape getDefaultHex() {
    sf::ConvexShape hex(HEX_WIREFRAME);
    hex.setFillColor(sf::Color(0, 255, 0));
    hex.setOutlineColor(sf::Color(0, 0, 0));
    hex.setOutlineThickness(1);
    return hex;
}

const sf::ConvexShape DEFAULT_HEX = getDefaultHex();

std::vector<std::vector<sf::ConvexShape>> initMap() {
    std::vector<std::vector<sf::ConvexShape>> map(HEIGHT, std::vector<sf::ConvexShape>(WIDTH, DEFAULT_HEX));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j].setPosition(j * HEX_X_OFFSET, (i * 2 + j % 2) * HEX_HEIGHT2);
        }
    }
    return map;
}

const std::vector<std::vector<sf::ConvexShape>> MAP = initMap();

int main() {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    initMap();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (auto& row : MAP) {
            for (auto& hex : row) {
                window.draw(hex);
            }
        }
        window.display();
    }

    return 0;
}