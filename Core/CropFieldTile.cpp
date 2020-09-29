#include "CropFieldTile.h"
#include "ResourceLoader.h"
#include "resource.h"

static sf::Texture* texture;

CropFieldTile::CropFieldTile() : TileBase() {
	if (texture == NULL) {
		texture = new sf::Texture();
		texture->loadFromImage(ResourceLoader::loadImage(IDB_BITMAP3));
	}
	setTexture(texture);
}
