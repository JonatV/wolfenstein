/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:05:49 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/21 15:46:49 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

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

void	parse_all(t_pars *data, char *file)
{
	int		fd;
	int		checker;
	char	*str;

	checker = 1;
	str = NULL;
	fd = check_fd(data, file);
	data->error = 0;
	while (checker)
	{
		checker = get_next_line(fd, &str, data);
		if (data->error == 1)
			ft_errors(data, "Error: problem with map\n");
		get_colours(data, &str);
		get_texture(data, file);
		map_check(data, file);
		free(str);
	}
	close (fd);
	if (!data->sizeline || !data->nbrlines)
		ft_errors(data, "Error: no map given\n");
	map_pars(data, file);
}
