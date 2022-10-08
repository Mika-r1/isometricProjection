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
	//Tile properties
	static const int TILE_WIDTH = 32;
	static const int TILE_HEIGHT = 32;

	//Window properties
	static const int WINDOW_WIDTH = 512;

	//Starting positions for the first Tile (Basically middle of the screen here)
	static const int x_start = WINDOW_WIDTH / 2 - TILE_WIDTH / 2;
	static const int y_start = TILE_HEIGHT;

	//Tile Shape and Texture
	sf::Texture tileTexture;
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