#ifndef ISOTILE_H
#define ISOTILE_H

class isoTile : public sf::Drawable
{
	/*
	* @class isoTile
	* @file isoTile.h
	* @brief Abstarct class for isoTiles which inherites from sf::Drawable
	* 
	* @details In this class the position of each tile is calculated and then drawn to the screen since the class inherited from sf::Drawable.
	*/
private:
	//STATIC_CONST_VARS
	static const int TILE_WIDTH = 32;
	static const int TILE_HEIGHT = 32;

	static const int WINDOW_WIDTH = 512;

	static const int x_start = WINDOW_WIDTH / 2 - TILE_WIDTH / 2;
	static const int y_start = TILE_HEIGHT;
	
	//Tile sprite and Texture
	sf::Sprite tile;
	sf::Texture tileTexture;

	/*Overriden draw() function*/
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	//Functions
	bool load(unsigned int x, unsigned int y);
};

#endif // !ISOTILE_H