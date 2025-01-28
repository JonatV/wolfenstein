/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:20:46 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/28 19:21:12 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

int	is_number(t_pars *data, char c)
{
	if (!c)
		return (0);
	if (c >= '0' && c <= '9')
		return (1);
	if (c != ',' && c != ' ')
		ft_exit(data, "Colour code is wrong");
	return (0);
}
