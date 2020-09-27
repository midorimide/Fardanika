#include "CropFieldTile.h"

static sf::Texture* texture;

CropFieldTile::CropFieldTile() : TileBase() {
	if (texture == NULL) {
		texture = new sf::Texture();
		texture->loadFromFile("C:/Users/silaiev/Pictures/wheat.png");
	}
	setTexture(texture);
}
