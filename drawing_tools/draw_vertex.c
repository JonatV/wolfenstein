#include "../wolfenstein.h"

/* draw_vertex:
 * draw a line between two points
 * it uses the Bresenham's line algorithm
 * @param img: the image where to draw
 * @param x0: the x position of the first point
 * @param y0: the y position of the first point
 * @param x1: the x position of the second point
 * @param y1: the y position of the second point
 * @return: 0
 */
int	draw_vertex(t_img *img, int x_start, int y_start, int x_end, int y_end, int color)
{
	int delta_x = abs(x_end - x_start);
	int delta_y = abs(y_end - y_start);
	int step_x = x_start < x_end ? 1 : -1;
	int step_y = y_start < y_end ? 1 : -1;
	int error = (delta_x > delta_y ? delta_x : -delta_y) / 2;
	int error2;

	while (1)
	{
		if (x_start >= 0 && x_start < img->line_len / (img->bpp / 8) && y_start >= 0 && y_start < img->line_len / (img->bpp / 8))
			img_pix_put(img, x_start, y_start, color);
		if (x_start == x_end && y_start == y_end)
			break;
		error2 = error;
		if (error2 > -delta_x)
		{
			error -= delta_y;
			x_start += step_x;
		}
		if (error2 < delta_y)
		{
			error += delta_x;
			y_start += step_y;
		}
	}
	return (0);
}
