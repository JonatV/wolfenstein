/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:08 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/21 15:52:07 by eschmitz         ###   ########.fr       */
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
	data->map[j] = malloc(sizeof(int) * data->sizeline + 1);
	if (!(data->map[j]))
		return ;
	while (str[i])
	{
		if (start(data, j, i, str[i]))
			data->map[j][i] = 0;
		else if (str[i] == 32)
			data->map[j][i] = 1;
		else
			data->map[j][i] = ft_atoi(str[i]);
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
					data->wrongchar = 1;
				return (0);
			}
		}
		return (1);
	}
	return (0);
}

void	map_pars(t_pars *data, char *file)
{
	int		check;
	int		fd;
	char	*str;

	check = 1;
	str = NULL;
	fd = open(file, O_RDONLY);
	data->map = malloc(sizeof(int *) * data->nbrlines;
	if (!(data->map)))
		return ;
	while (check)
	{
		check = get_next_line(fd, &str, data);
		if (data->in_map && !empty_line(str) && data->count < data->nbrlines)
			data->empty_line = 1;
		data->in_map = is_map(data, str);
		if (data->in_map)
		{
			data->count++;
			create_map(data, str);
		}
		free(str);
	}
	close(fd);
	ft_errors(data);
}
