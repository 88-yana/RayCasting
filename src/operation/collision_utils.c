/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:16:56 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 14:43:39 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 壁の向きから法線ベクトルを決定する
 *
 * @param wall
 * @return t_vec
 */
t_vec	get_normal_vector(t_news wall)
{
	if (wall & NORTH)
		return ((t_vec){0, -1});
	if (wall & EAST)
		return ((t_vec){-1, 0});
	if (wall & WEST)
		return ((t_vec){1, 0});
	if (wall & SOUTH)
		return ((t_vec){0, 1});
	return ((t_vec){0, 0});
}

/** 衝突した壁の向きを判定（第3・4象限）*/
static t_news	get_collision_dir_quad34(t_vec move, t_vec pos,
	t_vec next_pos, char **map)
{
	if (move.x < 0 && move.y < 0)
	{
		if (map[(int)next_pos.y][(int)pos.x] == '1')
			return (NORTH);
		else if (map[(int)pos.y][(int)next_pos.x] == '1')
			return (EAST);
	}
	else if (move.x >= 0 && move.y < 0)
	{
		if (map[(int)next_pos.y][(int)pos.x] == '1')
			return (NORTH);
		else if (map[(int)pos.y][(int)next_pos.x] == '1')
			return (WEST);
	}
	return (NONE);
}

/** 衝突した壁の向きを判定(第1・2象限) */
t_news	get_collision_dir_quad12(t_vec move,
	t_vec pos, t_vec next_pos, char **map)
{
	if (move.x >= 0 && move.y >= 0)
	{
		if (map[(int)next_pos.y][(int)pos.x] == '1')
			return (SOUTH);
		else if (map[(int)pos.y][(int)next_pos.x] == '1')
			return (WEST);
	}
	else if (move.x < 0 && move.y >= 0)
	{
		if (map[(int)next_pos.y][(int)pos.x] == '1')
			return (SOUTH);
		else if (map[(int)pos.y][(int)next_pos.x] == '1')
			return (EAST);
	}
	return (NONE);
}

/**
 * @brief 衝突した壁の向きを判定
 *
 * @param move
 * @param pos
 * @param next_pos
 * @param map
 * @return t_news
 */
t_news	get_collision_dir(t_vec move, t_vec pos, t_vec next_pos, char **map)
{
	t_news	dir;

	dir = get_collision_dir_quad12(move, pos, next_pos, map);
	if (dir != NONE)
		return (dir);
	dir = get_collision_dir_quad34(move, pos, next_pos, map);
	return (dir);
}
