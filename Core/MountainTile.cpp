#include "MountainTile.h"

static sf::Texture* texture;

MountainTile::MountainTile() : TileBase() {
	if (texture == NULL) {
		texture = new sf::Texture();
		texture->loadFromFile("C:/Users/silaiev/Pictures/mountain.png");
	}
	setTexture(texture);
}
