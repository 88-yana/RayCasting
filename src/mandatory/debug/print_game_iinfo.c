#include "cub3D.h"
#include "ft_snprintf.h"
#include "ft_printf.h"

static void	putstr_to_window(t_game *game, char *str, size_t offset)
{
	int	color;

	color = create_trgb(0, 255, 255, 255);
	mlx_string_put(game->mlx, game->win, 16, offset, color, str);
	return ;
}

/**
 * @brief ゲーム中のデバッグ情報を出力する。
 *
 * @detail TODO: snprintfを使用しているため提出時に削除すること。
 * @param game
 */
void	print_debug_info(t_game *game)
{
	char			buff[50];
	int				color;
	t_player_info	*player;

	game->player.pos.x = 0;
	game->player.pos.y = 0;
	player = &game->player;
	color = create_trgb(0, 255, 255, 255);
	snprintf(buff, 50, "pos:{%f, %f} dir:{%f, %f}", \
		player->pos.x, player->pos.y, player->dir.x, player->dir.y);
	putstr_to_window(game, buff, 16);
	if (game->key_code)
	{
		ft_snprintf(buff, 50, "KEY: %d", game->key_code);
		putstr_to_window(game, buff, 32);
	}
}