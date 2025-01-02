#include "../wolfenstein.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
	{
		printf("Keycode: [%d] (move forward)\n", keycode);
		game->keys.w = true;
	}
	else if (keycode == XK_s)
	{
		printf("Keycode: [%d] (move backward)\n", keycode);
		game->keys.s = true;
	}
	else if (keycode == XK_a)
	{
		printf("Keycode: [%d] (look left)\n", keycode);
		game->keys.a = true;
	}
	else if (keycode == XK_d)
	{
		printf("Keycode: [%d] (look right)\n", keycode);
		game->keys.d = true;
	}
	else if (keycode == XK_e)
	{
		printf("Keycode: [%d] (interact)\n", keycode);
		game->keys.e = true;
	}
	else if (keycode == XK_Return)
	{
		printf("Keycode: [%d] (enter)\n", keycode);
		game->keys.enter = true;
	}
	else if (keycode == XK_space)
	{
		printf("Keycode: [%d] (map(space))\n", keycode);
		game->keys.space = true;
	}
	else if (keycode == XK_Tab)
	{
		printf("Keycode: [%d] (inventory)\n", keycode);
		game->keys.tab = true;
	}
	else if (keycode == XK_m)
	{
		printf("Keycode: [%d] (menu)\n", keycode);
		game->keys.m = true;
	}
	else if (keycode == XK_Escape)
	{
		printf("Keycode: [%d] (close game)\n", keycode);
		game->keys.esc = true;
	}
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys.w = false;
	else if (keycode == XK_s)
		game->keys.s = false;
	else if (keycode == XK_a)
		game->keys.a = false;
	else if (keycode == XK_d)
		game->keys.d = false;
	else if (keycode == XK_e)
		game->keys.e = false;
	else if (keycode == XK_Return)
		game->keys.enter = false;
	else if (keycode == XK_space)
		game->keys.space = false;
	else if (keycode == XK_Tab)
		game->keys.tab = false;
	else if (keycode == XK_m)
		game->keys.m = false;
	else if (keycode == XK_Escape)
		game->keys.esc = false;
	return (0);
}
