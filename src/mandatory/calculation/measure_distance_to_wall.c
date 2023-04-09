#include "cub3D.h"

static void	set_nearest_pos(t_player_info *player, t_ray *ray_info, float theta)
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
}

static void	find_nearest_grid_on_line(t_player_info *player, t_ray *ray_info, float theta)
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
void	measure_distance_to_wall(t_game *game, t_ray *ray_info, float theta)
{
	find_nearest_grid_on_line(&game->player, ray_info, theta);
	calc_digital_difference(ray_info, theta);
	calc_tile_step(ray_info);
	walk_to_wall(game, ray_info);
}
