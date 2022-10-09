//Includes
#include "stdafx.h"
#include "Projection.h"

//Private functions
void Projection::initWindow()
{
	/*
	* @return void
	*
	* @brief Window gets created and configured.
	*/
	this->window.create(sf::VideoMode(this->WINDOW_WIDTH, this->WINDOW_HEIGHT), "Isometric Projection", sf::Style::Titlebar | sf::Style::Close);
	this->window.setFramerateLimit(60);
	this->window.setVerticalSyncEnabled(false);
}

void Projection::initTextures()
{
	/*
	* @return void
	* 
	* @brief Initializes a std::map loaded with textures that the Tiles  can have.
	*/
	for (int i = 1; i <= this->AMOUNT_OF_TILES; i++)
	{
		this->textures[i] = new sf::Texture();
		if (!this->textures[i]->loadFromFile("Textures/Tile_" + std::to_string(i) + ".png"))
			std::cerr << "FAILED LOADING TILE TEXTURE " << i << std::endl;
	}
}

void Projection::addTile(unsigned int tileNumber, unsigned int pos_x, unsigned int pos_y, unsigned int pos_z)
{
	/*
	* @return void
	*
	* @param tileNumber unsigned int that indicates the tile from the textures std::map
	* @param pos_x, unsigned int for the x component of the Tile's position
	* @param pos_y, unsigned int for the y component of the Tile's position
	* @param pos_z, unsigned int for the optical z component of the new Tile's position
	* a
	* @brief Adds a new Tile at the parameter's position to the Vector.
	*/
	this->isoTiles.push_back(
		new isometricTile(
			this->textures[tileNumber],
			pos_x,
			pos_y,
			pos_z
		)
	);
}

void Projection::buildMap()
{
	/*
	* @return void
	*
	* @brief All the tiles are getting added to the vector in this function.
	*/
	this->addTile(1, 0, 0, 0);
	this->addTile(2, 0, 0, 1);
	this->addTile(2, 0, 0, 2);
	this->addTile(2, 1, 0, 0);
	this->addTile(1, 1, 0, 1);
	this->addTile(2, 0, 1, 0);
	this->addTile(1, 0, 1, 1);
	this->addTile(2, 1, 1, 0);
	this->addTile(1, 1, 1, 1);

	std::cout << "Amount of Tiles: " << isoTiles.size() << std::endl;
}

//Constructor / Destructor
Projection::Projection()
{
	this->initWindow();
	this->initTextures();
	this->buildMap();
}

Projection::~Projection()
{

}

//Accessors
bool Projection::isOpen()
{
	/*
	* @return boolean
	*
	* @brief Returns true as long as the Window is open.
	*/
	return this->window.isOpen();
}

//Functions
void Projection::pollEvents()
{
	/*
	* @return void
	*
	* @brief Polls for User input.
	*/
	while (this->window.pollEvent(sfEv))
	{
		switch (sfEv.type)
		{
		case sf::Event::Closed:
			this->window.close();
			break;
		case sf::Event::KeyPressed:
			switch (sfEv.key.code)
			{
			case sf::Keyboard::Escape:
				this->window.close();
				break;
			}
		}
	}
}

void Projection::update()
{
	/*
	* @return void
	*
	* @brief Update manager, calls everything that is repeatedly done.
	*/
	this->pollEvents();
}

void Projection::render()
{
	/*
	* @return void
	*
	* @brief Render manager, calls everything that needs to get drawn to screen.
	*/
	/*!! @Old: !!*/
	/*PROBABLY NOT IDEAL SOLUTION*/
	/*
	isoTile tile;
	isoTile tile2;
	isoTile tile3;
	isoTile tile4;
	*/
	/*---------------------------*/
	/*
	if (!tile.load(0, 0))
		std::cerr << "Failed drawing isometric tile(0, 0)" << std::endl;

	if (!tile2.load(1, 0))
		std::cerr << "Failed drawing isometric tile(1, 0)" << std::endl;

	if (!tile3.load(0, 1))
		std::cerr << "Failed drawing isometric tile(0, 1)" << std::endl;

	if (!tile4.load(1, 1))
		std::cerr << "Failed drawing isometric tile(1, 1)" << std::endl;

	this->window.clear(sf::Color::Black);

	this->window.draw(tile);
	this->window.draw(tile2);
	this->window.draw(tile3);
	this->window.draw(tile4);
	*/

	for (auto* isometricTile : this->isoTiles)
	{
		isometricTile->render(this->window);
	}

	this->window.display();
}