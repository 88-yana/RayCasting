#include "cub3D.h"
#include "math.h"

void	init_image(t_game *game)
{
	t_image	*img;

	img = &game->img;
	img->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	draw_minimap(game);
	mlx_put_image_to_window(&game->mlx, game->win, game->img.img, 0, 0);
}

/**
 * @brief MLXの初期化処理
 *
 * @param game
 */
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	init_image(game);
	load_images(game);
	load_player(game);
	game->is_minimap = true;
	set_event_hooks(game);
}
