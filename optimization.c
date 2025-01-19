#include "wolfenstein.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
		char	*pixel;
		
		if (x < 0 || y < 0 || x >= img->width || y >= img->height)
			return ;
		if (color == (int)0xFF000000) //todo: check if mandatory: it seems like if it is activated, it will be black instead of transparent
			return ;
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
}
