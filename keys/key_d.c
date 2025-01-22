/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:29:00 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/22 17:06:32 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

void	key_d(t_game *game)
{
	if (game->keys.d)
	{
		if (game->map.map_grid[(int)(game->player.pos_y + game->player.plane_y \
		* game->player.speed + 0.21)][(int)(game->player.pos_x)] == 0 && \
		game->map.map_grid[(int)(game->player.pos_y + game->player.plane_y * \
		game->player.speed - 0.21)][(int)(game->player.pos_x)] == 0)
		{
			game->player.pos_y += game->player.plane_y * game->player.speed;
		}
		if (game->map.map_grid[(int)(game->player.pos_y)] \
		[(int)(game->player.pos_x + game->player.plane_x * game->player.speed + \
		0.21)] == 0 && game->map.map_grid[(int)(game->player.pos_y)] \
		[(int)(game->player.pos_x + game->player.plane_x * game->player.speed - \
		0.21)] == 0)
		{
			game->player.pos_x += game->player.plane_x * game->player.speed;
		}
	}
}
