#include "GrassTile.h"

static sf::Texture* texture;

GrassTile::GrassTile() : TileBase() {
	if (texture == NULL) {
		texture = new sf::Texture();
		texture->loadFromFile("C:/Users/silaiev/Pictures/grass.png");
	}
	setTexture(texture);
}
