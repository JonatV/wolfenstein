#include "../wolfenstein.h"

int temp_map[MAP_H][MAP_W] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,0,1},
	{1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1,1,1,0,1,0,0,0,1},
	{1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
	{1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1},
	{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
//#define MAP_H 13
// #define MAP_W 24
// int temp_map[MAP_H][MAP_W] = {
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };
// int temp_map[MAP_H][MAP_W] = {
// 	{1,1,1,1,1,1,1,1,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,0,0,0,0,0,0,0,1},
// 	{1,1,1,1,1,1,1,1,1}
// };


bool init_map_struct(t_game *game)
{
	int	y;
	int	x;

	game->map.height = MAP_H;
	game->map.width = MAP_W;
	game->map.tile_size = TILE_SIZE;

	game->map.floor_color = encode_rgb(43, 31, 26);		// brown
	game->map.wall_color = encode_rgb(255, 0, 0);		// red
	game->map.empty_color = 0xFF000000;					// transparent
	game->map.player_color = encode_rgb(255, 255, 255);	// white

	game->map.map_grid = malloc(sizeof(int *) * game->map.height);
	if (!game->map.map_grid)
		return (printf("Error: map grid\n"), false);
	y = -1;
	while (++y < game->map.height)
	{
		game->map.map_grid[y] = malloc(sizeof(int) * game->map.width);
		if (!game->map.map_grid[y])
		{
			while (--y >= 0)
				free(game->map.map_grid[y]);
			free(game->map.map_grid);
			return (printf("Error: inside map grid\n"), false);
		}
	}
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
			game->map.map_grid[y][x] = temp_map[y][x];
	}
	// init minimap data
	game->map.padding = 10;
	game->map.mini_tile_size = 20;
	game->map.minimap_height = 150;
	game->map.minimap_width = 150;
	game->map.player_marker_sprite = (t_sprite){0};
	// init map focus data
	game->map.max_map_width = 1008;
	game->map.max_map_height = 402;
	game->map.focus_tile_size = FOCUS_TILE_SIZE;
	game->map.dynamic_map = false;
	if (game->map.height * game->map.focus_tile_size > game->map.max_map_height \
		|| game->map.width * game->map.focus_tile_size > game->map.max_map_width)
		game->map.dynamic_map = true;
	if (game->map.dynamic_map)
	{
		game->map.start_x = 96;
		game->map.start_y = 99;
	}
	else
	{
		game->map.start_x = (game->win_w - (game->map.width * game->map.focus_tile_size))/2;
		game->map.start_y = (game->win_h - (game->map.height * game->map.focus_tile_size))/2;
	}
	return (true);
}
