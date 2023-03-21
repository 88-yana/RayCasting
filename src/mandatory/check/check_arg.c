/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:27:32 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/21 20:00:30 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_arg(int argc, char **argv)
{
	char	*ptr;

	if (argc != 2)
	{
		handle_error(NULL, ERR_ARGS);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], ".cub") == 0)
	{
		handle_error(NULL, ERR_FILE_NAME);
		exit(EXIT_FAILURE);
	}
	ptr = ft_strrchr(argv[1], '.');
	if (ptr == NULL || ft_strcmp(ptr, ".cub") != 0)
	{
		handle_error(NULL, ERR_FILE_NAME);
		exit(EXIT_FAILURE);
	}
}

//error case
//.cub
//abc.???