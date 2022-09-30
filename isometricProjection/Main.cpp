#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Projection.h"

int main()
{
	Projection projection;

	while (projection.isOpen())
	{
		projection.update();

		projection.render();
	}

	return 0;
}