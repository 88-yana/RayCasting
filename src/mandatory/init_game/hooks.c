#include "cub3D.h"

/**
 * @brief 押下されたキーをストアに一時格納する。
 *
 * @param keycode
 * @param game
 * @return int
 */
int	store_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		game->key_store |= MOVE_FORWARD;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->key_store |= MOVE_BACKWARD;
	else if (keycode == KEY_A)
		game->key_store |= MOVE_LEFT;
	else if (keycode == KEY_D)
		game->key_store |= MOVE_RIGHT;
	else if (keycode == KEY_LEFT)
		game->key_store |= ROTATE_LEFT;
	else if (keycode == KEY_RIGHT)
		game->key_store |= ROTATE_RIGHT;
	return (0);
}

/**
 * @brief キー入力のストアをクリアする。
 *
 * @param keycode
 * @param game
 * @return int
 */
int	store_key_release(int keycode, t_game *game)
{
	(void)keycode;
	if (keycode == KEY_Q || keycode == KEY_ESC)
		game->key_store = GAME_EXIT;
	else if (keycode == KEY_W || keycode == KEY_UP)
		game->key_store &= ~MOVE_FORWARD;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->key_store &= ~MOVE_BACKWARD;
	else if (keycode == KEY_A)
		game->key_store &= ~MOVE_LEFT;
	else if (keycode == KEY_D)
		game->key_store &= ~MOVE_RIGHT;
	else if (keycode == KEY_LEFT)
		game->key_store &= ~ROTATE_LEFT;
	else if (keycode == KEY_RIGHT)
		game->key_store &= ~ROTATE_RIGHT;
	return (0);
}

int	update_game(t_game *game)
{
	check_collision(game);
	fetch_key_input(game);
	print_debug_info(game);
	draw_minimap(game);
	ray_casting(game);
	draw_player_position(game);
	draw_wall_intersection(game);
	mlx_put_image_to_window(&game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

/**
 * @brief ゲーム中に使用するイベントフックを設定
 *
 * @param game
 */
void	set_event_hooks(t_game *game)
{
	mlx_hook(game->win, 02, 1L << 0, store_key_press, game);
	mlx_hook(game->win, 03, 1L << 0, store_key_release, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop_hook(game->mlx, update_game, game);
//	mlx_expose_hook (game->win, render_map, game);
}
