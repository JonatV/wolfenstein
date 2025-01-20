/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:01 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/20 14:03:18 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

int	is_special(char c)
{
	if (c != ' ' && c != '0' && c != '1' && c != '2' && c != 'N' c != 'S' &&
			c != 'W' && c != 'E' && c != '\n' && c != '\t')
		return (1);
	return (0);
}

int	data_check(t_pars *data)
{
	if (data->f == -1 || data->c == -1 || data->no == NULL || data->so == NULL ||
			data->we == NULL || data->ea == NULL)
		return (1);
	return (0);
}
