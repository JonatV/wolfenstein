#include "../wolfenstein.h"

void	draw_circle(t_img *img, int x, int y, int radius, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < radius * 2 && i + y < img->height)
	{
		j = 0;
		while (j < radius * 2 && j + x < img->width)
		{
			if (((j - radius) * (j - radius)) +
			((i - radius) * (i - radius)) <
			(radius * radius))
				img_pix_put(img, j + x, i + y, color);
			j++;
		}
		i++;
	}
}
