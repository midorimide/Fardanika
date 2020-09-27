#include "TileBase.h"

TileBase::TileBase() : sf::ConvexShape(getDefaultTile()) {
}

const sf::ConvexShape& TileBase::getDrawTileWireframe() {
    static sf::ConvexShape hex(6);
    static bool accessed = false;
    if (!accessed) {
        accessed = true;
        hex.setPoint(0, sf::Vector2f(0, -HEX_SIDE_SIZE));
        hex.setPoint(1, sf::Vector2f(HEX_WIREFRAME_X_OFFSET, -HEX_WIREFRAME_Y_OFFSET));
        hex.setPoint(2, sf::Vector2f(HEX_WIREFRAME_X_OFFSET, HEX_WIREFRAME_Y_OFFSET));
        hex.setPoint(3, sf::Vector2f(0, HEX_SIDE_SIZE));
        hex.setPoint(4, sf::Vector2f(-HEX_WIREFRAME_X_OFFSET, HEX_WIREFRAME_Y_OFFSET));
        hex.setPoint(5, sf::Vector2f(-HEX_WIREFRAME_X_OFFSET, -HEX_WIREFRAME_Y_OFFSET));
        hex.setOutlineColor(sf::Color::Black);
        hex.setOutlineThickness(1);
    }
    return hex;
}

const sf::ConvexShape& TileBase::getDefaultTile() {
    static sf::ConvexShape hex(getDrawTileWireframe());
    static bool accessed = false;
    if (!accessed) {
        accessed = true;
        hex.setOutlineColor(sf::Color::Black);
        hex.setOutlineThickness(1);
    }
    return hex;
}