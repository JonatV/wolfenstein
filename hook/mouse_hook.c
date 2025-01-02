#include "../wolfenstein.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)game;
	printf("Mouse move: x[%d] y[%d]\n", x, y);
	return (0);
}

int	mouse_press(int button, int x, int y, t_game *game)
{
	(void)game;
	if (button == Button1)
	{
		printf("Mouse press: button[%d] x[%d] y[%d] (left click)\n", button, x, y);
	}
	else if (button == Button2)
	{
		printf("Mouse press: button[%d] x[%d] y[%d] (middle click)\n", button, x, y);
	}
	else if (button == Button3)
	{
		printf("Mouse press: button[%d] x[%d] y[%d] (right click)\n", button, x, y);
	}
	return (0);
}
