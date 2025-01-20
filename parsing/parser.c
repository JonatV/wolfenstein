/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:05:49 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/20 19:07:40 by eschmitz         ###   ########.fr       */
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

	if (!(data->map = malloc(sizeof(char *) * data->nbrlines)))
		return ;
	while (check)
	{
		check = get_next_line(fd, &str, data);
		if (data->in_map == 1 && !empty_line(str) && data->count < data->nbrlines)
			data->empty_line = 1;
		if ((data->in_map = is_map(data, str)) == 1)
		{
			data->count++;
			create_map(data, str);
		}
		free(str);
	}
	close(fd);
	ft_errors(data);
	init_sprite(data);
}

void	parse_all(t_pars *data, char *file)
{
	int		fd;
	int		checker;
	char	*str;

	checker = 1;
	str = NULL;
	if ((fd = open(file, O_DIRECTORY)) != -1)
		ft_errors(data, "Error: file is a directory\n");
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_errors(data, "Error: invalid file\n");
	data->error = 0;
	while (checker)
	{
		checker = get_next_line(fd, &str, data);
		if (data->error == 1)
			ft_errors(data, "Error: problem with map\n");
		get_colours(data, &str);
		get_texture();
		map_check();
		free(str);
	}
	close (fd);
	if (!data->sizeline || !data->nbrlines)
		ft_errors(data, "Error: no map given\n");
	map_pars(data, file);
}
