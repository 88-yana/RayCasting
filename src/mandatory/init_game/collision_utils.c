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

/**
 * @brief 衝突した壁の向きを判定（TODO: norm対応）
 *
 * @param move
 * @param pos
 * @param next_pos
 * @param map
 * @return t_news
 */
t_news	get_collision_direction(t_vec move, t_vec pos, t_vec next_pos, char **map)
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
	else if (move.x < 0 && move.y < 0)
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
