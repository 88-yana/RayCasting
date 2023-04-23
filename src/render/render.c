/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:25:22 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 13:36:04 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render(t_game *game)
{
	mlx_do_sync(game->mlx);
	draw_back(game);
	ray_casting(game);
	draw_rays_on_screen(game);
	if (game->is_minimap == true)
	{
		draw_minimap(game);
		draw_rays_on_minimap(game);
		draw_player_on_minimap(game);
	}
	mlx_put_image_to_window(&game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
