/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_w.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:29:00 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/22 16:56:42 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

void	key_w(t_game *game)
{
	if (game->keys.w)
	{
		if (game->map.map_grid[(int)(game->player.pos_y + game->player.dir_y \
		* game->player.speed + 0.21)][(int)(game->player.pos_x)] == 0 && \
		game->map.map_grid[(int)(game->player.pos_y + game->player.dir_y \
		* game->player.speed - 0.21)][(int)(game->player.pos_x)] == 0)
		{
			game->player.pos_y += game->player.dir_y * game->player.speed;
		}
		if (game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.\
		pos_x + game->player.dir_x * game->player.speed + 0.21)] == 0 && \
		game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.\
		pos_x + game->player.dir_x * game->player.speed - 0.21)] == 0)
		{
			game->player.pos_x += game->player.dir_x * game->player.speed;
		}
	}
}
