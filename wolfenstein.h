#ifndef WOLFENSTEIN_H
#define WOLFENSTEIN_H

# include "libft/libft.h"			// for libft functions
# include "minilibx_linux/mlx.h"		// for mlx functions (handle window, image, etc)
# include <X11/Xutil.h>				// for keycode Macro (XK_SPACE, XK_Escape, etc)
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdint.h>
# include <math.h>

#define TITLE "Wolfenstein"
#define WIN_W 1200
#define WIN_H 600
#define FPS 32

// has to be define in the parsing latter
// #define MAP_H 28
#define MAP_H 19
#define MAP_W 29
// #define MAP_W 35

#define C_BLACK		0x1A1A1A
#define C_DARK_RED	0x311F1F
#define C_DEEP_RED	0x8C2B36
#define C_RED		0xF53F39
#define C_DARK_GREY	0x2e2e2e
#define C_GREY		0xABABAB
#define C_TRANSPARENT	0xFF000000

#define NS false
#define EW true

// Map Macro
#define PADDING 10
#define MINI_SIZE 20
#define FOC_SIZE 20
#define MINI_H 150
#define MINI_W 150
#define MAX_M_W 1008
#define MAX_M_H 402

enum game_state
{
	home_screen,
	game_screen,
	game_over,
	menu,
	map_focus,
	inventory,
	// add more here
};

enum xpm_images
{
	xpm_home_screen,
	xpm_game_over,
	xpm_menu,
	xpm_map_focus,
	xpm_inventory,
	xpm_north,
	xpm_south,
	xpm_east,
	xpm_west,
	xpm_walls,
	xpm_null,
	// add more here
};

enum wall_orientation
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
	bool	e;
	bool	m;
	bool	tab;
	bool	esc;
	bool	enter;
	bool	space;
	bool	m_pressed;
	bool	tab_pressed;
	bool	enter_pressed;
	bool	space_pressed;
}		t_keys;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;

	int		width;
	int		height;

	struct s_win	*win;
}		t_img;

typedef struct s_rect
{
	t_img	*img;
	int		x;
	int		y;
	int		w;
	int		h;
	int		color;
}	t_rect;

typedef struct s_copy_pixel
{
	t_img	src_img;
	int		src_x;
	int		src_y;
	t_img	dst_img;
	int		dst_x;
	int		dst_y;
}	t_copy_pix;

typedef struct s_win
{
	char	*title;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	screen;
	int		width;
	int		height;
}		t_win;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	speed;
	double	rot_speed;
	double	plane_x;
	double	plane_y;
}		t_player;

typedef struct s_sprite_slice_data
{
	int x;
	int y;
	int width;
	int height;
}	t_sprite_slice_data;

typedef struct s_marker
{
	t_img	frame;
	float	min_angle;		// to set the image orientation property
}	t_marker;

typedef struct s_lst
{
	void			*content;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_sprite
{
	void	*anim;	// void because it can be either the frames list (player marker)
									//or the structure that content the info of the animation + the frames list 
	t_lst	*cur_node;
	char	*name;
	char	*file_path;
	t_img	sprite_img;
	int	width;
	int	height;
}	t_sprite;

typedef struct s_map
{
	int		**map_grid;
	int		width;
	int		height;
	// minimap data (little map on left top corner)
	t_sprite	pos_sprite;
	// map focus data (full screen map)
	bool		dynamic_map;
	int			start_x;
	int			start_y;
	int			f_startx;
	int			f_starty;
	t_img		focus_map_dynamic;
	bool		focus_rendered;
}		t_map;

typedef struct s_ray
{
	bool	hit;		
	double	camera;			// position of the current column
	double	ray_dir_x;
	double	ray_dir_y;
	double	map_x;
	double	map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	step_x;
	double	step_y;
	double	perp_wall_dist; // it measures the distance from the player to the wall, it will be used to calculate the height of the wall strip
	double	wall_x; // exact value of where the wall was hit
	bool	side; // it will be used to determine if the ray hit a NS or EW wall
	enum wall_orientation	wall_orientation;
	double	wall_height;
}		t_raycast;

typedef struct s_game
{
	t_win		win;
	t_keys		keys;
	t_player	player;
	t_map		map;
	t_raycast	raycast;
	unsigned int	win_w;
	unsigned int	win_h;
	enum game_state	state;
	uint64_t	created_at;
	uint64_t	updated_at;
	int			fps;

	// array of xpm images
	t_img		xpm_images[xpm_null];
	// t_img		xpm_images[xpm_null];
}	t_game;

/*----------------  expose_hook.c  ---------------*/
int		expose_hook(t_game *game);

/*----------------  mouse_hook.c  ---------------*/
int		mouse_move(int x, int y, t_game *game);
int		mouse_press(int button, int x, int y, t_game *game);

/*----------------  key_hook.c  ---------------*/
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);

/*----------------  main.c  ---------------*/
int		main(void);

/*----------------  draw_rectangle.c  ---------------*/
// void		draw_rect(t_img *img, int x, int y, int w, int h, int color);
void		draw_rect(t_rect rect);

/*----------------  optimization.c  ---------------*/
void		img_pix_put(t_img *img, int x, int y, int color);

/*----------------  init_keys_struct.c  ---------------*/
bool		init_keys_struct(t_game *game);

/*----------------  init_hooks_logics.c  ---------------*/
bool		init_hooks_logics(t_game *game);

/*----------------  init_project.c  ---------------*/
bool		init_project(t_game **game);

/*----------------  init_player_struct.c  ---------------*/
bool		init_player_struct(t_game *game);

/*----------------  init_xpm_images.c  ---------------*/
bool		init_xpm_images(t_game *game);

/*----------------  init_map_struct.c  ---------------*/
bool		init_map_struct(t_game *game);

/*----------------  init_window_struct.c  ---------------*/
bool		init_window_struct(t_game **game);

/*----------------  init_game_struct.c  ---------------*/
bool		init_game_struct(t_game **game);

/*----------------  close.c  ---------------*/
int		close_game(void *p);

/*----------------  fps.c  ---------------*/
uint64_t		gettimeofday_ms(void);
uint64_t		timestamp_in_ms(t_game *game);

/*----------------  colors.c  ---------------*/
int		encode_rgb(int r, int g, int b);

/*----------------  image_helpers.c  ---------------*/
t_img		new_img(int w, int h, t_win *window);
t_img		set_new_xpm(char *path, t_win *window);
void		put_img_to_img(t_img *dst, t_img *src, int x, int y);
void		copy_pixel_img(t_img src_img, int src_x, int src_y, t_img dst_img, int dst_x, int dst_y);
// void		copy_pixel_img(t_copy_pix c);


/*----------------  handle_keys.c  ---------------*/
void		handle_keys(t_game *game);

/*----------------  layout_home_screen.c  ---------------*/
int		layout_home_screen(t_game *game);

/*----------------  layout_game_screen.c  ---------------*/
int		layout_game_screen(t_game *game);

/*----------------  update.c  ---------------*/
int		update(t_game *game);

int		raycast(t_game *game);
void	put_column_to_win(t_game *game, int x);

void	layout_map_screen(t_game *game);

/*----------------  minimap.c  ---------------*/
void	minimap(t_game *game);

/*----------------  animation_tools.c  ---------------*/
t_sprite	new_sprite(char *name, char *file_path, t_win *win);

/*----------------  init_animation_struct.c  ---------------*/
bool	init_animation_struct(t_game *game);

/*----------------  animation_utils.c  ---------------*/
t_lst	*lst_new_double(void *content);
void	lstadd_back_double(t_lst **lst, t_lst *new);
t_lst	*lstlast(t_lst *lst);

#endif
