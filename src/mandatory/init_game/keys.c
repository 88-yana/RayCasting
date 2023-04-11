#include "cub3D.h"

/**
 * @brief キー入力：移動
 *
 * @param game
 */
void	move_player(t_game *game)
{
	t_vec	dir;

	dir = game->player.dir;
	if (game->key_store & MOVE_FORWARD)
		game->player.move = dir;
	if (game->key_store & MOVE_BACKWARD)
		game->player.move = ft_rotate_vec(dir, M_PI);
	if (game->key_store & MOVE_LEFT)
		game->player.move = ft_rotate_vec(dir, M_PI_2);
	if (game->key_store & MOVE_RIGHT)
		game->player.move = ft_rotate_vec(dir, -M_PI_2);
}

/**
 * @brief キー入力：回転
 *
 * @param game
 */
void	rotate_player(t_game *game)
{
	t_vec	*dir;

	dir = &game->player.dir;
	if (game->key_store & ROTATE_LEFT)
		*dir = ft_rotate_vec(*dir, ft_deg_to_rad(1));
	if (game->key_store & ROTATE_RIGHT)
		*dir = ft_rotate_vec(*dir, ft_deg_to_rad(-1));
}

/**
 * @brief キー入力：システム
 *
 * @detail 終了操作（Q）およびミニマップの表示切り替え（M）
 * @param game
 */
void	config_game(t_game *game)
{
	if (game->key_store & GAME_EXIT)
		exit_game(MSG_EXIT_GAME);
	if (game->key_store & SWITCH_MINIMAP)
		switch_display_minimap(game);
}

/**
 * @brief 入力されたキーコードを取得し、対応する操作を行う。
 *
 * @param game
 */
void	fetch_key_input(t_game *game)
{
	if (game->key_store & MOVE)
		move_player(game);
	if (game->key_store & ROTATE)
		rotate_player(game);
	if (game->key_store & CONFIG)
		config_game(game);
}
