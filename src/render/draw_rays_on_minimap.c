/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays_on_minimap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:28 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 12:59:28 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_ray_on_minimap(t_game *game, int i)
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;

	x = floor(10 * game->draw.x_wall[i]);
	y = floor(10 * game->draw.y_wall[i]);
	player_x = game->player.pos.x * TIP_SIZE;
	player_y = game->player.pos.y * TIP_SIZE;
	if (!is_out_of_map_width(game, game->draw.x_wall[i])
		&& !is_out_of_map_height(game, game->draw.y_wall[i]))
	{
		draw_pixel(&game->img, x, y, COLOR_GREEN);
		draw_line(game, (t_vec){player_x, player_y},
			(t_vec){x, y}, COLOR_YELLOW);
	}
}

void	draw_rays_on_minimap(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		draw_ray_on_minimap(game, x);
		x++;
	}
}
