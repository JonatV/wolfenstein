/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:08 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/20 19:12:34 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

int	start(t_pars *data, int i, int j, char c)
{
	static int	checker = 0;
	
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (checker)
		{
			data->error = 1;
		}
		data->start_dir = c; //pour donner la direction de depart du joueur
		data->x_position = j; //pour donner les coordonnees du depart du joueur
		data->y_position = i;
		checker = 1;
		return (1);
	}
	return (0);
}

void	create_map(t_pars *data, char *str)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (!(data->map[j] = malloc(data->sizeline + 1)))
		return ;
	while (str[i])
	{
		if (start(data, j, i, str[i]))
			data->map[j][i] = 0;
		else if (str[i] == 32)
			data->map[j][i] = 1;
		else
			data->map[j][i] = ft_itoa(str[i]);
		i++;
	}
	while (i <= (data->sizeline - 1))
		data->map[j][i++] = '1';
	j++;
}

int	is_map(t_pars *data, char *str)
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
					data->wrongchar = 1; //pour de futurs messages d'erreur au besoin genre caractere incorrect
				return (0);
			}
		}
		return (1);
	}
	return (0);
}

void	map_check(t_pars *data, char *str)
{
	static int	nbrlines = 0;
	static int	sizeline = 0;

	if (is_map(data, str) == 1)
	{
		if (data_check(data))
			data->error = 1;
		if (ft_strlen(str) > sizeline)
			sizeline = ft_strlen(str);
		nbrlines += 1;
	}
	data->sizeline = sizeline;
	data->nbrlines = nbrlines;
}
