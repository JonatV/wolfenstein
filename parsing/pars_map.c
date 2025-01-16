/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:08 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/16 18:56:50 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolfenstein.h"

int	is_map(t_game *data, char *str)
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
				if (data->insidemap == 1)
					data->wrongcharmap = 2;
				return (0);
			}
		}
		return (1);
	}
	return (0);
}

void	map_check(t_game *data, char *str)
{
	static int	nbrlinesstat = 0;
	static int	sizelinestat = 0;
	
	i = 0;
	if (is_map(data, str) == 1)
	{
		if (data_check(data))
			data->error = 2;
		if (ft_strlen(str) > sizelinestat)
			sizelinestat = ft_strlen(str);
		nblinesstat += 1;
	}
	data->sizeline = sizelinestat;
	data->nbrlines = nbrlinesstat;
}