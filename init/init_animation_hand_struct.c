/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation_hand_struct.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:25:50 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/23 16:37:33 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

bool	init_anim_hand(t_game *game)
{
	(void)game;
	game->anim_h.sprite_img = set_new_xpm("assets/player_hand.xpm", &game->win);
	return (true);
}
