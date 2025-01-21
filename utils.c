#include "wolfenstein.h"

uint64_t	gettimeofday_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

uint64_t	timestamp_in_ms(t_game *game)
{
	if (!game)
		return 0;
	if (game->created_at == 0)
		game->created_at = gettimeofday_ms();
	return (gettimeofday_ms() - game->created_at);
}

int		encode_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

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
	int	i;
	int	j;
	char	*src_pixel;
	char	*dst_pixel;

	for (i = 0; i < src->height; i++)
	{
		for (j = 0; j < src->width; j++)
		{
			src_pixel = src->addr + (i * src->line_len + j * (src->bpp / 8));
			dst_pixel = dst->addr + ((y + i) * dst->line_len + (x + j) * (dst->bpp / 8));
			if (*(int *)src_pixel != (int)0xFF000000) // Check for transparency
				*(int *)dst_pixel = *(int *)src_pixel;
		}
	}
}


/* Copy a pixel from a source image to a destination image at the specified coordinates
 * 
*/
void	copy_pixel_img(t_img src_img, int src_x, int src_y, t_img dst_img, int dst_x, int dst_y)
{
	unsigned int color;
	char *src_addr;
	char *dst_addr;

	// Get pixel from source image
	if (src_x >= 0 && src_y >= 0 && src_x < src_img.width && src_y < src_img.height)
	{
		src_addr = src_img.addr + (src_y * src_img.line_len + src_x * (src_img.bpp / 8));
		color = *(unsigned int *)src_addr;
	}
	else
		return; // Out of bounds, do nothing

	// Put pixel into destination image
	if (dst_x >= 0 && dst_y >= 0 && dst_x < dst_img.width && dst_y < dst_img.height)
	{
		dst_addr = dst_img.addr + (dst_y * dst_img.line_len + dst_x * (dst_img.bpp / 8));
		*(unsigned int *)dst_addr = color;
	}
}

/* IN GENERAL:
** Destroy image and xpm images
** Destroy display
** Destroy window
** Destroy map grid
** Free mlx_ptr
** Free main game struct
*/
int	close_game(void *p)
{
	t_game	*game;
	int		i;

	game = (t_game *)p;
	i = 0;

	// destroy all the images and xpm images
	if (game->win.screen.mlx_img)
		mlx_destroy_image(game->win.mlx_ptr, game->win.screen.mlx_img);
	while (i < xpm_null)
	{
		if (game->xpm_images[i].mlx_img)
			mlx_destroy_image(game->win.mlx_ptr, game->xpm_images[i].mlx_img);
		i++;
	}
	// destroy img of the dynamic map
	mlx_destroy_image(game->win.mlx_ptr, game->map.focus_map_dynamic.mlx_img);
	// destroy the player marker lst
	t_lst *current = game->map.pos_sprite.anim;
	t_lst *next = NULL;
	while(current)
	{
		next = current->next;
		mlx_destroy_image(game->win.mlx_ptr, ((t_marker *)current->content)->frame.mlx_img);
		free((t_marker *)current->content);
		free(current);
		if (next == game->map.pos_sprite.anim)
			break;
		current = next;
	}
	game->map.pos_sprite.anim = NULL;
	free(game->map.pos_sprite.file_path);
	free(game->map.pos_sprite.name);
	mlx_destroy_image(game->win.mlx_ptr, game->map.pos_sprite.sprite_img.mlx_img);
	// destroy window
	if (game->win.win_ptr)
		mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);

	// destroy display
	if (game->win.mlx_ptr)
		mlx_destroy_display(game->win.mlx_ptr);

	// destroy map grid
	i = 0;
	while (i < game->map.height)
		free(game->map.map_grid[i++]);
	free(game->map.map_grid);

	free(game);
	exit(0);
}
