/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:56:07 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/24 15:48:32 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

/* IN GENERAL:
** Destroy image and xpm images
** Destroy display
** Destroy window
** Destroy map grid
** Free mlx_ptr
** Free main game struct
*/

static void	destroy_animation_struct(t_game *game)
{
	t_list	*current;
	t_list	*next;
	t_img	*img;
	int		i;

	next = NULL;
	current = game->anim_h.sequence;

	mlx_destroy_image(game->win.mlx_ptr, game->anim_h.sprite_img.mlx_img);
	i = -1;
	while (++i < game->anim_h.total_frame)
	{
		img = (t_img *)current->content;
		mlx_destroy_image(game->win.mlx_ptr, img->mlx_img);
		next = current->next;
		free(img);
		free(current);
		if (next == game->anim_h.sequence)
			break ;
		current = next;
	}
	game->anim_h.sequence = NULL;
}
static void	destroy_map_struct(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->map.height)
		free(game->map.map_grid[i++]);
	free(game->map.map_grid);
	mlx_destroy_image(game->win.mlx_ptr, game->map.f_map_dynamic.mlx_img);
}

static void	destroy_marker_struct(t_game *game)
{
	t_lst	*current;
	t_lst	*next;

	next = NULL;
	current = game->map.pos_sprite.anim;
	while (current)
	{
		next = current->next;
		mlx_destroy_image(game->win.mlx_ptr, ((t_marker *)current->content)->frame.mlx_img);
		free((t_marker *)current->content);
		free(current);
		if (next == game->map.pos_sprite.anim)
			break ;
		current = next;
	}
	game->map.pos_sprite.anim = NULL;
	free(game->map.pos_sprite.file_path);
	free(game->map.pos_sprite.name);
	mlx_destroy_image(game->win.mlx_ptr, game->map.pos_sprite.sprite_img.mlx_img);
}

int	close_game(void *p)
{
	t_game	*game;
	int		i;

	game = (t_game *)p;
	i = 0;
	// destroy all the images and xpm images
	if (game->win.scr.mlx_img)
		mlx_destroy_image(game->win.mlx_ptr, game->win.scr.mlx_img);
	while (i < xpm_null)
	{
		if (game->xpm_images[i].mlx_img)
			mlx_destroy_image(game->win.mlx_ptr, game->xpm_images[i].mlx_img);
		i++;
	}
	// destroy anim hand
	destroy_animation_struct(game);
	// destroy img of the dynamic map
	// destroy the player marker lst
	destroy_marker_struct(game);
	// destroy the map struct
	destroy_map_struct(game);
	// destroy window
	if (game->win.win_ptr)
		mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
	// destroy display
	if (game->win.mlx_ptr)
		mlx_destroy_display(game->win.mlx_ptr);
	// destroy map grid
	free(game);
	exit(0);
}
