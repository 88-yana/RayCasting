/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 06:14:08 by hyanagim          #+#    #+#             */
/*   Updated: 2023/04/23 15:08:27 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief debug用，取得したファイルの中身を表示
 * 		 mapの右端に2マス空白が入るのは，\nの分
 * @param game 
 */
#ifdef DEBUG
void	print_input(t_game *game)
{
	size_t	i;

	i = 0;
	ft_printf("--------------------map--------------------\n");
	while (game->map[i])
	{
		ft_printf("|%s|\n", game->map[i]);
		i++;
	}
	ft_printf("--------------------map--------------------\n");
	ft_printf("%s\n", game->map_info.path.north);
	ft_printf("%s\n", game->map_info.path.south);
	ft_printf("%s\n", game->map_info.path.west);
	ft_printf("%s\n", game->map_info.path.east);
	ft_printf("height : %u\n", game->map_info.height);
	ft_printf("width : %u\n", game->map_info.width);
	ft_printf("floor : ");
	ft_printf("%d ", game->map_info.floor.r);
	ft_printf("%d ", game->map_info.floor.g);
	ft_printf("%d\n", game->map_info.floor.b);
	ft_printf("ceiling : ");
	ft_printf("%d ", game->map_info.ceiling.r);
	ft_printf("%d ", game->map_info.ceiling.g);
	ft_printf("%d\n\n", game->map_info.ceiling.b);
}
#else

void	print_input(t_game *game)
{
	(void)game;
}
#endif