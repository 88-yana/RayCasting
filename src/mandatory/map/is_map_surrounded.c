/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_surrounded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:58:51 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/24 10:45:34 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief map内の要素の場合true
 * 
 * @param c 
 * @return true 
 * @return false 
 */
static bool	is_in_map(char c)
{
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'W')
		return (true);
	if (c == 'E')
		return (true);
	if (c == ROAD)
		return (true);
	return (false);
}

/**
 * @brief 範囲外やMARK,WALLであったら,return
 * マップ内に到達したら,エラー
 * 現時点にMARKを付けて，探索
 * @param game 
 * @param i 
 * @param j 
 */
void	dfs(t_game *game, size_t i, size_t j)
{
	if (i < 0 || game->map_info.height + SP <= i)
		return ;
	if (j < 0 || game->map_info.width + SP <= j)
		return ;
	if (game->map[i][j] == MARK || game->map[i][j] == WALL)
		return ;
	if (is_in_map(game->map[i][j]))
		handle_error(ERR_MAP);
	game->map[i][j] = MARK;
	dfs(game, i - 1, j);
	dfs(game, i + 1, j);
	dfs(game, i, j - 1);
	dfs(game, i, j + 1);
}

/**
 * @brief map外であるスペースを探す
 * スペースからdfsを開始する
 * map内に侵入できないかをcheckする
 * @param game 
 * @return true 
 * @return false 
 */
bool	is_map_surrounded(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->map_info.height + SP)
	{
		j = 0;
		while (j < game->map_info.width + SP)
		{
			if (game->map[i][j] == OUT)
				dfs(game, i, j);
			j++;
		}
		i++;
	}
	return (true);
}
