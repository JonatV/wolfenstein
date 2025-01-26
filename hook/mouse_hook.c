/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:24:38 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/26 12:30:20 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)game;
	printf("Mouse move: x[%d] y[%d]\n", x, y);
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
	(void)game;
	if (button == Button1)
	{
		printf("Mouse press: button[%d] x[%d] y[%d] \
		(left click)\n", button, x, y);
	}
	else if (button == Button2)
	{
		printf("Mouse press: button[%d] x[%d] y[%d] \
		(middle click)\n", button, x, y);
	}
	else if (button == Button3)
	{
		printf("Mouse press: button[%d] x[%d] y[%d] \
		(right click)\n", button, x, y);
	}
	return (0);
}
