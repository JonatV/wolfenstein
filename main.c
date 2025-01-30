/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:30:59 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/30 11:25:44 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_pars	*data;

	if (argc != 2)
		return (write(1, "Wrong number of arguments\n", 26), 0);
	data = malloc(sizeof(t_pars));
	init_pars(&data);
	parse_all(data, argv[1]);
	if (!init_project(&game, data))
		return (1);
	mlx_loop_hook(game->win.mlx_ptr, update, game);
	mlx_loop(game->win.mlx_ptr);
	return (0);
}
