#include "../wolfenstein.h"

bool	init_project(t_game **game)
{
	if (!init_game_struct(game))
		return (printf("Error: init_game_struct\n"), false);
	if (!init_window_struct(game))
		return (printf("Error: init_window\n"), false);
	if (!init_map_struct(*game))
		return (printf("Error: init_map\n"), false);
	if (!init_xpm_images(*game))
		return (printf("Error: init_xpm_images\n"), false);
	if (!init_animation_struct(*game))
		return (printf("Error: init_animation_struct\n"), false);
	if (!init_player_struct(*game))
		return (printf("Error: init_player\n"), false);
	if (!init_keys_struct(*game))
		return (printf("Error: init_keys\n"), false);
	init_hooks_logics(*game);
	printf("Project initialized\n");
	return (true);
}
