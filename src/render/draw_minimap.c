/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:24 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 13:16:28 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_rectangle(t_image *img, t_vec *p, int size, int color)
{
	size_t	i;
	size_t	j;

	i = p->y;
	while (i < p->y + size)
	{
		j = p->x;
		while (j < p->x + size)
		{
			draw_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->map_info.height + 2)
	{
		j = 0;
		while (j < game->map_info.width + 2)
		{
			if (game->map[i][j] == '1')
				draw_rectangle(&game->img, &(t_vec){i * TIP_SIZE, j * TIP_SIZE},
					TIP_SIZE, COLOR_LGRAY);
			if (game->map[i][j] == '0' || is_start_position(game->map[i][j]))
				draw_rectangle(&game->img, &(t_vec){i * TIP_SIZE, j * TIP_SIZE},
					TIP_SIZE, COLOR_GRAY);
			j++;
		}
		i++;
	}
}
