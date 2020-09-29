#include "ForestTile.h"
#include "ResourceLoader.h"
#include "resource.h"

static sf::Texture* texture;

ForestTile::ForestTile() {
	if (texture == NULL) {
		texture = new sf::Texture();
		texture->loadFromImage(ResourceLoader::loadImage(IDB_BITMAP2));
	}
	setTexture(texture);
}
