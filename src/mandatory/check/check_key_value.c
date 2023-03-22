/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:00:09 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/23 01:49:13 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_valid_key_value_format(char ***info)
{
	if (ft_matrixlen(*info) != 2)
	{
		ft_free_matrix(info);
		return (false);
	}
	return (true);
}

int	key_to_idx(char *key)
{
	if (ft_strcmp(key, "NO") == 0)
		return (NO);
	if (ft_strcmp(key, "SO") == 0)
		return (SO);
	if (ft_strcmp(key, "WE") == 0)
		return (WE);
	if (ft_strcmp(key, "EA") == 0)
		return (EA);
	if (ft_strcmp(key, "F") == 0)
		return (F);
	if (ft_strcmp(key, "C") == 0)
		return (C);
	return (-1);
}

bool	is_valid_rgb(char *value)
{
	char	**rgb;

	rgb = ft_split(value, ',');
	if (ft_matrixlen(rgb) != 3)
	{
		ft_free_matrix(&rgb);
		return (false);
	}
	if (!is_valid_number(rgb, 0))
	{
		ft_free_matrix(&rgb);
		return (false);
	}
	ft_free_matrix(&rgb);
	return (true);
}
