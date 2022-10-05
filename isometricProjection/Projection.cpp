//Includes
#include "stdafx.h"a
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

void Projection::addTile(unsigned int pos_x, unsigned int pos_y)
{
    /*
    * @return void
    * 
    * @param pos_x, unsigned int for the x component of the Tile's position
    * @param pos_y, unsigned int for the y component of the Tile's position
    * 
    * @brief Adds a new Tile at the parameter's position to the Vector. 
    */
    this->isoTiles.push_back(
        new isometricTile(
            pos_x,
            pos_y
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
    /*Just for testing, not ideal to add every tile by hand.*/
    this->addTile(0, 0);
    this->addTile(1, 0);
    this->addTile(0, 1);
    this->addTile(1, 1);
    this->addTile(2, 2);
    this->addTile(3, 3);
    this->addTile(4, 4);
    this->addTile(5, 5);
    this->addTile(6, 6);
    this->addTile(7, 7);
    this->addTile(8, 8);
    this->addTile(9, 8);
    this->addTile(8, 9);
    this->addTile(9, 9);
    this->addTile(10, 10);
    this->addTile(11, 11);
    this->addTile(12, 12);
    this->addTile(13, 13);
    this->addTile(14, 14);
    this->addTile(15, 15);
    this->addTile(16, 16);
    this->addTile(17, 16);
    this->addTile(16, 17);
    this->addTile(17, 17);
    this->addTile(18, 18);
    this->addTile(19, 19);
    this->addTile(20, 20);
    this->addTile(21, 21);
    this->addTile(22, 22);
    this->addTile(23, 23);
    this->addTile(24, 24);
    this->addTile(25, 24);
    this->addTile(24, 25);
    
    std::cout << "Amount of Tiles: " << isoTiles.size() << std::endl;
}

//Constructor / Destructor
Projection::Projection()
{
    this->initWindow();
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