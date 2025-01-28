/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:29:00 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/28 23:00:41 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

void	key_a(t_game *game)
{
	double	new_x;
	double	new_y;

	if (game->keys.a)
	{
		new_x = game->player.pos_x - game->player.plane_x * game->player.speed;
		new_y = game->player.pos_y - game->player.plane_y * game->player.speed;
		if (game->map.map_grid[(int)(new_y + ST)][(int)(game->player.pos_x)] == 0 && \
			game->map.map_grid[(int)(new_y - ST)][(int)(game->player.pos_x)] == 0)
			game->player.pos_y = new_y;
		if (game->map.map_grid[(int)(game->player.pos_y)][(int)(new_x + ST)] == 0 && \
			game->map.map_grid[(int)(game->player.pos_y)][(int)(new_x - ST)] == 0)
			game->player.pos_x = new_x;
	}
}
