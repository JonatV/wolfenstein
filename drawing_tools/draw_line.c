#include "../wolfenstein.h"

void	draw_line_vertical(t_img *img, int x, int y, int h, int color)
{
	int	i;

	i = 0;
	while (i < h && i + y < img->height)
	{
		img_pix_put(img, x, i + y, color);
		i++;
	}
}

void	draw_line_horizontal(t_img *img, int x, int y, int w, int color)
{
	int	i;

	i = 0;
	while (i < w && i + x < img->width)
	{
		img_pix_put(img, i + x, y, color);
		i++;
	}
}
