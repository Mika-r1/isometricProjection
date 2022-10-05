//Includes
#include "stdafx.h"
#include "Projection.h"

int main()
{
	//Projection object
	Projection projection;

	//Executed while window is open
	while (projection.isOpen())
	{
		projection.update();

		projection.render();
	}

	//End of program
	return 0;
}