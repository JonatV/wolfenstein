/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:05 by eschmitz          #+#    #+#             */
/*   Updated: 2025/01/28 10:39:52 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

// void	line_checker(t_pars *data, char *str)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	j = 0;
// 	while (str && str[++i])
// 	{
// 		if (str[i] == ',')
// 			j++;
// 	}
// 	if (j > 2)
// 	{
// 		data->error = 1;
// 		ft_errors(data, "Too many comas\n");
// 	}
// }

// int	ft_atoi_c(t_pars *data, char *str)
// {
// 	int	checker;
// 	int	ret;
// 	int	i;

// 	ret = 0;
// 	i = 0;
// 	if (str[1] != 32)
// 		data->error = 1;
// 	line_checker(data, str);
// 	while (str[i] == 32 || str[i] == '\t' || str[i] == ',' || str[i] == '\n')
// 	{
// 		i++;
// 		checker = 0;
// 		while (str[i] >= '0' && str[i] <= '9')
// 		{
// 			checker = (checker * 10) + (str[i] - 48);
// 			ret = ret * 10 + str[i] - 48;
// 			i++;
// 		}
// 		if (checker > 255 || checker < 0)
// 			data->error = 1;
// 	}
// 	return (ret);
// }

// void	get_colours(t_pars *data, char **str)
// {
// 	int	i;

// 	i = 0;
// 	if (!data->no || !data->we || !data->ea || !data->so)
// 		ft_errors(data, "Not enough textures were given\n");
// 	if (*str[i] == 'F')
// 		data->f = ft_atoi_c(data, *str);
// 	else if (*str[i] == 'C')
// 		data->c = ft_atoi_c(data, *str);
// }

void	malloc_colour(t_pars *data, char flag)
{
	if (flag == 'c')
	{
		data->cr = malloc(100);
		if (!data->cr)
			ft_exit(data, "Malloc failed");
		data->cg = malloc(100);
		if (!data->cg)
			ft_exit(data, "Malloc failed");
		data->cb = malloc(100);
		if (!data->cb)
			ft_exit(data, "Malloc failed");
	}
	else if (flag == 'f')
	{
		data->fr = malloc(100);
		if (!data->fr)
			ft_exit(data, "Malloc failed");
		data->fg = malloc(100);
		if (!data->fg)
			ft_exit(data, "Malloc failed");
		data->fb = malloc(100);
		if (!data->fb)
			ft_exit(data, "Malloc failed");
	}
}

int	is_number(char c)
{
	if (!c)
		return (0);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	rgb_to_hex(int r, int g, int b, t_pars *data)
{
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    	ft_exit(data, "RGB values must be between 0 and 255");
    return (r << 16) | (g << 8) | b;
}

void	create_colour_c(t_pars *d, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!is_number(str[i]))
		i++;
	while (is_number(str[i]))
		d->cr[j++] = str[i++];
	d->cr[j] = '\0';
	while (!is_number(str[i]))
		i++;
	j = 0;
	while (is_number(str[i]))
		d->cg[j++] = str[i++];
	d->cg[j] = '\0';
	while (!is_number(str[i]))
		i++;
	j = 0;
	while (is_number(str[i]))
		d->cb[j++] = str[i++];
	d->cb[j] = '\0';
	printf("Ceiling colour informations: %s %s %s\n", d->cr, d->cg, d->cb);
	d->c = rgb_to_hex((int)ft_atoi(d->cr), (int)ft_atoi(d->cg), (int)ft_atoi(d->cb), d);
}

void	create_colour_f(t_pars *d, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!is_number(str[i]))
		i++;
	while (is_number(str[i]))
		d->fr[j++] = str[i++];
	d->fr[j] = '\0';
	while (!is_number(str[i]))
		i++;
	j = 0;
	while (is_number(str[i]))
		d->fg[j++] = str[i++];
	d->fg[j] = '\0';
	while (!is_number(str[i]))
		i++;
	j = 0;
	while (is_number(str[i]))
		d->fb[j++] = str[i++];
	d->fb[j] = '\0';
	printf("Floor colour informations: %s %s %s\n", d->fr, d->fg, d->fb);
	d->f = rgb_to_hex(ft_atoi(d->fr), ft_atoi(d->fg), ft_atoi(d->fb), d);
}

void	pars_colours(t_pars *data, char *str)
{
	if (str[0] == 'F' && str[1] == 32)
	{
		malloc_colour(data, 'f');
		create_colour_f(data, str);
	}
	else if (str[0] == 'C' && str[1] == 32)
	{
		malloc_colour(data, 'c');
		create_colour_c(data, str);
	}
}
