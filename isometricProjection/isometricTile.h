#ifndef ISOMETRICTILE_H
#define ISOMETRICTILE_H

//Includes
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>

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
	//STATIC_CONST_VARS
	static const int TILE_WIDTH = 32;
	static const int TILE_HEIGHT = 32;

	static const int WINDOW_WIDTH = 512;

	static const int x_start = WINDOW_WIDTH / 2 - TILE_WIDTH / 2;
	static const int y_start = TILE_HEIGHT;

	//Tile shape
	sf::Texture tileTexture;
	sf::Sprite tile;

	//Private functions
	sf::Vector2f calculateScreenPositions(unsigned int pos_x, unsigned int pos_y);

public:
	//Constructor / Destructor
	isometricTile();
	isometricTile(unsigned int pos_x, unsigned int pos_y);
	virtual ~isometricTile();

	//Functions
	void render(sf::RenderTarget& target);
};

#endif // !ISOMETRICTILE_H