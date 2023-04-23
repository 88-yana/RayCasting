/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:16:46 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 01:16:47 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief  操作中の要素がスタート位置（NEWS）かどうか判定する
 *
 * @param tile
 * @return true
 * @return false
 */
bool	is_start_position(char tile)
{
	if (ft_strchr("NEWS", tile))
		return (true);
	return (false);
}

/**
 * @brief 取得した座標・方向を初期状態として保存する。
 *
 * @param game
 * @param x
 * @param y
 */
static void	set_start_position(t_game *game, size_t x, size_t y)
{
	if (game->map[x][y] == 'N')
		game->player.dir = (t_vec){0, 1};
	if (game->map[x][y] == 'S')
		game->player.dir = (t_vec){0, -1};
	if (game->map[x][y] == 'W')
		game->player.dir = (t_vec){-1, 0};
	if (game->map[x][y] == 'E')
		game->player.dir = (t_vec){1, 0};
}

/**
 * @brief プレーヤーの初期座標・方向を設定する
 *
 * @param game
 */
void	load_player(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->map_info.height)
	{
		j = 0;
		while (j < game->map_info.width)
		{
			if (is_start_position(game->map[i][j]))
			{
				game->player.pos = (t_vec){j + 0.5, i + 0.5};
				set_start_position(game, i, j);
			}
			j++;
		}
		i++;
	}
	game->key_store = 0;
}
