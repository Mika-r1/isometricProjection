//Includes
#include "isoTile.h"

/*Overriden draw() function*/
void isoTile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    /*
    * @return void
    * 
    * @param target, sf::RenderTarget& for the target where the function is supposed to draw to
    * @param states, sf::RenderStates for the Current render state
    * 
    * @brief draws the tile with the Current render state to the target.
    */
    target.draw(tile, states);
}

bool isoTile::load(unsigned int x, unsigned int y)
{
    /*
    * @return void
    * 
    * @param x, unsigned int for the x position in the isometric grid of the Tile
    * @param y, unsigned int for the y position in the isometric grid of the Tile
    * 
    * @brief Initalizes the Texture, calculates the position on the screen and sets the position of the tile.
    */
    if (!tileTexture.loadFromFile("Tile.png"))
        return false;

    tile.setTexture(tileTexture);

    int x_screen = x_start + (x - y) * (TILE_WIDTH / 2);
    int y_screen = y_start + (x + y) * (TILE_HEIGHT / 2)/2;
   
    tile.setPosition(x_screen, y_screen);
}