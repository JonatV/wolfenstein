#include "../wolfenstein.h"

// // void	move_forward(t_game *game)
// // {
// // 	int	x;
// // 	int	y;

// // 	x = floor(data->pos_x + data->dir_x * data->speed);
// // 	y = floor(data->pos_y + data->dir_y * data->speed);
// // 	if (data->map.map[y][(int)floor(data->pos_x)] != '1')
// // 		data->pos_y += (data->dir_y * data->speed);
// // 	if (data->map.map[(int)floor(data->pos_y)][x] != '1')
// // 		data->pos_x += (data->dir_x * data->speed);
// // }

// // void	move_backward(t_game *data)
// // {
// // 	int	x;
// // 	int	y;

// // 	x = floor(data->pos_x - data->dir_x * data->speed);
// // 	y = floor(data->pos_y - data->dir_y * data->speed);
// // 	if (data->map.map[y][(int)floor(data->pos_x)] != '1')
// // 		data->pos_y -= (data->dir_y * data->speed);
// // 	if (data->map.map[(int)floor(data->pos_y)][x] != '1')
// // 		data->pos_x -= (data->dir_x * data->speed);
// // }

// void	move_left(t_game *data)
// {
// 	int	x;
// 	int	y;

// 	x = floor(data->pos_x - data->plane_x * data->speed);
// 	y = floor(data->pos_y - data->plane_y * data->speed);
// 	if (data->map.map[y][(int)floor(data->pos_x)] != '1')
// 		data->pos_y -= (data->plane_y * data->speed);
// 	if (data->map.map[(int)floor(data->pos_y)][x] != '1')
// 		data->pos_x -= (data->plane_x * data->speed);
// }

// void	move_right(t_game *data)
// {
// 	int	x;
// 	int	y;

// 	x = floor(data->pos_x + data->plane_x * data->speed);
// 	y = floor(data->pos_y + data->plane_y * data->speed);
// 	if (data->map.map[y][(int)floor(data->pos_x)] != '1')
// 		data->pos_y += (data->plane_y * data->speed);
// 	if (data->map.map[(int)floor(data->pos_y)][x] != '1')
// 		data->pos_x += (data->plane_x * data->speed);
// }

void	rotate(t_game *game, bool lr)
{
	double	tmp_dir;
	double	tmp_plane;
	double	rot_speed;

	rot_speed = game->player.speed;
	if (lr == 1)
		rot_speed *= -1;
	tmp_dir = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed) - game->player.dir_y * sin(rot_speed);
	game->player.dir_y = tmp_dir * sin(rot_speed) + game->player.dir_y * cos(rot_speed);
	tmp_plane = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = tmp_plane * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
}
void	handle_keys(t_game *game)
{
	if (game->keys.esc)
		close_game(game);
		
	if (game->keys.enter)
	{
		if (game->state == home_screen)
			game->state = game_screen;
	}
	if (game->state == home_screen)
		return ;
	if (game->keys.tab && !game->keys.tab_pressed)
	{
		game->keys.tab_pressed = true;
		if (game->state == game_screen)
			game->state = inventory;
		else if (game->state == inventory)
			game->state = game_screen;
	}
	else if (!game->keys.tab)
		game->keys.tab_pressed = false;

	if (game->keys.space && !game->keys.space_pressed)
	{
		game->keys.space_pressed = true;
		if (game->state == game_screen)
			game->state = map_focus;
		else if (game->state == map_focus)
			game->state = game_screen;
	}
	else if (!game->keys.space)
		game->keys.space_pressed = false;

	if (game->keys.m && !game->keys.m_pressed)
	{
		game->keys.m_pressed = true;
		if (game->state == game_screen)
			game->state = menu;
		else if (game->state == menu)
			game->state = game_screen;
	}
	else if (!game->keys.m)
		game->keys.m_pressed = false;
	// moving the player
	if (game->state == game_screen)
	{
		// look left
		if (game->keys.a)
			rotate(game, 1);
		// look right
		if (game->keys.d)
			rotate(game, 0);
		// move forward
		if (game->keys.w)
		{
			if (game->map.map_grid[(int)(game->player.pos_y + game->player.dir_y * game->player.speed)][(int)game->player.pos_x] == 0)
				game->player.pos_y += game->player.dir_y * game->player.speed;
			if (game->map.map_grid[(int)game->player.pos_y][(int)(game->player.pos_x + game->player.dir_x * game->player.speed)] == 0)
				game->player.pos_x += game->player.dir_x * game->player.speed;
		}
		// move backward
		if (game->keys.s)
		{
			if (game->map.map_grid[(int)(game->player.pos_y - game->player.dir_y * game->player.speed)][(int)game->player.pos_x] == 0)
				game->player.pos_y -= game->player.dir_y * game->player.speed;
			if (game->map.map_grid[(int)game->player.pos_y][(int)(game->player.pos_x - game->player.dir_x * game->player.speed)] == 0)
				game->player.pos_x -= game->player.dir_x * game->player.speed;
		}
		
	}
}
