#include "isoTile.h"

void isoTile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(tile, states);
}

bool isoTile::load(unsigned int x, unsigned int y)
{
    if (!tileTexture.loadFromFile("Tile.png"))
        return false;

    tile.setTexture(tileTexture);

    int x_screen = x_start + (x - y) * (TILE_WIDTH / 2);
    int y_screen = y_start + (x + y) * (TILE_HEIGHT / 2)/2;
   
    tile.setPosition(x_screen, y_screen);
}
