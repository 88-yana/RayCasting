/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:23 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 14:09:13 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	t_vec	switch_absolute(t_vec v0, t_vec v1)
{
	t_vec	d;

	d.x = ft_abs(v1.x - v0.x);
	d.y = -ft_abs(v1.y - v0.y);
	return (d);
}

static t_vec	switch_quadrant(t_vec v0, t_vec v1)
{
	t_vec	s;

	if (v0.x < v1.x)
		s.x = 1;
	else
		s.x = -1;
	if (v0.y < v1.y)
		s.y = 1;
	else
		s.y = -1;
	return (s);
}

/**
 * @brief 二点間を結ぶ直線を描画する（Bresenham's Algorithm）
 *
 * @param game
 * @param v1
 * @param v2
 * @param color
 */
void	draw_line(t_game *game, t_vec v0, t_vec v1, int color)
{
	t_vec	d;
	t_vec	s;
	int		err;
	int		e2;

	d = switch_absolute(v0, v1);
	s = switch_quadrant(v0, v1);
	err = d.x + d.y;
	while (true)
	{
		draw_pixel(&game->img, v0.x, v0.y, color);
		if (v0.x == v1.x && v0.y == v1.y)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
		{
			err += d.y;
			v0.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			v0.y += s.y;
		}
	}
}
