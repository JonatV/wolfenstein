#include "wolfenstein.h"

int main(void)
{
	t_game	*game;

	if (!init_project(&game))
		return (1);
	printf("Initialization successful, entering mlx_loop\n");
	mlx_loop_hook(game->win.mlx_ptr, update, game);
	mlx_loop(game->win.mlx_ptr);
	return 0;
}
