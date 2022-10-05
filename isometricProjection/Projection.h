#ifndef PROJECTION_H
#define PROJECTION_H

//Includes
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>

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
	//STATIC_CONST_VARS
	static const int WINDOW_WIDTH = 512;
	static const int WINDOW_HEIGHT = 512;

	//SFML window
	sf::RenderWindow window;

	//SFML Event
	sf::Event sfEv;

	//Isometric Tiles :)
	std::vector<isometricTile*> isoTiles;

	//Private functions
	void initWindow();
	void initTextures();

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