/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:11:30 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/22 05:10:21 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	free_char_array(char **array)
// {
// 	size_t	i;

// 	i = 0;
// 	while (array[i] != NULL)
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// }

void	free_elements(char ***key, char ***value, char ***contents)
{
	ft_free_matrix(key);
	ft_free_matrix(value);
	ft_free_matrix(contents);
}
