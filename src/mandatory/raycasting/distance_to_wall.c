#include "cub3D.h"

// typedef struct s_point {
// 	t_vec x_pos;
// 	t_vec y_pos;
// }	t_point;

typedef struct s_raycasting {
	float	dx;
	float	dy;
	t_vec	x_pos_on_grid;
	t_vec	y_pos_on_grid;
	float	x_step;
	float	y_step;
	float	x_tile_step;
	float	y_tile_step;
	float	x_distance_to_wall;
	float	y_distance_to_wall;

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

// t_vec	touch_wall(t_game *game, t_vec ray_pos, t_vec diff_vec, char flag)
// {
// 	float	direction;

// 	if (flag == 'x')
// 		direction = game->player.dir.x;
// 	else
// 		direction = game->player.dir.y;
// 	while(1)
// 	{
// 		if (is_wall(game->map, ray_pos, direction, flag))
// 			return ray_pos;
// 		ft_add_vec(ray_pos, diff_vec);
// 	}
// }

// float	find_wall(t_game *game, t_vec nearest, t_vec diff_vec, char flag)
// {
// 	t_vec wall_pos;
	
// 		wall_pos = touch_wall(game, nearest, diff_vec, flag);
// 	return (ft_distance_vec(game->player.pos, wall_pos));
// }

// float find_nearest_grid_lines(t_player_info *player, t_point *nearest)
// {
// 	float pos_to_vertical_line;
// 	float y_diff;

// 	pos_to_vertical_line = ceil(player->pos.x) - player->pos.x;
// 	y_diff = player->dir.y * pos_to_vertical_line / player->dir.x; //FIXME:dir.xが0でない保証をしないといけない
// 	nearest->y_pos = player->pos.y + y_diff;
// 	player->dir;

// 	find_nearest_x_pos(nearest_x_pos);
// 	find_nearest_y_pos(nearest_y_pos);
// }

void	set_nearest_pos(t_player_info *player, t_raycasting *ray_info, float theta)
{
	ray_info->x_pos_on_grid.x = player->pos.x + ray_info->dx;
	ray_info->x_pos_on_grid.y = player->pos.y - ray_info->dx * tan(theta);
	if (tan(theta) != 0)
		ray_info->y_pos_on_grid.x = player->pos.x - ray_info->dy / tan(theta);
	ray_info->y_pos_on_grid.y = player->pos.y + ray_info->dy;
}

void	calc_dx_dy(t_player_info *player, t_raycasting *ray_info)
{
	if (player->dir.x > 0)
		ray_info->dx = ceil(player->pos.x) - player->pos.x;
	else
		ray_info->dx = floor(player->pos.x) - player->pos.x;
	if (player->dir.y > 0)
		ray_info->dy = floor(player->pos.y) - player->pos.y;
	else
		ray_info->dy = ceil(player->pos.y) - player->pos.y;
}

void	calc_tile_step(t_player_info *player, t_raycasting *ray_info)
{
	if (player->dir.x > 0)
		ray_info->x_tile_step = 1;
	else
		ray_info->x_tile_step = -1;
	if (player->dir.y > 0)
		ray_info->y_tile_step = -1;
	else
		ray_info->y_tile_step = 1;
}

float	find_nearest_grid_on_line(t_player_info *player, t_raycasting *ray_info, float theta)
{
	calc_dx_dy(player, ray_info);
	set_nearest_pos(player, ray_info, theta);
}

void	calc_digital_difference(t_raycasting *ray_info, float theta)
{
	if (M_PI < theta && theta < 2 * M_PI)
		ray_info->x_step = - 1 / tan(theta);
	else
		ray_info->x_step = 1 / tan(theta);
	if (M_PI / 2 < theta && theta < 3 * M_PI / 2)
		ray_info->y_step = tan(theta);
	else
		ray_info->y_step = - tan(theta);
}

bool	is_x_wall(char **map, t_player_info *player, t_raycasting *ray_info)
{
	if (player->dir.x >= 0)
	{
		if (map[(int)ceil(ray_info->x_pos_on_grid.y)]
			[(int)ray_info->x_pos_on_grid.x] == '1')
			return (true);
	}
	else
	{
		if (map[(int)ceil(ray_info->x_pos_on_grid.y)]
			[(int)ray_info->x_pos_on_grid.x - 1] == '1')
			return (true);
	}
	return (false);
}

bool	is_y_wall(char **map, t_player_info *player, t_raycasting *ray_info)
{
	if (player->dir.y >= 0)
	{
		if (map[(int)ray_info->y_pos_on_grid.y]
			[(int)floor(ray_info->y_pos_on_grid.x)] == '1')
			return (true);
	}
	else
	{
		if (map[(int)ray_info->y_pos_on_grid.y - 1]
			[(int)floor(ray_info->y_pos_on_grid.x)] == '1')
			return (true);
	}
	return (false);
}

void	walk_to_wall(char **map, t_player_info *player, t_raycasting *ray_info)
{
	while (1)
	{
		if (is_x_wall(map, player, ray_info))
			return ;
		ray_info->x_pos_on_grid.x += ray_info->x_step;
		ray_info->x_pos_on_grid.y += ray_info->x_tile_step;
	}
	while (1)
	{
		if (is_y_wall(map, player, ray_info))
			return ;
		ray_info->y_pos_on_grid.x += ray_info->y_tile_step;
		ray_info->y_pos_on_grid.y += ray_info->y_step;
	}
}

float	calc_distance_to_wall(t_player_info *player, t_vec wall_vec)
{
	float	angle;

	angle = atan(player->dir.y / player->dir.x);
	return ((wall_vec.x - player->pos.x) * cos(angle) + (wall_vec.y - player->pos.y) * sin(angle));
}

float	choose_distance_to_wall(t_player_info *player, t_raycasting *ray_info)
{
	if (ft_distance_vec(ray_info->x_pos_on_grid, player->pos) < ft_distance_vec(ray_info->y_pos_on_grid, player->pos))
		return (calc_distance_to_wall(player, ray_info->x_pos_on_grid));
	else
		return (calc_distance_to_wall(player, ray_info->y_pos_on_grid));
}

/**
 * @brief playerから壁までの距離を測る
 * 最初に一番近いグリッド線上の位置を見つける
 * その位置と次に近い位置から，差分(= digital difference)を計測
 * 一番近いグリッド線上から，差分を足していき，壁の位置を見つけ，playerの位置との差から,壁までの距離を求める
 * @param game 
 * @return float 
 */
float	measure_distance_to_wall(t_game *game, float theta)
{
	t_raycasting	ray_info;
	float			distance_to_wall;

	find_nearest_grid_on_line(&game->player, &ray_info, theta);
	calc_digital_difference(&ray_info, theta);
	calc_tile_step(&game->player, &ray_info);
	walk_to_wall(&game->map, &game->player, &ray_info);
	distance_to_wall = choose_distance_to_wall(&game->player, &ray_info);
	return (distance_to_wall);
}

float calculate_wall_height(float distance_to_wall)
{
	return (WALL_HEIGHT/distance_to_wall); //TODO:コンストの値を距離で割る
}

void	get_wall_height(t_game *game, float theta)
{
	float	distance_to_wall;

	distance_to_wall = measure_distance_to_wall(game, theta);
	game->player.wall_height = calculate_wall_height(distance_to_wall);
}
