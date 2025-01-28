/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:24:38 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/28 13:56:16 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)y;
	if (game->state != game_screen)
		return (0);
	if (x < WIN_W / 2)
		rotate(game, 1);
	else if (x > WIN_W / 2)
		rotate(game, 0);
	return (0);
}

int	mouse_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (game->state == game_screen)
	{
		if (button == Button1)
			game->keys.mouse_1 = true;
		else if (button == Button2)
			game->keys.mouse_2 = true;
		else if (button == Button3)
			game->keys.mouse_3 = true;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (game->state == game_screen)
	{
		if (button == Button1)
			game->keys.mouse_1 = false;
		else if (button == Button2)
			game->keys.mouse_2 = false;
		else if (button == Button3)
			game->keys.mouse_3 = false;
	}
	return (0);
}
