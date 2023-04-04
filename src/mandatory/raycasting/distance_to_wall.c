#include "cub3D.h"

float	dir_to_angle(t_vec dir)
{
	if (dir.x > 0 && dir.y > 0)
		return (atan(dir.y / dir.x));
	if (dir.x < 0 && dir.y > 0)
		return (atan(-dir.x / dir.y) + M_PI_2);
	if (dir.x < 0 && dir.y < 0)
		return (atan(dir.y / dir.x) + M_PI);
	if (dir.x > 0 && dir.y < 0)
		return (atan(dir.x / -dir.y) + 3 * M_PI_2);
	if (dir.x == 0)
	{
		if (dir.y == 1)
			return (M_PI_2);
		else if (dir.y == -1)
			return (3 * M_PI_2);
	}
	if (dir.y == 0)
	{
		if (dir.x == 1)
			return (0);
		else if (dir.x == -1)
			return (M_PI);
	}
	return (0);
}

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

void	calc_dx_dy(t_player_info *player, t_raycasting *ray_info)
{
	if (ray_info->ray_dir.x > 0)
		ray_info->dx = ceil(player->pos.x) - player->pos.x;
	else if (ray_info->ray_dir.x < 0)
		ray_info->dx = floor(player->pos.x) - player->pos.x;
	else if (ray_info->ray_dir.x == 0)
		ray_info->dx = 0;
	if (ray_info->ray_dir.y > 0)
		ray_info->dy = floor(player->pos.y) - player->pos.y;
	else if (ray_info->ray_dir.y < 0)
		ray_info->dy = ceil(player->pos.y) - player->pos.y;
	else if (ray_info->ray_dir.y == 0)
		ray_info->dy = 0;
}

void	calc_tile_step(t_raycasting *ray_info)
{
	if (ray_info->ray_dir.x > 0)
		ray_info->x_tile_step = 1;
	else if (ray_info->ray_dir.x < 0)
		ray_info->x_tile_step = -1;
	else if (ray_info->ray_dir.x == 0)
		ray_info->x_tile_step = 0;
	if (ray_info->ray_dir.y > 0)
		ray_info->y_tile_step = -1;
	else if (ray_info->ray_dir.y < 0)
		ray_info->y_tile_step = 1;
	else if (ray_info->ray_dir.y == 0)
		ray_info->y_tile_step = 0;
}

void	find_nearest_grid_on_line(t_player_info *player, t_raycasting *ray_info, float theta)
{
	calc_dx_dy(player, ray_info);
	set_nearest_pos(player, ray_info, theta);
}

void	calc_digital_difference(t_raycasting *ray_info, float theta)
{
	if (ray_info->ray_dir.x > 0)
		ray_info->x_step_on_y_axis = - tan(theta);
	else if (ray_info->ray_dir.x < 0)
		ray_info->x_step_on_y_axis = tan(theta);
	else if (ray_info->ray_dir.x == 0)
		ray_info->x_step_on_y_axis = 0;
	if (ray_info->ray_dir.y > 0)
		ray_info->y_step_on_x_axis = 1 / tan(theta);
	else if (ray_info->ray_dir.y < 0)
		ray_info->y_step_on_x_axis = - 1 / tan(theta);
	else if (ray_info->ray_dir.y == 0)
		ray_info->y_step_on_x_axis = 0;

}

float	calc_distance_to_wall(t_player_info *player, t_vec wall_vec)
{
	float	angle;

	angle = dir_to_angle(player->dir);
	player->x_wall_on_minimap = (int) floor(10 * wall_vec.x);
	// player->y_wall_on_minimap = (int) ceil(10 * wall_vec.y) + 10;
	player->y_wall_on_minimap = (int) ceil(10 * wall_vec.y);
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
void	measure_distance_to_wall(t_game *game, t_raycasting *ray_info, float theta)
{
	find_nearest_grid_on_line(&game->player, ray_info, theta);
	calc_digital_difference(ray_info, theta);
	calc_tile_step(ray_info);
	walk_to_wall(game, &game->player, ray_info);
}

float calculate_wall_height(float distance_to_wall)
{
	return (WALL_HEIGHT/distance_to_wall); //TODO:0で割るのを除外
}

void	get_wall_height(t_game *game, t_vec ray_dir, float theta)
{
	float			distance_to_wall;
	t_raycasting	ray_info;

	ray_info.ray_dir = ray_dir;
	measure_distance_to_wall(game, &ray_info, theta);
	distance_to_wall = choose_distance_to_wall(&game->player, &ray_info);
	// game->player.wall_height = calculate_wall_height(distance_to_wall);
}

void	draw_ray_on_near_grid(t_game *game)
{
	get_wall_height(game, game->player.dir, dir_to_angle(game->player.dir));
	if (!is_out_of_map_width(game, game->player.near_x / 10) && !is_out_of_map_height(game, game->player.near_y / 10))
		my_mlx_pixel_put(&game->img, game->player.near_x, game->player.near_y, COLOR_RED);
}


bool	rotate_right_angle(t_vec *right_dir, float *right_angle)
{
	float	temp;

	*right_dir = ft_rotate_vec(*right_dir, ft_deg_to_rad(1));
	temp = *right_angle;
	*right_angle = dir_to_angle(*right_dir);
	if (temp > *right_angle)
		return (false);
	return (true);
}

void	emit_rays(t_game *game, t_vec *right_dir, float left_angle, float right_angle)
{
	while (left_angle > right_angle)
	{
		get_wall_height(game, *right_dir, right_angle);
		draw_wall_intersection(game);
		if (!rotate_right_angle(right_dir, &right_angle))
			break ;
	}
}

void	ray_casting(t_game *game)
{
	float	right_angle;
	float	left_angle;
	t_vec	right_dir;
	t_vec	left_dir;

	right_dir = ft_rotate_vec(game->player.dir, ft_deg_to_rad(-VIEWING_ANGLE));
	left_dir = ft_rotate_vec(game->player.dir, ft_deg_to_rad(VIEWING_ANGLE));
	right_angle = dir_to_angle(right_dir);
	left_angle = dir_to_angle(left_dir);
	draw_ray_on_near_grid(game);
	if (left_angle > right_angle)
		emit_rays(game, &right_dir, left_angle, right_angle);
	else
	{
		emit_rays(game, &right_dir, 2 * M_PI, right_angle);
		emit_rays(game, &right_dir, left_angle, 0);
	}
}
