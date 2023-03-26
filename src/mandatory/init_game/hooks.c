#include "cub3D.h"

int	store_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
		game->key_code = GAME_EXIT;
	if (keycode == KEY_W || keycode == KEY_UP)
		game->key_code = MOVE_FORWARD;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->key_code = MOVE_BACKWARD;
	else if (keycode == KEY_A)
		game->key_code = MOVE_LEFT;
	else if (keycode == KEY_D)
		game->key_code = MOVE_RIGHT;
	else if (keycode == KEY_LEFT)
		game->key_code = ROTATE_LEFT;
	else if (keycode == KEY_RIGHT)
		game->key_code = ROTATE_RIGHT;
	return (0);
}

int	store_key_release(int keycode, t_game *game)
{
	(void)keycode;
	game->key_code = 0;
	return (0);
}

int	update_game(t_game *game)
{
	move_player(game);
	print_debug_info(game);
	return (0);
}

void	set_event_hooks(t_game *game)
{
	mlx_hook(game->win, 02, 1L << 0, store_key_press, game);
	mlx_hook(game->win, 03, 1L << 0, store_key_release, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop_hook(game->mlx, update_game, game);
}
