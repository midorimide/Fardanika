#include "MountainTile.h"
#include "ResourceLoader.h"
#include "resource.h"

static sf::Texture* texture;

MountainTile::MountainTile() : TileBase() {
	if (texture == NULL) {
		texture = new sf::Texture();
		texture->loadFromImage(ResourceLoader::loadImage(IDB_BITMAP1));
	}
	setTexture(texture);
}
