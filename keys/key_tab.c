/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:20:03 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/22 16:21:10 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

void	key_tab(t_game *game)
{
	if (game->keys.tab && !game->keys.tab_pressed)
	{
		game->keys.tab_pressed = true;
		if (game->state == game_screen)
			game->state = inventory;
		else if (game->state == inventory)
			game->state = game_screen;
	}
	else if (!game->keys.tab)
		game->keys.tab_pressed = false;
}
