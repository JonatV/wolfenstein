/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:28:54 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/26 21:04:18 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

bool	init_player_struct(t_game *game)
{
	game->player.dir_x = 0.0;
	game->player.dir_y = -1.0;
	game->player.pos_x = 2.5;
	game->player.pos_y = 21.5;
	game->player.speed = 0.1;
	game->player.rot_speed = 1.0;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0.0;
	return (true);
}
