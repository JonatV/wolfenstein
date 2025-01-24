/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_player_hand.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:53:27 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/24 16:11:57 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

void	player_hand(t_game *game)
{
	t_animation	*a;

	a = &game->anim_h;
	if (game->keys.w || game->keys.a || game->keys.s || game->keys.d)
	{
		if (++a->tmp_delay >= a->delay)
		{
			a->current_frame_num++;
			a->current_frame = ((t_list *)a->current_frame)->next;
			if (a->current_frame == NULL)
			{
				a->current_frame_num = 0;
				a->current_frame = a->sequence;
			}
			a->tmp_delay = 0;
		}
	}
	put_img_to_img(&game->win.scr, ((t_list *)a->current_frame)->content, a->x, a->y);
}
