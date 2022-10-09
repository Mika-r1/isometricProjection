#ifndef STDAFX_H
#define STDAFX_H

//Includes
//SFML Libraries
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//C++ Libraries
#include <iostream>
#include <vector>
#include <map>

class stdafx
{
	/*
	* @class STDAFX
	* @file stdafx.h
	* @brief Precompiled Header class
	* 
	* @details
	* Precompiled headers for shorter compile time and easier useability. In addition static const variables that are used in various files are in
	* here because this header gets included from every file anyways.
	*/
public:
	/**STATIC_CONST_VARS**/
	//Tile properties
	static const int TILE_WIDTH = 32;
	static const int TILE_HEIGHT = 32;

	//Window properties
	static const int WINDOW_WIDTH = 512;
	static const int WINDOW_HEIGHT = 512;
};

#endif // !STDAFX_H
