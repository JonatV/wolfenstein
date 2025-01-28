/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_errors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:23:15 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/28 19:02:58 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

static void	free_tmp_map(t_pars *data, int ***map)
{
	int	y;

	y = 0;
	if (*map)
	{
		while (y < data->tmp_map_h && (*map)[y])
		{
			free((*map)[y]);
			y++;
		}
		free(*map);
	}
}

static void	free_map(t_pars *data, int ***map)
{
	int	y;

	y = 0;
	if (*map)
	{
		while (y < data->map_h && (*map)[y])
		{
			free((*map)[y]);
			y++;
		}
		free(*map);
	}
}

void	free_colours(t_pars *data)
{
	if (data->cr)
		free(data->cr);
	if (data->cg)
		free(data->cg);
	if (data->cb)
		free(data->cb);
	if (data->fr)
		free(data->fr);
	if (data->fg)
		free(data->fg);
	if (data->fb)
		free(data->fb);
}

void	ft_exit(t_pars *data, char *str)
{
	if (str && str[0])
	{
		write (1, "Error: ", 7);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
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
		if (data->tmp_map_h < data->map_h)
			free_tmp_map(data, &data->map);
		else
			free_map(data, &data->map);
	}
	free_colours(data);
	if (data)
		free(data);
	exit(1);
}

int	ft_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0' && str[i] != '\n'
			&& str[i] != '\r' && str[i] != '\v' && str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}

void	flood_fill(t_pars *d, int **map, int x, int y)
{
	if ((x < 0 || y < 0 || x >= d->map_w || y >= d->map_h) || map[y][x] == -1) //je pense qu'il y a une couille dans le pate parce que la ca checke pas si c'est entoure par des murs
		ft_exit(d, "Map error\n");
	if (map[y][x] == 1 || map[y][x] == -2 || (map[y][x] <= 7 && map[y][x] >= 4))
		return ;
	map[y][x] = -2;
	flood_fill(d, map, x + 1, y);
	flood_fill(d, map, x - 1, y);
	flood_fill(d, map, x, y + 1);
	flood_fill(d, map, x, y - 1);
}

void	copy_map(t_pars *data, int ***target, int ** source)
{
	int	x;
	int	y;

	(*target) = malloc(sizeof(int *) * data->map_h);
	if (!(*target))
		ft_exit(data, "Malloc failed");
	y = -1;
	while (++y < data->map_h)
	{
		(*target)[y] = malloc(sizeof(int) * data->map_w);
		if (!(*target)[y])
		{
			//faut rajouter un free target qui passe sur la map
			while (--y >= 0)
				free((*target)[y]);
			free(*target);
			ft_exit(data, "Malloc failed");
		}
	}
	y = -1;
	while (++y < data->map_h)
	{
		x = -1;
		while (++x < data->map_w)
			(*target)[y][x] = source[y][x];
	}
}

void	ft_errors(t_pars *d, char *str)
{
	int	**map_copy;

	map_copy = NULL;
	copy_map(d, &map_copy, d->map);
	if (!str)
	{
		if (!d->start_dir || !d->start_x || !d->start_dir)
			ft_exit(d, "Player informations inexistant or wrong");
		if (d->empty_line)
			ft_exit(d, "Empty line in map");
		if (d->wrongchar)
			ft_exit(d, "Wrong character in map");
		if (!d->no || !d->so || !d->we || !d->ea || !d->c || !d->f)
			ft_exit(d, "Texture or colour informations missing");
		flood_fill(d, map_copy, d->start_x, d->start_y);
		free_map(d, &map_copy);
	}
}
