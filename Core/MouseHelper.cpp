#include "MouseHelper.h"

static sf::Vector2i previousMousePosition;
static sf::Vector2i lastMouseMoveOffset;

const sf::Vector2i& MouseHelper::getPreviousMousePosition() {
    return previousMousePosition;
}

const sf::Vector2i& MouseHelper::getLastMouseMoveOffset() {
    return lastMouseMoveOffset;
}

void MouseHelper::updatePreviousMousePosition() {
    const sf::Vector2i mousePosition = sf::Mouse::getPosition();
    lastMouseMoveOffset = mousePosition - previousMousePosition;
    previousMousePosition = mousePosition;
}

void MouseHelper::reset() {
    lastMouseMoveOffset = sf::Vector2i(0, 0);
    previousMousePosition = sf::Mouse::getPosition();
}

