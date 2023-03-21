/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:35:57 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/22 06:25:20 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_input(t_game *game);

static char	**get_info(char	*elem, char ***key, char ***value, char ***contents)
{
	char	**info;

	info = ft_split(elem, ' ');
	if (!is_valid_info_format(&info))
	{
		free_elements(key, value, contents);
		handle_error(NULL, ERR_INPUT_FILE);
	}
	return (info);
}

static void	get_key_value(char ***key, char ***value, char ***contents)
{
	size_t	i;
	char	**info;

	i = 0;
	while (i < ELEMENT_SIZE)
	{
		info = get_info((*contents)[i], key, value, contents);
		(*key)[i] = info[0];
		info[1][ft_strlen(info[1]) - 1] = '\0';
		(*value)[i] = info[1];
		free(info);
		i++;
	}
	(*key)[i] = NULL;
	(*value)[i] = NULL;
}

static void	get_map(t_game *game, char **contents)
{
	size_t	i;

	i = ELEMENT_SIZE;
	while (contents[i])
	{
		game->map[i - ELEMENT_SIZE] = contents[i];
		i++;
	}
	game->map[i - ELEMENT_SIZE] = NULL;
}

static bool	get_rgb(t_game *game, char *key, char *value)
{
	char	**rgb;
	size_t	i;

	rgb = ft_split(value, ',');
	if (rgb == NULL)
		return (false);
	if (ft_strcmp(key, "F") == 0)
	{
		i = 0;
		while (i < ft_matrixlen(rgb))
		{
			game->map_info.floor[i] = ft_atoi(rgb[i]);
			i++;
		}
	}
	if (ft_strcmp(key, "C") == 0)
	{
		i = 0;
		while (i < ft_matrixlen(rgb))
		{
			game->map_info.ceiling[i] = ft_atoi(rgb[i]);
			i++;
		}
	}
	ft_free_matrix(&rgb);
	return (true);
}

static void	get_map_info(t_game *game, char ***key, char ***value, char ***contents)
{
	size_t	i;

	i = 0;
	while (i < ELEMENT_SIZE)
	{
		if (key_to_idx((*key)[i]) < 4)
			game->map_info.path_to_texture[key_to_idx((*key)[i])] = (*value)[i];
		else
		{
			if (!get_rgb(game, (*key)[i], (*value)[i]))
			{
				free_elements(key, value, contents);
				handle_error(NULL, ERR_MALLOC_FAILURE);
			}
			free((*value)[i]);
		}
		i++;
	}
}

void	validate_file_contents(t_game *game, size_t height, char ***contents)
{
	char	**key;
	char	**value;
	size_t	i;

	key = malloc(sizeof(char *) * (ELEMENT_SIZE + 1));
	value = malloc(sizeof(char *) * (ELEMENT_SIZE + 1));
	if (key == NULL || value == NULL)
	{
		free(key);
		free(value);
		ft_free_matrix(contents);
		handle_error(NULL, ERR_MALLOC_FAILURE);
	}
	i = 0;
	while (i < ELEMENT_SIZE + 1)
	{
		key[i] = NULL;
		value[i] = NULL;
		i++;
	}
	get_key_value(&key, &value, contents);
	if (!is_valid_key(key) || !is_valid_value(key, value))
	{
		free_elements(&key, &value, contents);
		handle_error(NULL, ERR_INPUT_FILE);
	}
	get_map_info(game, &key, &value, contents);
	game->map = malloc(sizeof(char *) * (height - ELEMENT_SIZE + 1));
	if (game->map == NULL)
	{
		free_elements(&key, &value, contents);
		handle_error(NULL, ERR_MALLOC_FAILURE);
	}
	get_map(game, *contents);
	ft_free_matrix(&key);
	free(value);
	print_input(game);
}
