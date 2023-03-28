#include "cub3D.h"

#define MOVE_COEF 0.1f

/**
 * @brief キー入力：移動
 *
 * @param game
 */
void	move_player(t_game *game)
{
	t_vec	*dir;

	pos = &game->player.pos;
	if (game->key_code & MOVE_FORWARD)
		*pos = ft_add_vec(*pos, (ft_mul_vec((t_vec){0, -1}, MOVE_COEF)));
	else if (game->key_code & MOVE_BACKWARD)
		*pos = ft_add_vec(*pos, (ft_mul_vec((t_vec){0, 1}, MOVE_COEF)));
	else if (game->key_code & MOVE_LEFT)
		*pos = ft_add_vec(*pos, (ft_mul_vec((t_vec){-1, 0}, MOVE_COEF)));
	else if (game->key_code & MOVE_RIGHT)
		*pos = ft_add_vec(*pos, (ft_mul_vec((t_vec){1, 0}, MOVE_COEF)));
}

/**
 * @brief キー入力：回転
 *
 * @param game
 */
void	rotate_player(t_game *game)
{
	// t_player_info	*player;

	// player = &game->player;
	t_vec	*dir;

	dir = &game->player.dir;
	if (game->key_code & ROTATE_LEFT)
	{
		// dirを回転させたい
		*dir = ft_rotate_vec(*dir, 2);
	}
	if (game->key_code & ROTATE_RIGHT)
	{
		// dirを回転させたい
		*dir = ft_rotate_vec(*dir, -2);
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
