#include "cub3D.h"
#include "math.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_rectangle(t_image *img, t_vec *p, int size, int color)
{
	size_t	i;
	size_t	j;

	i = p->y;
	while (i < p->y + size)
	{
		j = p->x;
		while (j < p->x + size)
		{
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->map_info.height + 2)
	{
		j = 0;
		while (j < game->map_info.width + 2)
		{
			if (game->map[i][j] == '1')
				draw_rectangle(&game->img, &(t_vec){i * 10, j * 10}, 10, COLOR_LGRAY);
			else if (game->map[i][j] == '0' || !is_start_position(game->map[i][j]))
				draw_rectangle(&game->img, &(t_vec){i * 10, j * 10}, 10, COLOR_GRAY);
			j++;
		}
		i++;
	}
}


void	draw_player_pos(t_game *game)
{
	my_mlx_pixel_put(&game->img, game->player.pos.x * 10, game->player.pos.y * 10, COLOR_RED);
}

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
	set_event_hooks(game);
}
