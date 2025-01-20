#include "../wolfenstein.h"

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
	game->player.plane_x = game->player.plane_x * cos(rot_speed) - game->player.plane_y * sin(rot_speed);
	game->player.plane_y = tmp_plane * sin(rot_speed) + game->player.plane_y * cos(rot_speed);
}

static void	detect_door(t_game *game)
{
	float angle;

	angle = atan2(game->player.dir_y, game->player.dir_x) * (180.0 / M_PI);
	if (angle < 0)
		angle += 360;
	if (angle >= 45 && angle < 135)
	{
		if (game->map.map_grid[(int)(game->player.pos_y + game->player.dir_y + 0.2)][(int)game->player.pos_x] == 3)
			game->map.map_grid[(int)(game->player.pos_y + game->player.dir_y + 0.2)][(int)game->player.pos_x] = 0;
	}
	else if (angle >= 135 && angle < 225)
	{
		if (game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.pos_x + game->player.dir_x - 0.2)] == 3)
			game->map.map_grid[(int)game->player.pos_y][(int)(game->player.pos_x + game->player.dir_x - 0.2)] = 0;
	}
	else if (angle >= 225 && angle < 315)
	{
		if (game->map.map_grid[(int)(game->player.pos_y + game->player.dir_y - 0.2)][(int)game->player.pos_x] == 3)
			game->map.map_grid[(int)(game->player.pos_y + game->player.dir_y - 0.2)][(int)game->player.pos_x] = 0;
	}
	else
	{
		if (game->map.map_grid[(int)game->player.pos_y][(int)(game->player.pos_x + game->player.dir_x + 0.2)] == 3)
			game->map.map_grid[(int)game->player.pos_y][(int)(game->player.pos_x + game->player.dir_x + 0.2)] = 0;
	}
}

void	handle_keys(t_game *game)
{
	// quit game
	if (game->keys.esc)
		close_game(game);
	// homescreen to game screen
	if (game->keys.enter)
	{
		if (game->state == home_screen)
			game->state = game_screen;
	}
	if (game->state == home_screen)
		return ;
	// Show inventory
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
	// Show map
	if (game->keys.space && !game->keys.space_pressed)
	{
		game->keys.space_pressed = true;
		if (game->state == game_screen)
			game->state = map_focus;
		else if (game->state == map_focus)
		{
			game->map.focus_rendered = false;
			game->state = game_screen;
		}
	}
	else if (!game->keys.space)
		game->keys.space_pressed = false;
	// Show menu
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
		if (game->keys.left)
			rotate(game, 1);
		// look right
		if (game->keys.right)
			rotate(game, 0);
		// move forward
		if (game->keys.w)
		{
			// Move forward
			if (game->map.map_grid[(int)(game->player.pos_y + game->player.dir_y * game->player.speed + 0.21)][(int)(game->player.pos_x)] == 0 &&
				game->map.map_grid[(int)(game->player.pos_y + game->player.dir_y * game->player.speed - 0.21)][(int)(game->player.pos_x)] == 0)
			{
				game->player.pos_y += game->player.dir_y * game->player.speed;
			}
			if (game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.pos_x + game->player.dir_x * game->player.speed + 0.21)] == 0 &&
				game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.pos_x + game->player.dir_x * game->player.speed - 0.21)] == 0)
			{
				game->player.pos_x += game->player.dir_x * game->player.speed;
			}
		}
		if (game->keys.s)
		{
			// Move backward
			if (game->map.map_grid[(int)(game->player.pos_y - game->player.dir_y * game->player.speed + 0.21)][(int)(game->player.pos_x)] == 0 &&
				game->map.map_grid[(int)(game->player.pos_y - game->player.dir_y * game->player.speed - 0.21)][(int)(game->player.pos_x)] == 0)
			{
				game->player.pos_y -= game->player.dir_y * game->player.speed;
			}
			if (game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.pos_x - game->player.dir_x * game->player.speed + 0.21)] == 0 &&
				game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.pos_x - game->player.dir_x * game->player.speed - 0.21)] == 0)
			{
				game->player.pos_x -= game->player.dir_x * game->player.speed;
			}
		}
		if (game->keys.a)
		{
			// Strafe left
			if (game->map.map_grid[(int)(game->player.pos_y - game->player.plane_y * game->player.speed + 0.21)][(int)(game->player.pos_x)] == 0 &&
				game->map.map_grid[(int)(game->player.pos_y - game->player.plane_y * game->player.speed - 0.21)][(int)(game->player.pos_x)] == 0)
			{
				game->player.pos_y -= game->player.plane_y * game->player.speed;
			}
			if (game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.pos_x - game->player.plane_x * game->player.speed + 0.21)] == 0 &&
				game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.pos_x - game->player.plane_x * game->player.speed - 0.21)] == 0)
			{
				game->player.pos_x -= game->player.plane_x * game->player.speed;
			}
		}
		if (game->keys.d)
		{
			// Strafe right
			if (game->map.map_grid[(int)(game->player.pos_y + game->player.plane_y * game->player.speed + 0.21)][(int)(game->player.pos_x)] == 0 &&
				game->map.map_grid[(int)(game->player.pos_y + game->player.plane_y * game->player.speed - 0.21)][(int)(game->player.pos_x)] == 0)
			{
				game->player.pos_y += game->player.plane_y * game->player.speed;
			}
			if (game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.pos_x + game->player.plane_x * game->player.speed + 0.21)] == 0 &&
				game->map.map_grid[(int)(game->player.pos_y)][(int)(game->player.pos_x + game->player.plane_x * game->player.speed - 0.21)] == 0)
			{
				game->player.pos_x += game->player.plane_x * game->player.speed;
			}
		}
		if (game->keys.e)
		{
			detect_door(game);
		}
	}
}
