#include "cub3D.h"
#include "ft_snprintf.h"

void	print_debug_info(t_game *game)
{
	char			buff[50];
	int				color;
	t_player_info	*player;

	player = &game->player;
	color = create_trgb(0, 255, 255, 255);
	ft_snprintf(buff, 50, "pos:[%d, %d] dir:[%d, %d]", \
		player->pos.x, player->pos.y, player->dir.x, player->dir.y);
	mlx_string_put(game->mlx, game->win, 16, 16, color, buff);
	if (game->key_code)
	{
		ft_snprintf(buff, 50, "KEY: %d", game->key_code);
		mlx_string_put(game->mlx, game->win, 32, 32, color, buff);
	}
}

