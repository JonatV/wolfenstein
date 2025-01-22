/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:26:32 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/22 23:14:16 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

bool	init_xpm_images(t_game *game)
{
	t_img	*xpm;

	xpm = game->xpm_images;
	xpm[xpm_home_screen] = set_new_xpm("assets/home_screen.xpm", &game->win);
	xpm[xpm_game_over] = set_new_xpm("assets/game_over.xpm", &game->win);
	xpm[xpm_menu] = set_new_xpm("assets/menu.xpm", &game->win);
	xpm[xpm_map_focus] = set_new_xpm("assets/map.xpm", &game->win);
	xpm[xpm_inventory] = set_new_xpm("assets/inventory.xpm", &game->win);
	xpm[xpm_north] = set_new_xpm("assets/NORTH.xpm", &game->win);
	xpm[xpm_south] = set_new_xpm("assets/SOUTH.xpm", &game->win);
	xpm[xpm_east] = set_new_xpm("assets/EAST.xpm", &game->win);
	xpm[xpm_west] = set_new_xpm("assets/WEST.xpm", &game->win);
	xpm[xpm_walls] = set_new_xpm("assets/wallsv2.xpm", &game->win);
	xpm[xpm_door] = set_new_xpm("assets/DAMN.xpm", &game->win);
	return (true);
}
