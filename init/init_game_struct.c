#include "../wolfenstein.h"

bool	init_game_struct(t_game **game)
{
	*game = (t_game *)malloc(sizeof(t_game));
	if (!*game)
		return (printf("Error: main game struct\n"), false);
	(*game)->win_w = WIN_W;
	(*game)->win_h = WIN_H;
	(*game)->fps = FPS;
	(*game)->state = home_screen;
	(*game)->created_at = gettimeofday_ms();
	(*game)->updated_at = gettimeofday_ms();
	return (true);
}
