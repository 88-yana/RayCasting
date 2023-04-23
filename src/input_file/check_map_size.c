/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:17:12 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 01:17:13 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_size(t_game *game)
{
	if (game->map_info.height > 50 || game->map_info.width > 50)
		handle_error(ERR_MAP_SIZE);
}
