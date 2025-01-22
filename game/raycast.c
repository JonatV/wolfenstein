#include "../wolfenstein.h"

int	raycast(t_game *game)
{
	int	current_x;
	int	number_of_the_wall_hitted;

	number_of_the_wall_hitted = 0;
	current_x = 0;
	while (current_x < (int)game->win_w)
	{
		// STARTwe need to initialize the current column ray index
		game->raycast.hit = false;
		game->raycast.camera = 2 * (double)current_x / (double)game->win_w - 1;
		game->raycast.ray_dir_x = game->player.dir_x + game->player.plane_x * game->raycast.camera;
		game->raycast.ray_dir_y = game->player.dir_y + game->player.plane_y * game->raycast.camera;
		game->raycast.map_x = (int)game->player.pos_x;
		game->raycast.map_y = (int)game->player.pos_y;
		game->raycast.delta_dist_x = fabs(1.0 / game->raycast.ray_dir_x);	// this serves as the distance the ray has to travel to go from 1 x-side to the next x-side
		game->raycast.delta_dist_y = fabs(1.0 / game->raycast.ray_dir_y);	// this serves as the distance the ray has to travel to go from 1 y-side to the next y-side
																			// function fabs() returns the absolute value of a floating point number
		// END init
		// START we need to calculate the step and initial side distance
		if (game->raycast.ray_dir_x < 0) // if the ray is going left
		{
			game->raycast.step_x = -1;
			game->raycast.side_dist_x = (game->player.pos_x - game->raycast.map_x) * game->raycast.delta_dist_x;
		}
		else // if the ray is going right
		{
			game->raycast.step_x = 1;
			game->raycast.side_dist_x = (game->raycast.map_x + 1.0 - game->player.pos_x) * game->raycast.delta_dist_x;
		}
		if (game->raycast.ray_dir_y < 0) // if the ray is going up
		{
			game->raycast.step_y = -1;
			game->raycast.side_dist_y = (game->player.pos_y - game->raycast.map_y) * game->raycast.delta_dist_y;
		}
		else // if the ray is going down
		{
			game->raycast.step_y = 1;
			game->raycast.side_dist_y = (game->raycast.map_y + 1.0 - game->player.pos_y) * game->raycast.delta_dist_y;
		}
		// END step and initial side distance
		// START we need to perform DDA
		while (!game->raycast.hit)
		{
			if (game->raycast.side_dist_x < game->raycast.side_dist_y)
			{
				game->raycast.side_dist_x += game->raycast.delta_dist_x;
				game->raycast.map_x += game->raycast.step_x;
				game->raycast.side = EW;
				if (game->raycast.ray_dir_x < 0)
					game->raycast.wall_orientation = EAST; // todo check to be sure
				else
					game->raycast.wall_orientation = WEST; // todo check to be sure
			}
			else
			{
				game->raycast.side_dist_y += game->raycast.delta_dist_y;
				game->raycast.map_y += game->raycast.step_y;
				game->raycast.side = NS;
				if (game->raycast.ray_dir_y < 0)
					game->raycast.wall_orientation = SOUTH; // todo check to be sure
				else
					game->raycast.wall_orientation = NORTH; // todo check to be sure
			}
			if (game->map.map_grid[(int)game->raycast.map_y][(int)game->raycast.map_x] > 0) // for now eveything is a wall
			{
				game->raycast.hit = true;
				number_of_the_wall_hitted = game->map.map_grid[(int)game->raycast.map_y][(int)game->raycast.map_x];
			}
		}
		// END DDA
		// START we need to calculate the distance to the wall
		if (game->raycast.side == EW)
		{
			game->raycast.perp_wall_dist = game->raycast.side_dist_x - game->raycast.delta_dist_x;
			game->raycast.wall_x = game->player.pos_y + game->raycast.perp_wall_dist * game->raycast.ray_dir_y;
		}
		else
		{
			game->raycast.perp_wall_dist = game->raycast.side_dist_y - game->raycast.delta_dist_y;
			game->raycast.wall_x = game->player.pos_x + game->raycast.perp_wall_dist * game->raycast.ray_dir_x;
		}
		// END distance to the wall
		// START we need to calculate the height of the wall strip
		game->raycast.wall_height = (double)game->win_h / game->raycast.perp_wall_dist;
		// END height of the wall strip
		game->raycast.wall_x -= floor(game->raycast.wall_x); // this is to get the texture x coordinate from the fractional part of wall_x
		// START we need to calculate the color of the wall strip
		put_column_to_win(game, current_x, number_of_the_wall_hitted); // this function will draw the wall strip
		// END color of the wall strip
		current_x++;
	}
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.scr.mlx_img, 0, 0);
	return (0);
}
