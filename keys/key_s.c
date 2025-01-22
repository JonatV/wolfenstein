/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:29:00 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/22 16:57:52 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

void	key_s(t_game *game)
{
	if (game->keys.s)
	{
		if (game->map.map_grid[(int)(game->player.pos_y - game->player.dir_y \
		* game->player.speed + 0.21)][(int)(game->player.pos_x)] == 0 && \
		game->map.map_grid[(int)(game->player.pos_y - game->player.dir_y * \
		game->player.speed - 0.21)][(int)(game->player.pos_x)] == 0)
		{
			game->player.pos_y -= game->player.dir_y * game->player.speed;
		}
		if (game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.\
		pos_x - game->player.dir_x * game->player.speed + 0.21)] == 0 && \
		game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.pos_x \
		- game->player.dir_x * game->player.speed - 0.21)] == 0)
		{
			game->player.pos_x -= game->player.dir_x * game->player.speed;
		}
	}
}
