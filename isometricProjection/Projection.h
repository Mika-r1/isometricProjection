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
	//Window properties
	static const unsigned int WINDOW_WIDTH = 512;
	static const unsigned int WINDOW_HEIGHT = 512;

	//Amount of different Tiles
	static const unsigned int AMOUNT_OF_TILES = 2;

	//SFML window
	sf::RenderWindow window;

	//SFML Event
	sf::Event sfEv;

	//Image map
	std::map<unsigned int, sf::Texture*> textures;

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