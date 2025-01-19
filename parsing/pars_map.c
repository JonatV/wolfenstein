/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:08 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/19 18:55:50 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfenstein.h"

int	wall_check(t_game *data) //checke si la map est bien entouree de 1, a implementer dans une fonction errors
{
	int	i;

	i = -1;
	while (++i < data->nbrlines)
		if (data->map[i][0] != '1' || data->map[i][data->sizeline - 1] != '1')
			return (1);
	i = -1;
	if (wall_utils(data->map[0]) == 1 || wall_utils(data->map[data->nbrlines - 1]) == 1)
		return (1);
	while (data->map[0][++i] && data->map[data->nbrlines -1][i])
		if (data->map[0][i] != '1' && data->map[data->nbrlines -1][i] != '1')
			return (1);
	return (0);
}

int	depart(t_game *data, int i, int j, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		data->depart_dir = c; //pour donner la direction de depart du joueur
		data->x_position = j; //pour donner les coordonnees du depart du joueur
		data->y_position = i;
		return (1);
	}
	return (0);
}

void	create_map(t_game *data, char *str)
{
	int			i;
	static int	j = 0;

	i = 0;
	data->map[j] = NULL;
	if (!(data->map[j] = malloc(data->sizeline + 1)))
		return ;
	while (str[i])
	{
		if (depart(data, j, i, str[i]) == 1)
			data->map[j][i] = '0';
		else if (str[i] == 32)
			data->map[j][i] = '1';
		else
			data->map[j][i] = str[i];
		i++;
	}
	while (i <= (data->sizeline - 1))
		data->map[j][i++] = '1';
	data->map[j][i] = '\0';
	j++;
}

int	is_map(t_game *data, char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	if (find_char(str, '1') == 1 || find_char(str, '0') == 1)
	{
		while (str[i])
		{
			if (is_special(str[++i]))
			{
				if (data->in_map == 1)
					data->wrongcharmap = 1; //pour de futurs messages d'erreur au besoin genre caractere incorrect
				return (0);
			}
		}
		return (1);
	}
	return (0);
}

void	map_check(t_game *data, char *str)
{
	static int	nbrlinesstat = 0;
	static int	sizelinestat = 0;

	if (is_map(data, str) == 1)
	{
		if (data_check(data))
			data->error = 2;
		if (ft_strlen(str) > sizelinestat)
			sizelinestat = ft_strlen(str);
		nblinesstat += 1;
	}
	data->sizeline = sizelinestat;
	data->nbrlines = nbrlinesstat;
}
