#include "../wolfenstein.h"

bool	init_window_struct(t_game **game)
{
	// here we initialize the window struct
	(*game)->win.mlx_ptr = mlx_init();
	if (!(*game)->win.mlx_ptr)
		return (printf("Error: mlx_init\n"), false);
	(*game)->win.win_ptr = mlx_new_window((*game)->win.mlx_ptr, (*game)->win_w, (*game)->win_h, TITLE);
	if (!(*game)->win.win_ptr)
		return (printf("Error: mlx_new_window\n"), false);
	(*game)->win.title = TITLE;
	(*game)->win.width = WIN_W;
	(*game)->win.height = WIN_H;
	(*game)->win.screen = new_img((*game)->win.width, (*game)->win.height, &(*game)->win);
	printf("Window struct initialized\n");
	return (true);
}
