/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:24:19 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/23 05:43:41 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_valid_key(char **key)
{
	size_t	i;

	i = 0;
	while (i < ELEMENT_SIZE)
	{
		if (ft_strcmp(key[i], "NO") == 0)
			;
		else if (ft_strcmp(key[i], "SO") == 0)
			;
		else if (ft_strcmp(key[i], "WE") == 0)
			;
		else if (ft_strcmp(key[i], "EA") == 0)
			;
		else if (ft_strcmp(key[i], "F") == 0)
			;
		else if (ft_strcmp(key[i], "C") == 0)
			;
		else
			return (false);
		i++;
	}
	return (true);
}

static bool	is_valid_value(char **key, char **value)
{
	size_t	i;
	int		fd;

	i = 0;
	while (i < ELEMENT_SIZE)
	{
		if (key_to_idx(key[i]) < 4)
		{
			fd = open(value[i], O_RDONLY);
			if (fd == -1)
				;// return (false);FIXME: コメントアウトを戻す
			else
				close(fd);
		}
		else
		{
			if (!is_valid_rgb(value[i]))
			{
				return (false);
			}
		}
		i++;
	}
	return (true);
}

bool	is_valid_dict(t_dictionary *dict)
{
	if (!is_valid_key(dict->key))
		return (false);
	if (!is_valid_value(dict->key, dict->value))
		return (false);
	return (true);
}

bool	is_valid_key_value_format(char ***info)
{
	if (ft_matrixlen(*info) != 2)
	{
		ft_free_matrix(info);
		return (false);
	}
	return (true);
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
