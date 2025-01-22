/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:19:57 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/22 10:30:11 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

void	init_pars(t_pars **data)
{
	data->map[0] = 0;
	data->error = 0;
	data->map_w = 0;
	data->map_h = 0;
	data->empty_line = 0;
	data->wrongchar = 0;
	data->in_map = 0;
	data->start_x = 0;
	data->start_y = 0;
	data->start_dir = 0;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = 0;
	data->c = 0;
}
