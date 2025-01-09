#include "../wolfenstein.h"

bool	init_xpm_images(t_game *game)
{
	game->xpm_images[xpm_north] = set_new_xpm("assets/NORTH.xpm", &game->win);
	game->xpm_images[xpm_south] = set_new_xpm("assets/SOUTH.xpm", &game->win);
	game->xpm_images[xpm_east] = set_new_xpm("assets/EAST.xpm", &game->win);
	game->xpm_images[xpm_west] = set_new_xpm("assets/WEST.xpm", &game->win);
	return (true);
}
