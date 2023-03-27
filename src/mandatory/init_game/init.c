#include "cub3D.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	load_images(game);
	load_player(game);
	set_event_hooks(game);
}
