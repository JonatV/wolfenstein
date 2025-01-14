#include "../wolfenstein.h"

int	layout_map_screen(t_game *game)
{
	int	x;
	int	y;
	int	color;

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
			draw_rect(&game->xpm_images[xpm_map_focus], 100 + (x * 20), 100 + (y * 20), 20, 20, color);
			x++;
		}
		y++;
	}
	put_img_to_img(&game->win.screen, &game->xpm_images[xpm_map_focus], 0, 0);
	return (0);
}
