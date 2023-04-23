/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:07 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 01:17:08 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	rotate_right_angle(t_vec *right_dir, float *right_angle)
{
	float	temp;
	float	diff_rad;

	diff_rad = ft_deg_to_rad(2 * VIEWING_ANGLE) / WIN_WIDTH;
	*right_dir = ft_rotate_vec(*right_dir, diff_rad);
	temp = *right_angle;
	*right_angle = dir_to_angle(*right_dir);
	if (temp > *right_angle)
		return (false);
	return (true);
}

void	set_info_to_draw(t_game *game, int x)
{
	game->draw.x_wall[x] = game->player.x_wall;
	game->draw.y_wall[x] = game->player.y_wall;
	game->draw.wall_height[x] = game->player.wall_height;
	game->draw.distance_to_wall[x] = game->player.distance_to_wall;
	game->draw.news[x] = game->player.news;
}

void	emit_rays(
		t_game *game, t_vec *right_dir, float left_angle, float right_angle)
{
	static int	x_axis = WIN_WIDTH - 1;

	if (x_axis < 0)
		x_axis = WIN_WIDTH - 1;
	while (left_angle > right_angle && x_axis >= 0)
	{
		get_wall_height(game, *right_dir, right_angle);
		set_info_to_draw(game, x_axis);
		if (!rotate_right_angle(right_dir, &right_angle))
			break ;
		x_axis--;
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
	if (left_angle > right_angle)
		emit_rays(game, &right_dir, left_angle, right_angle);
	else
	{
		emit_rays(game, &right_dir, 2 * M_PI, right_angle);
		emit_rays(game, &right_dir, left_angle, 0);
	}
}
