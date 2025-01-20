/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:11:07 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/20 19:30:18 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

int	get_text_len(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '.')
		i++;
	while (str[i])
	{
		i++;
		j++;
	}
	return (j);
}

void	get_texture(t_pars *data, char **text, char *str, int j)
{
	int	i;

	i = 0;
	if (*text || !detect_char(str, '.') || !detect_char(str, '/'))
		data->error = 1;
	j -= 1;
	while (str[++j] != '.')
		if (str[j] != 32 &&str[j] != '.')
			data->error = 1;
	if (!(text = malloc(get_text_len(str) + 1)))
		data->error = 1;
	while (str[j])
	{
		(*text)[i] = str[j];
		i++;
		j++;
	}
	(*text)[i] = '\0';
}

void	texture(t_pars *data, char *file)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (str[i] == 'N' && str[i+1] == 'O')
		get_texture(data, &data->so, str, 2);
	else if (str[i] == 'S' && str[i+1] == 'O')
		get_texture(data, &data->no, str, 2);
	else if (str[i] == 'W' && str[i+1] == 'E')
		get_texture(data, &data->ea, str, 2);
	else if (str[i] == 'E' && str[i+1] == 'A')
		get_texture(data, &data->we, str, 2);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
			&& str[0] != 'F' && str[0] != 'C' && str[0] > 65 && str[0] < 122)
		data->error = 1;
	j++;
}
