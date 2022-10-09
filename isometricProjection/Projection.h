#ifndef PROJECTION_H
#define PROJECTION_H

//Includes
#include "isoTile.h"
#include "isometricTile.h"

class Projection
{
private:
	/*
	* @class Projection
	* @file Projection.h
	* @brief Abstract Super class for projection of isometric views 
	* 
	* @details The most things of projecting a view isometric are done in here.
	*/
	/**STATIC_CONST_VARS**/
	//Amount of different Tile textures
	static const unsigned int AMOUNT_OF_TILETEXTURES = 2;

	//Maximum Map diameter
	static const unsigned int MAX_MAP_DIAMETER = 8;

	//SFML window
	sf::RenderWindow window;

	//SFML Event
	sf::Event sfEv;

	//Image map
	std::map<unsigned int, sf::Texture*> textures;

	//Structure of the Map where the number stands for the texture that gets loaded at position of x and y
	const int tileMapLayer_0[MAX_MAP_DIAMETER][MAX_MAP_DIAMETER] =
	{
		//8x8 Map at Layer 0 | insert -1 anywhere to not draw a tile there
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	const int tileMapLayer_1[MAX_MAP_DIAMETER][MAX_MAP_DIAMETER] =
	{
		//8x8 Map at layer 1 | insert -1 anywhere to not draw a tile there
		{ -1,-1,-1,-1,-1,-1,-1,-1 },
		{ -1, 2, 2, 2, 2, 2, 2,-1 },
		{ -1, 2,-1,-1,-1,-1, 2,-1 },
		{ -1, 2,-1,-1,-1,-1, 2,-1 },
		{ -1, 2,-1,-1,-1,-1, 2,-1 },
		{ -1, 2,-1,-1,-1,-1, 2,-1 },
		{ -1, 2, 2, 2, 2, 2, 2,-1 },
		{ -1,-1,-1,-1,-1,-1,-1,-1 }
	};

	const int tileMapLayer_2[MAX_MAP_DIAMETER][MAX_MAP_DIAMETER] =
	{
		//8x8 Map at Layer 2 | insert -1 anywhere to not draw a tile there
		{-1,-1,-1,-1,-1,-1,-1,-1},
		{-1, 1, 1, 1, 1, 1, 1,-1},
		{-1, 1, 1, 1, 1, 1, 1,-1},
		{-1, 1, 1, 1, 1, 1, 1,-1},
		{-1, 1, 1, 1, 1, 1, 1,-1},
		{-1, 1, 1, 1, 1, 1, 1,-1},
		{-1, 1, 1, 1, 1, 1, 1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1}
	};

	//Vector of tiles :)
	std::vector<isometricTile*> isoTiles;

	//Private functions
	void initWindow();
	void initTextures();
	void addTile(unsigned int tileNumber, unsigned int pos_x, unsigned int pos_y, unsigned int pos_z);
	void buildMap();

public:
	//Constructor / Destructor
	Projection();
	virtual ~Projection();

	//Accessors
	bool isOpen();

	//Functions
	void pollEvents();

	void update();
	void render();
};

#endif // !PROJECTION_H