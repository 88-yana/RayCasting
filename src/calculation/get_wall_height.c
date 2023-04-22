/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:03 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 01:17:04 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_news(t_player_info *player, float dir, char flag)
{
	if (flag == 'x')
	{
		if (dir > 0)
			player->news = EAST;
		else
			player->news = WEST;
	}
	if (flag == 'y')
	{
		if (dir < 0)
			player->news = SOUTH;
		else
			player->news = NORTH;
	}
}

static float	choose_distance_to_wall(t_player_info *player, t_ray *ray_info)
{
	if (ft_distance_vec(ray_info->x_pos_on_grid, player->pos)
		< ft_distance_vec(ray_info->y_pos_on_grid, player->pos))
	{
		set_news(player, ray_info->ray_dir.x, 'x');
		return (
			calc_distance_to_wall(player, ray_info, ray_info->x_pos_on_grid));
	}
	else
	{
		set_news(player, ray_info->ray_dir.y, 'y');
		return (
			calc_distance_to_wall(player, ray_info, ray_info->y_pos_on_grid));
	}
}

void	get_wall_height(t_game *game, t_vec ray_dir, float theta)
{
	t_ray	ray_info;

	ray_info.ray_dir = ray_dir;
	measure_distance_to_wall(game, &ray_info, theta);
	game->player.distance_to_wall = choose_distance_to_wall(
			&game->player, &ray_info);
	game->player.wall_height = calc_wall_height(game->player.distance_to_wall);
}
