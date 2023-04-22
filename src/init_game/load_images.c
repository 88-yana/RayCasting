/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:16:48 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 01:16:49 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief mlxライブラリを用いた変換およびエラー処理
 *
 * @param game
 * @param img_file
 * @return void*
 */
static void	*xpm_file_to_image(t_game *game, t_image *image, char *img_file)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, img_file, &image->width, &image->height);
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
	north = xpm_file_to_image(game, &images->north, game->map_info.path.north);
	south = xpm_file_to_image(game, &images->south, game->map_info.path.south);
	west = xpm_file_to_image(game, &images->west, game->map_info.path.west);
	east = xpm_file_to_image(game, &images->east, game->map_info.path.east);
	images->north.addr = mlx_get_data_addr(north, &images->north.bpp, &images->north.line_len, &images->north.endian);
	images->south.addr = mlx_get_data_addr(south, &images->south.bpp, &images->south.line_len, &images->south.endian);
	images->east.addr = mlx_get_data_addr(east, &images->east.bpp, &images->east.line_len, &images->east.endian);
	images->west.addr = mlx_get_data_addr(west, &images->west.bpp, &images->west.line_len, &images->west.endian);
}
