/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:15:22 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/21 15:15:23 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

bool	init_keys_struct(t_game *game)
{
	game->keys.w = false;
	game->keys.a = false;
	game->keys.s = false;
	game->keys.d = false;
	game->keys.e = false;
	game->keys.esc = false;
	game->keys.enter = false;
	game->keys.space = false;
	game->keys.tab = false;
	game->keys.m = false;
	game->keys.m_pressed = false;
	game->keys.tab_pressed = false;
	game->keys.enter_pressed = false;
	game->keys.space_pressed = false;
	return (true);
}
