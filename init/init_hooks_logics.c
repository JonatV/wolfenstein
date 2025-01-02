#include "../wolfenstein.h"

bool	init_hooks_logics(t_game *game)
{
	mlx_expose_hook(game->win.win_ptr, expose_hook, game);
	
	mlx_hook(game->win.win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win.win_ptr, KeyRelease, KeyReleaseMask, key_release, game);
	
	mlx_hook(game->win.win_ptr, MotionNotify, PointerMotionMask, mouse_move, game);
	mlx_mouse_hook(game->win.win_ptr, mouse_press, game);

	mlx_hook(game->win.win_ptr, ClientMessage, StructureNotifyMask, close_game, game);

	return (true);
}
