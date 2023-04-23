/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:16:40 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 13:38:30 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fetch_mouse_position(t_game *game)
{
	t_vec	*dir;

	dir = &game->player.dir;
	if (game->mouse_pos_x < WIN_WIDTH / 2 * 0.8)
		*dir = ft_rotate_vec(*dir, ft_deg_to_rad(1));
	if (game->mouse_pos_x > -WIN_WIDTH / 2 * 0.8)
		*dir = ft_rotate_vec(*dir, ft_deg_to_rad(-1));
}
