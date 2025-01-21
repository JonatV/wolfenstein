/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:05 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/21 15:40:44 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

void	line_checker(t_pars *data, char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str && str[++i])
	{
		if (str[i] == ',')
			j++;
	}
	if (j > 2)
	{
		data->error = 1;
		ft_errors(data, "Too many comas\n");
	}
}

int	ft_atoi(t_pars *data, char *str)
{
	int	checker;
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (str[1] != 32)
		data->error = 1;
	line_checker(data, str);
	while (str[i] == 32 || str[i] == '\t' || str[i] == ',' || str[i] == '\n'
		|| str[i] '\r' || str[i] == '\v' || str[i] == '\f')
	{
		i++;
		checker = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			checker = (checker * 10) + (str[i] - 48);
			ret = ret * 10 + str[i] - 48;
			i++;
		}
		if (checker > 255 || checker < 0)
			data->error = 1;
	}
	return (ret);
}

void	get_colours(t_pars *data, char **str)
{
	int	i;

	i = 0;
	if (data->toutcequonrecuperecommeinfo == NULL)
		data->error = 1;
	else if (*str[i] == 'F')
		data->f = ft_atoi(data, *str);
	else if (*str[i] == 'C')
		data->c = ft_atoi(data, *str);
}
