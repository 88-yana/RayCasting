#include "cub3D.h"

/**
 * @brief キー入力：移動
 *
 * @param game
 */
void	move_player(t_game *game)
{
	t_player_info	*player;

	player = &game->player;
	if (game->key_code & MOVE_FORWARD)
		ft_add_vec(player->pos, (ft_mul_vec((t_vec){0, -1}, 0.1)));
	else if (game->key_code & MOVE_BACKWARD)
		ft_add_vec(player->pos, (ft_mul_vec((t_vec){0, 1}, 0.1)));
	else if (game->key_code & MOVE_LEFT)
		ft_add_vec(player->pos, (ft_mul_vec((t_vec){-1, 0}, 0.1)));
	else if (game->key_code & MOVE_RIGHT)
		ft_add_vec(player->pos, (ft_mul_vec((t_vec){1, 0}, 0.1)));
}

/**
 * @brief キー入力：回転
 *
 * @param game
 */
void	rotate_player(t_game *game)
{
	t_player_info	*player;

	player = &game->player;
	if (game->key_code & ROTATE_LEFT)
	{
		// dirを回転させたい
	}
	if (game->key_code & ROTATE_RIGHT)
	{
		// dirを回転させたい
	}
}

/**
 * @brief キー入力：システム
 *
 * @detail TODO: Mandatoryの実装では終了操作のみ
 * @param game
 */
void	config_game(t_game *game)
{
	if (game->key_code & GAME_EXIT)
		exit_game(MSG_EXIT_GAME);
}

/**
 * @brief 入力されたキーコードを取得し、対応する操作を行う。
 *
 * @param game
 */
void	fetch_key_input(t_game *game)
{
	if (game->key_code & MOVE)
		move_player(game);
	else if (game->key_code & ROTATE)
		rotate_player(game);
	else if (game->key_code & CONFIG)
		config_game(game);
}
