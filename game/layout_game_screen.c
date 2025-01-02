#include "../wolfenstein.h"

int	layout_game_screen(t_game *game)
{
	if (game->state == game_screen)
		raycast(game);
		// draw_rect(&game->win.screen, 0, 0, game->win.width, game->win.height, C_GREY);
	else if (game->state == inventory)
		put_img_to_img(&game->win.screen, &game->xpm_images[xpm_inventory], 0, 0);
	else if (game->state == map_focus)
		layout_map_screen(game);
	else if (game->state == menu)
		put_img_to_img(&game->win.screen, &game->xpm_images[xpm_menu], 0, 0);
	else if (game->state == game_over)
		put_img_to_img(&game->win.screen, &game->xpm_images[xpm_game_over], 0, 0);
	// display the image to the window
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.screen.mlx_img, 0, 0);
	return (0);
}
