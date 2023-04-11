#include "cub3D.h"
#include "ft_snprintf.h"
#include "ft_printf.h"

#define RED "\033[31m"
#define DEFAULT "\033[m"

/**
 * @brief スクリーンへの出力
 *
 * @param game
 * @param str
 * @param offset
 */
void	putstr_to_window(t_game *game, char *str)
{
	int	offset;

	offset = WIN_HEIGHT - TIP_SIZE;
	mlx_string_put(game->mlx, game->win, TIP_SIZE, offset, COLOR_WHITE, str);
	return ;
}

/**
 * @brief コンソールへの出力
 *
 * @param game
 * @param str
 */
static void	putstr_to_console(t_game *game, char *str)
{
	(void)game;
	ft_printf("\033[1K\033[1G");
	ft_printf(RED);
	ft_printf("%s", str);
	ft_printf(DEFAULT);
}

/**
 * @brief ゲーム中のデバッグ情報を出力する。
 *
 * @detail TODO: snprintfを使用しているため提出時に削除すること。
 * @param game
 */
void	print_debug_info(t_game *game)
{
	char			buff[100];
	t_player_info	*player;

	player = &game->player;
	snprintf(buff, 100, "pos:{%f, %f} dir:{%f, %f} move:{%f, %f} ", \
		player->pos.x, player->pos.y, player->dir.x, player->dir.y, player->move.x, player->move.y);
//	putstr_to_window(game, buff);
	putstr_to_console(game, buff);
}
