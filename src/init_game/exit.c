/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:16:54 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 01:16:55 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define GREEN "\033[92m"
#define DEFAULT "\033[m"

/**
 * @brief ゲームの正常終了
 *
 * @param msg
 * @return int
 */
int	exit_game(char *msg)
{
	ft_putendl_fd(GREEN, 2);
	ft_putendl_fd(msg, 2);
	ft_putendl_fd(DEFAULT, 2);
	exit(0);
}

void	switch_display_minimap(t_game *game)
{
	if (game->is_minimap == true)
		game->is_minimap = false;
	else if (game->is_minimap == false)
		game->is_minimap = true;
	game->key_store &= ~SWITCH_MINIMAP;
}
