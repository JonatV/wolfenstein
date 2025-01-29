/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:29:04 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/29 00:46:59 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

bool	is_wall(int num)
{
	if (num == ID_WALL \
	|| num == ID_METAL \
	|| num == ID_METAL2 \
	|| num == ID_SCAFFOLD \
	|| num == ID_PIPE \
	|| num == ID_GRIDS)
		return (true);
	return (false);
}
