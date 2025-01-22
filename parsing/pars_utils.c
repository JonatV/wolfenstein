/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:01 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/22 13:47:49 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

int	is_special(char c)
{
	if (c != ' ' && c != '0' && c != '1' && c != '2' && c != 'N' && c != 'S'
		&& c != 'W' && c != 'E' && c != '\n' && c != '\t')
		return (1);
	return (0);
}

int	data_check(t_pars *data)
{
	if (data->f == -1 || data->c == -1 || data->no == NULL || data->so == NULL
		|| data->we == NULL || data->ea == NULL)
		return (1);
	return (0);
}

int	detect_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	map_check(t_pars *data, char *str)
{
	static int	nbrlines = 0;
	static int	sizeline = 0;

	if (is_map(data, str) == 1)
	{
		printf("goes in\n");
		if (data_check(data))
			data->error = 1;
		if ((int)ft_strlen(str) > sizeline)
			sizeline = ft_strlen(str);
		nbrlines += 1;
	}
	// printf("Sizeline: %d\nNumber lines: %d\n", sizeline, nbrlines);
	data->map_w = sizeline;
	data->map_h = nbrlines;
}

int	check_fd(t_pars *data, char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
		ft_errors(data, "Error: file is a directory\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_errors(data, "Error: invalid file\n");
	return (fd);
}
