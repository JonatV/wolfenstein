/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:52:59 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/21 14:34:13 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

static void find_current_marker( t_sprite *player_sprite, t_player player)
{
	//calcul point to adjust to the rotation of the player
	float angle = atan2(player.dir_y, player.dir_x);
	float angle_degrees = angle * (180.0 / M_PI);
	if (angle_degrees < 0)
		angle_degrees += 360;
	float to_find = (floor(angle_degrees / 15) * 15) + 7.500f;
	while(((t_marker *)player_sprite->cur_node->content)->min_angle != to_find)
		player_sprite->cur_node = player_sprite->cur_node->next;
}

void	minimap(t_game *game)
{
	float	start_x;
	float	start_y;
	int		i;
	int		j;
	
	start_x = game->player.pos_x * MINI_SIZE - (float)MINI_W / 2;
	start_y = game->player.pos_y * MINI_SIZE - (float)MINI_H / 2;
	i = 0;	
	while (i < MINI_H)
	{
		j = 0;
		while (j < MINI_W)
		{
			int grid_x = (int)(start_x + j) / MINI_SIZE;
			int grid_y = (int)(start_y + i) / MINI_SIZE;

			// check if we are out of bound
			if ((start_y + i >= 0 && start_y + i <= MINI_SIZE * MINI_H) &&
				(start_x + j >= 0 && start_x + j <= MINI_SIZE * MINI_W) &&
				(grid_y >= 0 && grid_y < game->map.height) &&
				(grid_x >= 0 && grid_x < game->map.width))
			{
				if (game->map.map_grid[grid_y][grid_x] == 1)
					img_pix_put(&game->win.screen, j + PADDING, i + PADDING, C_DARK_GREY);
				else if (game->map.map_grid[grid_y][grid_x] == 3)
					img_pix_put(&game->win.screen, j + PADDING, i + PADDING, C_DEEP_RED);
				else
					img_pix_put(&game->win.screen, j + PADDING, i + PADDING, C_GREY);
			}
			else
				img_pix_put(&game->win.screen, j + PADDING, i + PADDING, C_BLACK);
			j++;
		}
		i++;
	}
	find_current_marker(&game->map.pos_sprite, game->player);
	t_img *frame = &((t_marker *)game->map.pos_sprite.cur_node->content)->frame;
	put_img_to_img(&game->win.screen, frame, MINI_W / 2 + PADDING - frame->width / 2, MINI_H / 2 + PADDING - frame->height / 2);
}
