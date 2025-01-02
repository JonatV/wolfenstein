#include "../wolfenstein.h"

void	draw_rect(t_img *img, int x, int y, int w, int h, int color)
{
	int	i;
	int	j;

	printf("draw rect: x=%d, y=%d, w=%d, h=%d, color=%#x\n", x, y, w, h, color);
	i = 0;
	while (i < h && i + y < img->height)
	{
		j = 0;
		while (j < w && j + x < img->width)
		{
			img_pix_put(img, j + x, i + y, color);
			j++;
		}
		i++;
	}
}
