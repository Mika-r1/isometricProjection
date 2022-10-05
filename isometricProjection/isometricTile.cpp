#include "isometricTile.h"

//Private functions
sf::Vector2f isometricTile::calculateScreenPositions(unsigned int pos_x, unsigned int pos_y)
{
	int x_screen = x_start + (pos_x - pos_y) * (TILE_WIDTH / 2);
	int y_screen = y_start + (pos_x + pos_y) * (TILE_HEIGHT / 2) / 2;

	return sf::Vector2f(static_cast<float>(x_screen), static_cast<float>(y_screen));
}

//Constructor / Destructor
isometricTile::isometricTile()
{
	
}

isometricTile::isometricTile(unsigned int pos_x, unsigned int pos_y)
{
	if (!this->tileTexture.loadFromFile("Tile.png"))
		std::cerr << "ERROR::RENDERTILES.CPP::INIT::Failed loading texture: Tile.png" << std::endl;

	this->tile.setTexture(tileTexture);
	this->tile.setPosition(calculateScreenPositions(pos_x, pos_y));	
}

isometricTile::~isometricTile()
{

}

//Functions
void isometricTile::render(sf::RenderTarget& target)
{
	target.draw(this->tile);
}