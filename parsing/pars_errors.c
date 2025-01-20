/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:23:15 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/20 19:07:07 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

int	wall_check(t_pars *data)
{
	int	i;

	i = -1;
	while (++i < data->nbrlines)
		if (data->map[i][0] != '1' || data->map[i][data->sizeline - 1] != '1')
			return (1);
	i = -1;
	if (wall_utils(data->map[0]) == 1
		|| wall_utils(data->map[data->nbrlines - 1]) == 1)
		return (1);
	while (data->map[0][++i] && data->map[data->nbrlines -1][i])
		if (data->map[0][i] != '1' && data->map[data->nbrlines -1][i] != '1')
			return (1);
	return (0);
}

ft_exit() //faut faire une fonction exit qui free tout le bordel et ecrit le bon message d'erreur

void	ft_errors(t_pars *data, char *str)
{
	if (str && str[0])
		ft_exit(data, str);
	if (wall_check(data))
		ft_exit(data, "Map is not surrounded by walls\n");
	if (!data->start_dir || !data->start_x || !data->start_dir)
		ft_exit(data, "Player informations inexistant or wrong\n");
	if (data->empty_line)
		ft_exit(data, "Empty line in map\n");
	if (data->wrongchar)
		ft_exit(data, "Wrong character in map\n");
}
