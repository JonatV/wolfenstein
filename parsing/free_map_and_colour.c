/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_and_colour.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:10:50 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/28 19:11:14 by eschmitz         ###   ########.fr       */
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
