#ifndef ISOMETRICTILE_H
#define ISOMETRICTILE_H

class isometricTile
{
	/*
	* @class isometricTile
	* @file isometricTile.h
	* @brief Abstract Super class to render Tiels
	* 
	* @details
	* With this class you can render multiple tiles.
	*/
private:
	/**STATIC_CONST_VARS**/
	//Starting positions for the first Tile (Basically middle of the screen here)
	static const int x_start = stdafx::WINDOW_WIDTH / 2 - stdafx::TILE_WIDTH / 2;
	static const int y_start = stdafx::TILE_HEIGHT;

	//Tile Shape and Texture
	sf::Sprite tile;

	//Private functions
	sf::Vector2f calculateScreenPositions(unsigned int pos_x, unsigned int pos_y, unsigned int pos_z);

public:
	//Constructor / Destructor
	isometricTile();
	isometricTile(sf::Texture* texture, unsigned int pos_x, unsigned int pos_y, unsigned int pos_z);
	virtual ~isometricTile();

	//Functions
	void render(sf::RenderTarget& target);
};

#endif // !ISOMETRICTILE_H