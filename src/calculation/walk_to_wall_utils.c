/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_to_wall_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:10 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 01:17:11 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	set_inf(float *x, float *y)
{
	*x = INF;
	*y = INF;
	return (true);
}

bool	except_x_error(t_game *game, t_ray *ray_info)
{
	float	*x;
	float	*y;

	x = &ray_info->x_pos_on_grid.x;
	y = &ray_info->x_pos_on_grid.y;
	if (is_out_of_map_height(game, *y))
		return (set_inf(x, y));
	if (ray_info->ray_dir.x > 0 && is_out_of_map_width(game, *x))
		return (set_inf(x, y));
	if (ray_info->ray_dir.x < 0 && is_out_of_map_width(game, *x - 1))
		return (set_inf(x, y));
	if (ray_info->ray_dir.x == 0)
		return (set_inf(x, y));
	return (false);
}

bool	except_y_error(t_game *game, t_ray *ray_info)
{
	float	*x;
	float	*y;

	x = &ray_info->y_pos_on_grid.x;
	y = &ray_info->y_pos_on_grid.y;
	if (ray_info->ray_dir.y > 0 && is_out_of_map_height(game, *y - 1))
		return (set_inf(x, y));
	if (ray_info->ray_dir.y < 0 && is_out_of_map_height(game, *y))
		return (set_inf(x, y));
	if (is_out_of_map_width(game, *x))
		return (set_inf(x, y));
	if (ray_info->ray_dir.y == 0)
		return (set_inf(x, y));
	return (false);
}
