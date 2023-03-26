/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_to_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:16:17 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/26 11:36:43 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_ray {
	t_vec x;
	t_vec y;
}	t_ray;

void	find_nearest_grid_lines(t_ray *nearest_grid, t_vec position, t_vec direction)
{
	nearest_grid->x = find_nearest_grid_x(position, direction);
	nearest_grid->y = find_nearest_grid_y(position, direction);
}

/**
 * @brief 壁との距離を返す関数
 * 
 * @param position 
 * @return float 
 */
float	distance_to_wall(t_vec position, t_vec, direction)
{
	t_ray	nearest_grid;
	t_ray	next_grid;

	find_nearest_grid_lines(&nearest_grid, position, direction);
	find_nearest_grid_lines(&next_grid, position, direction);
	next_grid = nearest_grid(position, direction);
	distance_between_grids(nearest_grid, direction);
	calc_distance_to_wall(position, direction);
}

// t_ray nearest_grid_line;
// t_ray next_grid_line;

// next_grid_line.x - nearest_grid_line.x;