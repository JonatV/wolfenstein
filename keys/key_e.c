/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_e.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:29:00 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/22 17:04:33 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

static void	check_half(t_game *game, float angle)
{
	if (angle >= 45 && angle < 135)
	{
		if (game->map.map_grid[(int)(game->player.pos_y + \
		game->player.dir_y + 0.2)][(int)game->player.pos_x] == 3)
			game->map.map_grid[(int)(game->player.pos_y + \
			game->player.dir_y + 0.2)][(int)game->player.pos_x] = 0;
	}
	else if (angle >= 135 && angle < 225)
	{
		if (game->map.map_grid[(int)(game->player.pos_y)] \
		[(int)(game->player.pos_x + game->player.dir_x - 0.2)] == 3)
			game->map.map_grid[(int)game->player.pos_y] \
			[(int)(game->player.pos_x + game->player.dir_x - 0.2)] = 0;
	}
}

static void	check_other_half(t_game *game, float angle)
{
	if (angle >= 225 && angle < 315)
	{
		if (game->map.map_grid[(int)(game->player.pos_y + \
		game->player.dir_y - 0.2)][(int)game->player.pos_x] == 3)
			game->map.map_grid[(int)(game->player.pos_y + \
			game->player.dir_y - 0.2)][(int)game->player.pos_x] = 0;
	}
	else
	{
		if (game->map.map_grid[(int)game->player.pos_y] \
		[(int)(game->player.pos_x + game->player.dir_x + 0.2)] == 3)
			game->map.map_grid[(int)game->player.pos_y] \
			[(int)(game->player.pos_x + game->player.dir_x + 0.2)] = 0;
	}
}

static void	detect_door(t_game *game)
{
	float	angle;

	angle = atan2(game->player.dir_y, game->player.dir_x) * (180.0 / M_PI);
	if (angle < 0)
		angle += 360;
	check_half(game, angle);
	check_other_half(game, angle);
}

void	key_e(t_game *game)
{
	if (game->keys.e)
		detect_door(game);
}
