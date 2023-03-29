#include "cub3D.h"

typedef struct s_point {
	t_vec x_pos;
	t_vec y_pos;
}	t_point;

typedef struct s_raycasting {
	float	dx;
	float	dy;

}	t_raycasting;

// void	find_nearest_grid_lines(t_ray *nearest_grid, t_vec position, t_vec direction)
// {
// 	nearest_grid->x = find_nearest_grid_x(position, direction);
// 	nearest_grid->y = find_nearest_grid_y(position, direction);
// }

// /**
//  * @brief 壁との距離を返す関数
//  * 
//  * @param position 
//  * @return float 
//  */
// float	distance_to_wall(t_vec position, t_vec, direction)
// {
// 	t_ray	nearest_grid;
// 	t_ray	next_grid;

// 	find_nearest_grid_lines(&nearest_grid, position, direction);
// 	find_nearest_grid_lines(&next_grid, position, direction);
// 	next_grid = nearest_grid(position, direction);
// 	distance_between_grids(nearest_grid, direction);
// 	calc_distance_to_wall(position, direction);
// }

// // t_ray nearest_grid_line;
// // t_ray next_grid_line;

// // next_grid_line.x - nearest_grid_line.x;

// void	find_nearest_vertical_line();
// void	find_nearest_horizontal_line();


// next_x_pos = find_nearest_vertical_line(nearest_x_pos);
// next_y_pos = find_nearest_horizontal_line(nearest_y_pos);

// t_vec calc_digital_x_difference(t_point nearest, char flag)
// {
// 	t_pos	next;
// 	t_vec	diff_vec;

// 	find_nearest_grid_lines(nearest, &next);
// 	diff_vec = next.x_pos - nearest.x_pos;
// 	if (flag == 'x')
// 		nearest.x_pos
// }

bool	is_wall(char **map, t_vec ray_pos, float direction, char flag)
{
	if (flag == 'x')
	{
		if (direction >= 0)
			if (map[(int)floor(ray_pos.y)][(int)ray_pos.x] == '1')
				return (true);
		if (direction < 0)
			if (map[(int)floor(ray_pos.y)][(int)ray_pos.x - 1] == '1')
				return (true);
	}
	else
	{
		if (direction >= 0)
			if (map[(int)ray_pos.y][(int)floor(ray_pos.x)] == '1')
				return (true);
		if (direction < 0)
			if (map[(int)ray_pos.y - 1][(int)floor(ray_pos.x)] == '1')
				return (true);
	}
	return (false);
}


t_vec	calc_digital_difference(t_point nearest, char flag)
{
	t_point	next;

	find_nearest_grid_lines(nearest, &next);
	if (flag == 'x')
		return (ft_sub_vec(next.x_pos, nearest.x_pos));
	else
		reutrn (ft_sub_vec(next.y_pos, nearest.y_pos));
}

t_vec	touch_wall(t_game *game, t_vec ray_pos, t_vec diff_vec, char flag)
{
	float	direction;

	if (flag == 'x')
		direction = game->player.dir.x;
	else
		direction = game->player.dir.y;
	while(1)
	{
		if (is_wall(game->map, ray_pos, direction, flag))
			return ray_pos;
		ft_add_vec(ray_pos, diff_vec);
	}
}

float	find_wall(t_game *game, t_vec nearest, t_vec diff_vec, char flag)
{
	t_vec wall_pos;
	
		wall_pos = touch_wall(game, nearest, diff_vec, flag);
	return (ft_distance_vec(game->player.pos, wall_pos));
}

float find_nearest_grid_lines(t_player_info *player, t_point *nearest)
{
	float pos_to_vertical_line;
	float y_diff;

	pos_to_vertical_line = ceil(player->pos.x) - player->pos.x;
	y_diff = player->dir.y * pos_to_vertical_line / player->dir.x; //FIXME:dir.xが0でない保証をしないといけない
	nearest->y_pos = player->pos.y + y_diff;
	player->dir;

	find_nearest_x_pos(nearest_x_pos);
	find_nearest_y_pos(nearest_y_pos);
}

float	find_nearest_grid_on_line(t_player_info *player, t_point *nearest)
{
	player->pos;
	nearest find_nearest_x_pos(nearest_x_pos);
	find_nearest_y_pos(nearest_y_pos);
}

/**
 * @brief playerから壁までの距離を測る
 * 最初に一番近いグリッド線上の位置を見つける
 * その位置と次に近い位置から，差分(= digital difference)を計測
 * 一番近いグリッド線上から，差分を足していき，壁の位置を見つけ，playerの位置との差から,壁までの距離を求める
 * @param game 
 * @return float 
 */
float	measure_distance_to_wall(t_game *game, t_vec theta)
{
	t_point	nearest;
	t_vec	x_digital_diff_vec;
	t_vec	y_digital_diff_vec;
	float	x_distance_to_wall;
	float	y_distance_to_wall;

	find_nearest_grid_on_line(&game->player, &nearest);
	x_digital_diff_vec = calc_digital_difference(nearest, 'x');//FIXME: 差分がない場合＝水平，垂直の場合を考える
	y_digital_diff_vec = calc_digital_difference(nearest, 'y');
	x_distance_to_wall = find_wall(game, nearest.x_pos, x_digital_diff_vec, 'x');
	y_distance_to_wall = find_wall(game, nearest.y_pos, y_digital_diff_vec, 'y');
	if (x_distance_to_wall < y_distance_to_wall)
		return x_distance_to_wall;
	else
		return y_distance_to_wall;
}

float	get_wall_hight(t_game *game)
{
	float distance_to_wall;

	distance_to_wall = measure_distance_to_wall(game);
	calculate_wall_hight();
}
