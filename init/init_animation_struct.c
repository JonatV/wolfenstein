/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:13:46 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/17 22:40:43 by jveirman         ###   ########.fr       */
/*     
                                                                       */
/* ************************************************************************** */

#include "../wolfenstein.h"

static bool	minimap_add_frame(t_lst **a, t_sprite s, t_sprite_slice_data data, int i)
{
	t_player_marker	*frame_obj; // todo frame here has to be the t_player_marker object
	t_img	frame_img;
	int		y;
	int		x;

	frame_obj = (t_player_marker *)ft_calloc(sizeof(t_player_marker), 1);
	if (!frame_obj)
		return (false);
	frame_obj->min_angle = (i * 15) - 7.5;
	if (frame_obj->min_angle < 0)
		frame_obj->min_angle += 360;
	frame_img = new_img(data.width, data.height, s.sprite_img.win);
	if (frame_img.mlx_img == NULL)
	{
		free(frame_obj);
		return (false);
	}
	y = -1;
	while (++y < data.height)
	{
		x = -1;
		while (++x < data.width)
			copy_pixel_img(s.sprite_img, data.x + x, data.y + y, frame_img, x, y);
	}
	frame_obj->frame = frame_img;
	if (!frame_obj)
		return (false); // Error handling
	if (!*a) // Initialize head of the list
		*a = lst_new_double(frame_obj);
	else
		lstadd_back_double(a, lst_new_double(frame_obj));
	return (true);
}

/*	This function create a lst of frames
*	for the animation.
*	it creates node linked each other (prev and next)
*	and add a content that is a player_marker object
*/
t_lst	*minimap_sprite_slicer(t_sprite s, int frames)
{
	int i;
	t_lst	*anim;
	t_sprite_slice_data data;

	// data = (t_sprite_slice_data){32, 32, 0, 0};
	data.width = 32;
	data.height = 32;
	data.x = 0;
	data.y = 0;
	anim = NULL;
	i = 0;
	while (i < frames)
	{
		if (!minimap_add_frame(&anim, s, data, i))
			return (NULL);
		data.x += data.width;
		if (data.x >= s.width)
		{
			data.x = 0;
			data.y += data.height;
		}
		i++;
	}
	return (anim);
}

bool	init_animation_struct(t_game *game)
{
	// 1, we create the sprite object
	game->map.player_marker_sprite = new_sprite("player_marker", "assets/player_marker.xpm", &game->win); // we have game->map.player_marker_sprite
	if (game->map.player_marker_sprite.sprite_img.mlx_img == NULL \
		|| game->map.player_marker_sprite.file_path == NULL \
		|| game->map.player_marker_sprite.name == NULL)
		return (false);
	// 2, slice the sprite for each frames and we need to create the animation chain
	game->map.player_marker_sprite.animation_sequence = minimap_sprite_slicer(game->map.player_marker_sprite, 24); // 24 is the number of player marker (each represent 15deg on a circle)
	// get the current node // todo check with the orientation (NSWE) from the parser info
	game->map.player_marker_sprite.current_node = game->map.player_marker_sprite.animation_sequence;
	// 3 make the list of frames circle linked
	if (!game->map.player_marker_sprite.animation_sequence)
		printf("Error sa mere la pute\n");
	t_lst *last_node = lstlast((t_lst *)game->map.player_marker_sprite.animation_sequence);
	if (!last_node)
		printf("Error: last node is NULL\n");
	((t_lst *)game->map.player_marker_sprite.animation_sequence)->prev = last_node;
	printf("last node content angle: %f\n", ((t_player_marker *)last_node->prev->prev->content)->min_angle); 
	last_node->next = (t_lst *)game->map.player_marker_sprite.animation_sequence;
	return (true);
}
