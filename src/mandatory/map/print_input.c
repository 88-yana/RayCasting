/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 06:14:08 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/22 06:18:13 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_input(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		printf("%s\n", game->map_info.path_to_texture[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("%d\n", game->map_info.floor[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("%d\n", game->map_info.ceiling[i]);
		i++;
	}
}
