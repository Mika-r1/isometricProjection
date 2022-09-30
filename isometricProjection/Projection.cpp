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

//Constructor / Destructor
Projection::Projection()
{
    this->initWindow();
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

    /*PROBABLY NOT IDEAL SOLUTION*/
    isoTile tile;
    isoTile tile2;
    isoTile tile3;
    isoTile tile4;
    /*---------------------------*/

    if (!tile.load(0, 0))
        std::cerr << "Failed drawing isometric tile" << std::endl;

    if (!tile2.load(1, 0))
        std::cerr << "Failed drawing isometric tile" << std::endl;

    if (!tile3.load(0, 1))
        std::cerr << "Failed drawing isometric tile" << std::endl;

    if (!tile4.load(1, 1))
        std::cerr << "Failed drawing isometric tile" << std::endl;

    this->window.clear(sf::Color::Black);

    this->window.draw(tile);
    this->window.draw(tile2);
    this->window.draw(tile3);
    this->window.draw(tile4);

    this->window.display();
}