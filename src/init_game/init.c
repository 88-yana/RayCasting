/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:16:52 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 13:27:39 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "math.h"

/**
 * @brief ゲーム中に使用するイベントフックを設定
 *
 * @param game
 */
void	set_event_hooks(t_game *game)
{
	mlx_hook(game->win, 02, 1L << 0, store_key_press, game);
	mlx_hook(game->win, 03, 1L << 0, store_key_release, game);
	mlx_hook(game->win, 06, 1L << 6, store_mouse_position, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_expose_hook (game->win, render, game);
}

void	init_image(t_game *game)
{
	t_image	*img;

	img = &game->img;
	img->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
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
	game->player.move = (t_vec){0, 0};
	game->mouse_pos_x = 0;
	set_event_hooks(game);
}
