/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:00 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 01:17:01 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calc_dx_dy(t_player_info *player, t_ray *ray_info)
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

void	calc_tile_step(t_ray *ray_info)
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

void	calc_digital_difference(t_ray *ray_info, float theta)
{
	if (ray_info->ray_dir.x > 0)
		ray_info->x_step_on_y_axis = -tan(theta);
	else if (ray_info->ray_dir.x < 0)
		ray_info->x_step_on_y_axis = tan(theta);
	else if (ray_info->ray_dir.x == 0)
		ray_info->x_step_on_y_axis = 0;
	if (ray_info->ray_dir.y > 0)
		ray_info->y_step_on_x_axis = 1 / tan(theta);
	else if (ray_info->ray_dir.y < 0)
		ray_info->y_step_on_x_axis = -1 / tan(theta);
	else if (ray_info->ray_dir.y == 0)
		ray_info->y_step_on_x_axis = 0;
}

float	calc_distance_to_wall(
		t_player_info *player, t_ray *ray_info, t_vec wall_vec)
{
	float	player_angle;
	float	ray_angle;
	float	angle_difference;

	player->x_wall = wall_vec.x;
	player->y_wall = wall_vec.y;
	player_angle = dir_to_angle(player->dir);
	ray_angle = dir_to_angle(ray_info->ray_dir);
	angle_difference = fabs(ray_angle - player_angle);
	return (ft_distance_vec(wall_vec, player->pos) * cos(angle_difference));
}

float	calc_wall_height(float distance_to_wall)
{
	if (distance_to_wall == 0)
		return (WALL_HEIGHT * 2);
	return (WALL_HEIGHT / distance_to_wall);
}
