/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:30:01 by hyanagim          #+#    #+#             */
/*   Updated: 2023/04/23 13:57:13 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_input(t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;

	check_arg(argc, argv);
	input_file(&game, argv[1]);
	print_input(&game);
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
