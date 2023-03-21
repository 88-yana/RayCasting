/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:36:53 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/21 20:00:10 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define RED "\033[31m"
#define DEFAULT "\033[m"

static void	put_error_message(char *err_msg)
{
	ft_putendl_fd(RED, 2);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
	ft_putendl_fd(DEFAULT, 2);
}

void	handle_error(t_game *game, char *message)
{
	put_error_message(message);
	if (game)
		// free_game_buffer(game);//TODO: implement
	exit(EXIT_FAILURE);
}
