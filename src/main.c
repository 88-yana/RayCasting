/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:30:01 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/22 06:17:18 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_arg(argc, argv);
	input_file(&game, argv[1]);

	system("leaks -q cub3D");
	return (0);
}

	// free(game.map_info.path_to_texture[0]);
	// free(game.map_info.path_to_texture[1]);
	// free(game.map_info.path_to_texture[2]);
	// free(game.map_info.path_to_texture[3]);
	// ft_free_matrix(&game.map);