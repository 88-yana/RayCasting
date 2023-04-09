/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:22:20 by hyanagim          #+#    #+#             */
/*   Updated: 2023/04/09 23:33:22 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
/**
 * @brief char **mapに含まれていいものであればtrue
 * 
 * @param c 
 * @return true 
 * @return false 
 */
static bool	is_valid_identifier(char c)
{
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'W')
		return (true);
	if (c == 'E')
		return (true);
	if (c == '1')
		return (true);
	if (c == '0')
		return (true);
	if (c == ' ')
		return (true);
	return (false);
}

static void	cnt_start(t_map_info *map_info, char c)
{
	if (c == 'N')
		map_info->cnt_n++;
	if (c == 'S')
		map_info->cnt_s++;
	if (c == 'W')
		map_info->cnt_w++;
	if (c == 'E')
		map_info->cnt_e++;
}

/**
 * @brief N,S,W,T合わせて１つであれば，OK
 * 
 * @param map_info 
 * @return true 
 * @return false 
 */
static bool	is_valid_start_num(t_map_info *map_info)
{
	if (map_info->cnt_n + map_info->cnt_s + map_info->cnt_w + map_info->cnt_e == 1)
		return (true);
	return (false);
}

/**
 * @brief mapの要素として，適当なものしかないか
 * スタートの数が１つだけかを調べる
 * 
 * @param game 
 * @return true 
 * @return false 
 */
static void	check_valid_map_contents(t_game *game)
{
	size_t	i;
	size_t	j;

	game->map_info.cnt_n = 0;
	game->map_info.cnt_s = 0;
	game->map_info.cnt_w = 0;
	game->map_info.cnt_e = 0;
	i = 0;
	while (i < game->map_info.height + SP)
	{
		j = 0;
		while (j < game->map_info.width + SP)
		{
			if (!is_valid_identifier(game->map[i][j]))
				handle_error(ERR_MAP);
			cnt_start(&game->map_info, game->map[i][j]);
			j++;
		}
		i++;
	}
	if (!is_valid_start_num(&game->map_info))
		handle_error(ERR_MAP);
}

bool	check_valid_map(t_game *game)
{
	check_valid_map_contents(game);
	check_map_surrounded(game);
	check_map_size(game);
	return (true);
}
