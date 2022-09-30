#ifndef PROJECTION_H
#define PROJECTION_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "isoTile.h"

class Projection
{
private:
	//STATIC_CONST_VARS
	static const int WINDOW_WIDTH = 512;
	static const int WINDOW_HEIGHT = 512;

	sf::RenderWindow window;

	sf::Event sfEv;

	isoTile tile;

	void initWindow();

public:
	//Constructor / Deconstructor
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