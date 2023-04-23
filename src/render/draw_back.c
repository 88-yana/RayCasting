/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:21 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 01:17:22 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_in_window(int x, int y);

static void	draw_half(t_game *game, int offset, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw_pixel(&game->img, x, y + offset, color);
			x++;
		}
		y++;
	}
}

int	rgb_to_int(int r, int g, int b)
{
	int	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

void	draw_back(t_game *game)
{
	t_rgb	floor;
	t_rgb	ceil;

	floor = game->map_info.floor;
	ceil = game->map_info.ceiling;
	draw_half(game, 0, rgb_to_int(floor.r, floor.g, floor.b));
	draw_half(game, WIN_HEIGHT / 2, rgb_to_int(ceil.r, ceil.g, ceil.b));
}
