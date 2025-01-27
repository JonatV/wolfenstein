/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:23:15 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/27 17:37:42 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

void	free_map(t_pars *data)
{
	int	y;

	y = 0;
	if (data->map)
	{
		while (y < data->map_h && data->map[y])
		{
			free(data->map[y]);
			y++;
		}
		free(data->map);
	}
}

void	ft_exit(t_pars *data, char *str)
{
	if (str && str[0])
	{
		write (1, "Error: ", 7);
		write(1, str, ft_strlen(str));
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
		free_map(data);
	if (data)
		free(data);
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
	if (map[y][x] == 1 || map[y][x] == -2)
		return ;
	if (map[y][x] == -1 || ( map[y][x] != 1
		&& (x == 0 || y == 0 || x == d->map_w || y == d->map_h)))
		ft_exit(d, "Map error");
	map[y][x] = -2;
	flood_fill(d, map, x + 1, y);
	flood_fill(d, map, x - 1, y);
	flood_fill(d, map, x, y + 1);
	flood_fill(d, map, x, y - 1);
}

// int	wall_check(t_pars *data)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < data->map_h)
// 		if (data->map[i][0] != 1 || data->map[i][data->map_w - 1] != 1)
// 			return (1);
// 	i = -1;
// 	while (++i < data->map_w)
// 		if (data->map[0][i] != 1 || data->map[data->map_h - 1][i] != 1)
// 			return (1);
// 	return (0);
// }


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
			ft_exit(data, "Malloc failed");
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
	for (int i = 0; i < d->map_h; i++)
	{
		for (int j = 0; j < d->map_w; j++)
		{
			printf("[%d]", map_copy[i][j]);
		}
		printf("\n");
	}
	
	if (d->error && str)
		ft_exit(d, str);
	if (!str)
	{
		// if (wall_check(d))
		// 	ft_exit(d, "Map is not surrounded by walls\n");
		flood_fill(d, map_copy, d->start_x, d->start_y); // wip
		if (!d->start_dir || !d->start_x || !d->start_dir)
			ft_exit(d, "Player informations inexistant or wrong\n");
		if (d->empty_line)
			ft_exit(d, "Empty line in map\n");
		if (d->wrongchar)
			ft_exit(d, "Wrong character in map\n");
		printf(BOLD YELLOW"Check data:\nNorth texture: %s\nSouth texture: %s\nWest texture: %s\nEast texture: %s\nCeiling colour: %d\nFloor colour: %d\n"BOLD CYAN, d->no, d->so, d->we, d->ea, d->c, d->f);
		if (!d->no || !d->so || !d->we || !d->ea || !d->c || !d->f)
			ft_exit(d, "Texture or colour informations missing\n");
	}
}
