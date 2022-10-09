//Includes
#include "stdafx.h"
#include "isometricTile.h"

//Private functions
sf::Vector2f isometricTile::calculateScreenPositions(unsigned int pos_x, unsigned int pos_y, unsigned int pos_z)
{
	/*
	* @return sf::Vector2f
	*
	* @param pos_x, unsigned int for the x component of the Tile's position
	* @param pos_y, unsigned int for the y component of the Tile's position
	* @param pos_z, unsigned int for the optical z component of the new Tile's position
	*
	* @brief Calculates the screen coordinates of each Tile.
	*/
	int x_screen = x_start + (pos_x - pos_y) * (stdafx::TILE_WIDTH / 2);
	int y_screen = (y_start + ((pos_x + pos_y) * (stdafx::TILE_HEIGHT / 2) ) / 2) - (pos_z  * stdafx::TILE_HEIGHT / 2);

	return sf::Vector2f(static_cast<float>(x_screen), static_cast<float>(y_screen));
}

//Constructor / Destructor
isometricTile::isometricTile()
{

}

isometricTile::isometricTile(sf::Texture* texture, unsigned int pos_x, unsigned int pos_y, unsigned int pos_z)
{
	/*OVERLOADED CONSTRUCTOR/*
	*
	* @param texture, pointer to a texture that the Tile is supposed to have
	* @param pos_x, unsigned int for the x component of the new Tile's position
	* @param pos_y, unsigned int for the y component of the new Tile's position
	* @param pos_z, unsigned int for the optical z component of the new Tile's position
	*/
	this->tile.setTexture(*texture);
	this->tile.setPosition(calculateScreenPositions(pos_x, pos_y, pos_z));
}

isometricTile::~isometricTile()
{

}

//Functions
void isometricTile::render(sf::RenderTarget& target)
{
	/*
	* @return void
	*
	* @param target, sf::RenderTarget& is used as reffernce for a something to draw on
	*
	* @brief Draws the Tile on the Screen.
	*/
	target.draw(this->tile);
}