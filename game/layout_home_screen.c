#include "../wolfenstein.h"

int	layout_home_screen(t_game *game)
{
	put_img_to_img(&game->win.scr, &game->xpm_images[xpm_home_screen], 0, 0);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.scr.mlx_img, 0, 0);
	return (0);
}
