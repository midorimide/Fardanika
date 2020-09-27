#include "ForestTile.h"

static sf::Texture* texture;

ForestTile::ForestTile() {
	if (texture == NULL) {
		texture = new sf::Texture();
		texture->loadFromFile("forest.png");
	}
	setTexture(texture);
}
