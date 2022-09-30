#ifndef ISOTILE_H
#define ISOTILE_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

class isoTile : public sf::Drawable
{
private:
	//STATIC_CONST_VARS
	static const int TILE_WIDTH = 32;
	static const int TILE_HEIGHT = 32;

	static const int WINDOW_WIDTH = 512;

	static const int x_start = WINDOW_WIDTH / 2 - TILE_WIDTH / 2;
	static const int y_start = TILE_HEIGHT;
	
	sf::Sprite tile;
	sf::Texture tileTexture;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	bool load(unsigned int x, unsigned int y);
};

#endif // !ISOTILE_H