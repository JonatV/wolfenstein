#include "../wolfenstein.h"

bool	init_keys_struct(t_game *game)
{
	game->keys.w = false;		// FORWARD
	game->keys.a = false;		// LOOK LEFT
	game->keys.s = false;		// BACKWARD
	game->keys.d = false;		// LOOK RIGHT
	game->keys.e = false;		// OPEN DOOR
	game->keys.esc = false;		// LEAVE GAME
	game->keys.enter = false;	// START GAME
	game->keys.space = false;	// SEE MAP
	game->keys.tab = false;		// SEE INVENTORY
	game->keys.m = false;		// MENU
	
	game->keys.m_pressed = false;
	game->keys.tab_pressed = false;
	game->keys.enter_pressed = false;
	game->keys.space_pressed = false;
	return (true);
}
