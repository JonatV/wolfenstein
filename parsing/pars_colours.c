/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:05 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/20 14:54:53 by eschmitz         ###   ########.fr       */
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
		{
			data->error = 1;
			j++;
		}
	}
	if (j > 2)
		ft_errors(data, "Too many comas\n");
	
}

int	ft_atoi(t_pars *data, char *str)
{
	int	checker;

	checker = 0;
	if (str[1] == 32)
		data->error = 1;
	line_checker(data, str);
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
 