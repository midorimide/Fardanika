#include "GrassTile.h"
#include "ResourceLoader.h"
#include "resource.h"

static sf::Texture* texture;

GrassTile::GrassTile() : TileBase() {
	if (texture == NULL) {
		texture = new sf::Texture();
		texture->loadFromImage(ResourceLoader::loadImage(IDB_BITMAP4));
	}
	setTexture(texture);
}
