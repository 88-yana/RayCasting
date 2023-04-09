#include "cub3D.h"

/**
 * @brief mlxライブラリを用いた変換およびエラー処理
 *
 * @param game
 * @param img_file
 * @return void*
 */
static void	*xpm_file_to_image(t_game *game, char *img_file)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, img_file, &img_width, &img_height);
	if (img == NULL)
		handle_error(ERR_FILE_FORMAT);
	return (img);
}

/**
 * @brief xpmファイルを画像イメージに変換する
 *
 * @param game
 */
void	load_images(t_game *game)
{
	void			*north;
	void			*south;
	void			*east;
	void			*west;
	t_image_data	*images;

	images = &game->images;
	north = xpm_file_to_image(game, game->map_info.path.north);
	south = xpm_file_to_image(game, game->map_info.path.south);
	west = xpm_file_to_image(game, game->map_info.path.west);
	east = xpm_file_to_image(game, game->map_info.path.east);
	images->north_addr = mlx_get_data_addr(north, &images->north.bpp,
			&images->north.line_len, &images->north.endian);
	images->south_addr = mlx_get_data_addr(south, &images->south.bpp,
			&images->south.line_len, &images->south.endian);
	images->east_addr = mlx_get_data_addr(east, &images->east.bpp,
			&images->east.line_len, &images->east.endian);
	images->west_addr = mlx_get_data_addr(west, &images->west.bpp,
			&images->west.line_len, &images->west.endian);
}
