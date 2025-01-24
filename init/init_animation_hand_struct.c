/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation_hand_struct.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:25:50 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/24 15:47:03 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

// 1. Get the new img slot t_img
// 2. Copy on the new img slot the pixel from the source img
// 3. Create a new_node with the new img slot as content
// 4. Add the new_node to the list
// 5. Return true if all went well
// arg needed are the list of frames (a pointer to the list), the data rules, and the source img
static bool add_frame(t_list **f, t_sprite_slice_data data, t_img src)
{
	int		y;
	int		x;
	t_img	*frame;

	frame = malloc(sizeof(t_img));
	if (frame == NULL)
		return (false);
	*frame = new_img(data.width, data.height, src.win);
	if (frame->mlx_img == NULL)
		return (false);
	y = -1;
	while (++y < data.height)
	{
		x = -1;
		while (++x < data.width)
			copy_pixel_img(src, data.x + x, data.y + y, *frame, x, y);
	}
	if (*f == NULL)
		*f = ft_lstnew(frame);
	else
		ft_lstadd_back(f, ft_lstnew(frame));
	return (true);
}

/*
** will slice the sprite starting from the top left corner
** and slice it into frames(max frames = frames).
** It cycle left to right and from top to bottom row by row.
*/
t_list	*slice_sprite(t_sprite_slice_data data, int frames, t_img src)
{
	int		i;
	t_list	*a;

	a = NULL;
	i = -1;
	while (++i < frames)
	{
		if (!add_frame(&a, data, src))
			return (NULL);
		data.x += data.width;
		if (data.x >= src.width)
		{
			data.x = 0;
			data.y += data.height;
		}
	}
	return (a);
}


bool	init_anim_hand(t_game *game)
{
	t_sprite_slice_data	slice_data;

	slice_data = (t_sprite_slice_data){0, 0, H_W, H_H};
	game->anim_h.sprite_img = set_new_xpm("assets/player_hand2.xpm", &game->win);
	game->anim_h.delay = H_DELAY;
	game->anim_h.tmp_delay = 0;
	game->anim_h.current_frame_num = 0;
	game->anim_h.total_frame = H_FRAMES;
	game->anim_h.w = H_W;
	game->anim_h.h = H_H;
	game->anim_h.x = H_X;
	game->anim_h.y = H_Y;
	game->anim_h.sequence = slice_sprite(slice_data, H_FRAMES, game->anim_h.sprite_img);
	game->anim_h.current_frame = game->anim_h.sequence;
	return (true);
}
