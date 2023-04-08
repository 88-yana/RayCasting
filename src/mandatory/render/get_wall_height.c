#include "cub3D.h"

void	set_nearest_pos(t_player_info *player, t_raycasting *ray_info, float theta)
{
	ray_info->x_pos_on_grid.x = player->pos.x + ray_info->dx;
	if (ray_info->dx != 0)
		ray_info->x_pos_on_grid.y = player->pos.y - ray_info->dx * tan(theta);
	else
		ray_info->x_pos_on_grid.y = player->pos.y;
	if (tan(theta) != 0)
		ray_info->y_pos_on_grid.x = player->pos.x - ray_info->dy / tan(theta);
	else
		ray_info->y_pos_on_grid.x = player->pos.x - INF;
	ray_info->y_pos_on_grid.y = player->pos.y + ray_info->dy;

	if (ft_distance_vec(ray_info->x_pos_on_grid, player->pos) < ft_distance_vec(ray_info->y_pos_on_grid, player->pos))
	{
		player->near_x = 10 * ray_info->x_pos_on_grid.x;
		player->near_y = 10 * ray_info->x_pos_on_grid.y;
	}
	else
	{
		player->near_x = 10 * ray_info->y_pos_on_grid.x;
		player->near_y = 10 * ray_info->y_pos_on_grid.y;
	}
}

float	choose_distance_to_wall(t_player_info *player, t_raycasting *ray_info)
{
	if (ft_distance_vec(ray_info->x_pos_on_grid, player->pos)
		< ft_distance_vec(ray_info->y_pos_on_grid, player->pos))
	{
		if (ray_info->ray_dir.x > 0)
			player->news = EAST;
		else
			player->news = WEST;
		return (calc_distance_to_wall(player, ray_info, ray_info->x_pos_on_grid));
	}
	else
	{
		if (ray_info->ray_dir.y < 0)
			player->news = NORTH;
		else
			player->news = SOUTH;
		return (calc_distance_to_wall(player, ray_info, ray_info->y_pos_on_grid));
	}
}

void	find_nearest_grid_on_line(t_player_info *player, t_raycasting *ray_info, float theta)
{
	calc_dx_dy(player, ray_info);
	set_nearest_pos(player, ray_info, theta);
}

/**
 * @brief playerから壁までの距離を測る
 * 最初に一番近いグリッド線上の位置を見つける
 * その位置と次に近い位置から，差分(= digital difference)を計測
 * 一番近いグリッド線上から，差分を足していき，壁の位置を見つけ，playerの位置との差から,壁までの距離を求める
 * @param game
 * @return float
 */
void	measure_distance_to_wall(t_game *game, t_raycasting *ray_info, float theta)
{
	find_nearest_grid_on_line(&game->player, ray_info, theta);
	calc_digital_difference(ray_info, theta);
	calc_tile_step(ray_info);
	walk_to_wall(game, ray_info);
}

void	get_wall_height(t_game *game, t_vec ray_dir, float theta)
{
	float			distance_to_wall;
	t_raycasting	ray_info;

	ray_info.ray_dir = ray_dir;
	measure_distance_to_wall(game, &ray_info, theta);
	distance_to_wall = choose_distance_to_wall(&game->player, &ray_info);
	game->player.wall_height = calculate_wall_height(distance_to_wall);
}
