/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:23:15 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/22 11:23:19 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

int	wall_utils(int *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] != 1)
			return (1);
		i++;
	}
	return (0);
}

int	wall_check(t_pars *data)
{
	int	i;

	i = -1;
	while (++i < data->map_h)
		if (data->map[i][0] != '1' || data->map[i][data->map_w - 1] != '1')
			return (1);
	i = -1;
	if (wall_utils(data->map[0]) == 1
		|| wall_utils(data->map[data->map_h - 1]) == 1)
		return (1);
	while (data->map[0][++i] && data->map[data->map_h -1][i])
		if (data->map[0][i] != '1' && data->map[data->map_h -1][i] != '1')
			return (1);
	return (0);
}

void	ft_exit(t_pars *data, char *str)
{
	int	i;

	i = -1;
	if (str)
	{
		write (1, "Error: ", 7);
		write(1, &str, ft_strlen(str));
	}
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
	{
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	if (data)
		free(data);
}

void	ft_errors(t_pars *d, char *str)
{
	if (str && str[0])
		ft_exit(d, str);
	if (wall_check(d))
		ft_exit(d, "Map is not surrounded by walls\n");
	if (!d->start_dir || !d->start_x || !d->start_dir)
		ft_exit(d, "Player informations inexistant or wrong\n");
	if (d->empty_line)
		ft_exit(d, "Empty line in map\n");
	if (d->wrongchar)
		ft_exit(d, "Wrong character in map\n");
	if (!d->no || !d->so || !d->we || !d->ea || !d->c || !d->f)
		ft_exit(d, "Texture or colour informations missing\n");
}
