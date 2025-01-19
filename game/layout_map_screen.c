#include "../wolfenstein.h"
#include "wolfenstein.h"

static void print_loop_dynamic_map(t_game *game, int start_pos_x, int start_pos_y);

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
	int	tile_pos_x;
	int	tile_pos_y;
	int	start_pos_x;
	int	start_pos_y;

	tile_pos_x = (int)game->player.pos_x;
	tile_pos_y = (int)game->player.pos_y;
	start_pos_x = 1008/2 - (tile_pos_x * game->map.focus_tile_size); //todo clean magic numbers
	start_pos_y = 402/2 - (tile_pos_y * game->map.focus_tile_size);
	print_loop_dynamic_map(game, start_pos_x, start_pos_y);
}
/*
   * info:	max size of the map is 1008x402
   * 		position of the map top left corner is x: 96, y: 99
   */
int	layout_map_screen(t_game *game)
{
	t_player_marker *marker;
	t_img *img;

	marker = (t_player_marker *)game->map.player_marker_sprite.current_node->content;
	img = &marker->frame; // Get the address of the frame
	if (!game->map.focus_rendered)
	{
		printf("\e[4;32mRendering map focus\e[0m\n");
		// check if map will be out of bounds
		if (game->map.dynamic_map)
			dynamic_focus_map(game);
		else
			fixed_focus_map(game);
		game->map.focus_rendered = true;
	}
	put_img_to_img(&game->win.screen, &game->xpm_images[xpm_map_focus], 0, 0);
	put_img_to_img(&game->win.screen, &game->map.focus_map_dynamic, 96, 99);
	put_img_to_img(&game->win.screen, img, WIN_W/2 - img->width/2, WIN_H/2 - img->height/2);
	return (0);
}

static void print_loop_dynamic_map(t_game *game, int start_pos_x, int start_pos_y)
{
	int x;
	int y;
	int color;

	draw_rect(&game->map.focus_map_dynamic, 0, 0, 1008, 402, C_BLACK);
	y = 0;
	while (y < MAP_H)
	{
		x = 0;
		while (x < MAP_W)
		{
			if (game->map.map_grid[y][x] == 1)
				color = C_DARK_GREY;
			else if (game->map.map_grid[y][x] == 0)
				color = C_GREY;
			else
				color = C_RED;
			draw_rect(&game->map.focus_map_dynamic, start_pos_x + (x * game->map.focus_tile_size), start_pos_y + (y * game->map.focus_tile_size), game->map.focus_tile_size, game->map.focus_tile_size, color);
			x++;
		}
		y++;
	}
}
