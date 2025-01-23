/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveirman <jveirman@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:56:33 by jveirman          #+#    #+#             */
/*   Updated: 2025/01/23 09:30:02 by jveirman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolfenstein.h"

t_img	new_img(int w, int h, t_win *window)
{
	t_img	image;

	image.win = window;
	image.mlx_img = mlx_new_image(window->mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.mlx_img, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.width = w;
	image.height = h;
	return (image);
}

t_img	set_new_xpm(char *path, t_win *window)
{
	t_img	img;

	img.win = window;
	img.mlx_img = mlx_xpm_file_to_image(window->mlx_ptr, path, &img.width, &img.height);
	if (!img.mlx_img)
	{
		printf("Error: can't read this image file\n");
		exit(1);// !to change
	}
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
	printf("name: %s\n", path);
	printf("img: %p\n", img.mlx_img);
	printf("x: %d\n", img.width);
	printf("y: %d\n", img.height);
	return (img);
}

void	put_img_to_img(t_img *dst, t_img *src, int x, int y)
{
	int		i;
	int		j;
	char	*src_pixel;
	char	*dst_pixel;

	i = -1;
	while (++i < src->height)
	{
		j = -1;
		while (++j < src->width)
		{
			src_pixel = src->addr + (i * src->line_len + j * (src->bpp / 8));
			dst_pixel = dst->addr + ((y + i) * dst->line_len + (x + j) * \
			(dst->bpp / 8));
			if (*(int *)src_pixel != (int)0xFF000000)
				*(int *)dst_pixel = *(int *)src_pixel;
		}
	}
}

/* Copy a pixel from a source image to a destination image at the specified coordinates
 * 
*/
void	copy_pixel_img(t_img src_img, int src_x, int src_y, t_img dst_img, int dst_x, int dst_y)
{
	unsigned int	color;
	char			*src_addr;
	char			*dst_addr;

	// Get pixel from source image
	if (src_x >= 0 && src_y >= 0 && src_x < src_img.width && src_y < src_img.height)
	{
		src_addr = src_img.addr + (src_y * src_img.line_len + src_x * (src_img.bpp / 8));
		color = *(unsigned int *)src_addr;
	}
	else
		return ;
	if (dst_x >= 0 && dst_y >= 0 && dst_x < dst_img.width && dst_y < dst_img.height)
	{
		dst_addr = dst_img.addr + (dst_y * dst_img.line_len + dst_x * (dst_img.bpp / 8));
		*(unsigned int *)dst_addr = color;
	}
}
