/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:52:59 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/20 15:30:07 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

static void find_current_player_marker( t_sprite *player_sprite, t_player player)
{
	//calcul point to adjust to the rotation of the player
	float angle = atan2(player.dir_y, player.dir_x);
	float angle_degrees = angle * (180.0 / M_PI);
	if (angle_degrees < 0)
		angle_degrees += 360;
	float to_find = (floor(angle_degrees / 15) * 15) + 7.500f;
	while(((t_player_marker *)player_sprite->current_node->content)->min_angle != to_find)
		player_sprite->current_node = player_sprite->current_node->next;
}

void	minimap(t_game *game)
{
	float	start_x;
	float	start_y;
	int		i;
	int		j;
	
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
				else if (game->map.map_grid[grid_y][grid_x] == 3)
					img_pix_put(&game->win.screen, j + game->map.padding, i + game->map.padding, C_DEEP_RED);
				else
					img_pix_put(&game->win.screen, j + game->map.padding, i + game->map.padding, C_GREY);
			}
			else
				img_pix_put(&game->win.screen, j + game->map.padding, i + game->map.padding, C_BLACK);
			j++;
		}
		i++;
	}
	find_current_player_marker(&game->map.player_marker_sprite, game->player);
	t_img *frame = &((t_player_marker *)game->map.player_marker_sprite.current_node->content)->frame;
	put_img_to_img(&game->win.screen, frame, game->map.minimap_width/2 + game->map.padding - frame->width/2, game->map.minimap_height/2 + game->map.padding - frame->height/2);
}
