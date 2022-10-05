//Includes
#include "stdafx.h"
#include "isometricTile.h"

//Private functions
sf::Vector2f isometricTile::calculateScreenPositions(unsigned int pos_x, unsigned int pos_y)
{
	/*
	* @return sf::Vector2f
	* 
	* @param pos_x, unsigned int for the x component of the Tile's position
	* @param pos_y, unsigned int for the y component of the Tile's position
	* 
	* @brief Calculates the screen coordinates of each Tile. 
	*/
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
	/*OVERLOADED CONSTRUCTOR/*
	* 
	* @param pos_x, unsigned int for the x component of the new Tile's position
	* @param pos_y, unsigned int for the y component of the new Tile's position
	*/
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
	/*
	* @return void
	* 
	* @param target, sf::RenderTarget& is used as reffernce for a something to draw on
	* 
	* @brief Draws the Tile on the Screen.
	*/
	target.draw(this->tile);
}