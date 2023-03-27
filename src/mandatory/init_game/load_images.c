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
	game->images.north = xpm_file_to_image(game, game->map_info.path.north);
	game->images.south = xpm_file_to_image(game, game->map_info.path.south);
	game->images.west = xpm_file_to_image(game, game->map_info.path.west);
	game->images.east = xpm_file_to_image(game, game->map_info.path.east);
}
