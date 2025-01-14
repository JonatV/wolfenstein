/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:52:59 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/14 17:03:18 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

static void draw_minimap_player(t_game *game)
{
	//calcul point to adjust to the rotation of the player
	float angle = atan2(game->player.dir_y, game->player.dir_x);
	printf("player dir x: %f\n", game->player.dir_x);
	printf("player dir y: %f\n", game->player.dir_y);
	printf("angle: %f\n", angle);
	
}

void	minimap(t_game *game)
{
	// int	x;
	// int	y;
	float	start_x;
	float	start_y;
	int		i;
	int		j;
	(void)i, (void)j, (void)start_x, (void)start_y;

	start_x = game->player.pos_x * game->map.mini_tile_size  - game->map.minimap_width/2;
	start_y = game->player.pos_y * game->map.mini_tile_size - game->map.minimap_height/2;
	i = 0;
	while (i < game->map.minimap_height)
	{
		j = 0;
		while (j < game->map.minimap_width)
		{
			int grid_x = (int)(start_x + j) / game->map.mini_tile_size;
			int grid_y = (int)(start_y + i) / game->map.mini_tile_size;

			// check if we are out of bound
			if ((start_y + i >= 0 && start_y + i <= game->map.mini_tile_size * game->map.minimap_height) &&
				(start_x + j >= 0 && start_x + j <= game->map.mini_tile_size * game->map.minimap_width) &&
				(grid_y >= 0 && grid_y < game->map.height) &&
				(grid_x >= 0 && grid_x < game->map.width))
			{
				if (game->map.map_grid[grid_y][grid_x] == 1)
					img_pix_put(&game->win.screen, j + game->map.padding, i + game->map.padding, C_DARK_GREY);
				else
					img_pix_put(&game->win.screen, j + game->map.padding, i + game->map.padding, C_GREY);
			}
			else
				img_pix_put(&game->win.screen, j + game->map.padding, i + game->map.padding, C_BLACK);
			j++;
		}
		i++;
	}
	put_img_to_img(&game->win.screen, &game->xpm_images[xpm_minimap_player], game->map.minimap_width/2 + game->map.padding - game->xpm_images[xpm_minimap_player].width/2, game->map.minimap_height/2 + game->map.padding - game->xpm_images[xpm_minimap_player].width/2);
	draw_minimap_player(game);
}
