#include "../wolfenstein.h"

bool	init_player_struct(t_game *game)
{
	game->player.dir_x = 0.0;
	game->player.dir_y = -1.0;
	game->player.pos_x = 12.0;
	game->player.pos_y = 7.0;
	game->player.speed = 0.1;
	game->player.rot_speed = 1.0;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0.0;
	return (true);
}
