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
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->key_store |= MOVE_BACKWARD;
	if (keycode == KEY_A)
		game->key_store |= MOVE_LEFT;
	if (keycode == KEY_D)
		game->key_store |= MOVE_RIGHT;
	if (keycode == KEY_LEFT)
		game->key_store |= ROTATE_LEFT;
	if (keycode == KEY_RIGHT)
		game->key_store |= ROTATE_RIGHT;
	if (keycode == KEY_M)
		game->key_store |= SWITCH_MINIMAP;
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
	if (keycode == KEY_W || keycode == KEY_UP)
		game->key_store &= ~MOVE_FORWARD;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->key_store &= ~MOVE_BACKWARD;
	if (keycode == KEY_A)
		game->key_store &= ~MOVE_LEFT;
	if (keycode == KEY_D)
		game->key_store &= ~MOVE_RIGHT;
	if (keycode == KEY_LEFT)
		game->key_store &= ~ROTATE_LEFT;
	if (keycode == KEY_RIGHT)
		game->key_store &= ~ROTATE_RIGHT;
	if (keycode == KEY_M)
		game->key_store &= ~SWITCH_MINIMAP;
	return (0);
}

void	render(t_game *game)
{
	draw_back(game);
	ray_casting(game);
	draw_rays_on_screen(game);
	if (game->is_minimap == true)
	{
		draw_minimap(game);
		draw_rays_on_minimap(game);
		draw_player_on_minimap(game);
	}
	mlx_put_image_to_window(&game->mlx, game->win, game->img.img, 0, 0);
}

void	player_move(t_game *game)
{
	game->player.move = ft_mul_vec(game->player.move, MOVE_COEF);
	game->player.pos.x += game->player.move.x;
	game->player.pos.y -= game->player.move.y;
}

int	update_game(t_game *game)
{
	fetch_key_input(game);
	check_collision(game);
	player_move(game);
//	print_debug_info(game);
	render(game);
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
