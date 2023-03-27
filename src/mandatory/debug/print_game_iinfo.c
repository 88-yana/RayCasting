#include "cub3D.h"
#include "ft_snprintf.h"
#include "ft_printf.h"

#define RED "\033[31m"
#define DEFAULT "\033[m"

static void	putstr_to_window(t_game *game, char *str, size_t offset)
{
	int	color;

	color = create_trgb(0, 255, 255, 255);
	mlx_string_put(game->mlx, game->win, 16, offset, color, str);
	return ;
}

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
	int				color;
	t_player_info	*player;

	game->player.pos.x = 0;
	game->player.pos.y = 0;
	player = &game->player;
	color = create_trgb(0, 255, 255, 255);
	snprintf(buff, 100, "pos:{%f, %f} dir:{%f, %f} ", \
		player->pos.x, player->pos.y, player->dir.x, player->dir.y);
	putstr_to_window(game, buff, 16);
	putstr_to_console(game, buff);
	if (game->key_code)
	{
		ft_snprintf(buff, 100, "KEY: %d", game->key_code);
		putstr_to_window(game, buff, 32);
		putstr_to_console(game, buff);
	}
}