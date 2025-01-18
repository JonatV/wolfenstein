#include "../wolfenstein.h"

static void fixed_focus_map(t_game *game)
{
	int	x;
	int	y;
	int	color;
	int	size;
	
	size = game->map.focus_tile_size;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map_grid[y][x] == 1)
				color = C_BLACK;
			else if (game->map.map_grid[y][x] == 0)
				color = C_GREY;
			else
				color = C_BLACK;
			draw_rect(&game->xpm_images[xpm_map_focus], game->map.start_x + (x * size), game->map.start_y + (y * size), size, size, color);
			x++;
		}
		y++;
	}
}

static void dynamic_focus_map(t_game *game)
{
	(void)game;
}

/*
* info:	max size of the map is 1008x402
* 		position of the map top left corner is x: 96, y: 99 
*/
int	layout_map_screen(t_game *game)
{
	// check if map will be out of bounds
	if (game->map.dynamic_map)
		dynamic_focus_map(game);
	else
		fixed_focus_map(game);
	put_img_to_img(&game->win.screen, &game->xpm_images[xpm_map_focus], 0, 0);
	return (0);
}
