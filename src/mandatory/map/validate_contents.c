/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:35:57 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/23 04:21:48 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "map.h"

static char	**get_key_value(char *element)
{
	char	**key_value;

	key_value = ft_split(element, ' ');
	if (!is_valid_key_value_format(&key_value))
		handle_error(NULL, ERR_INPUT_FILE);
	return (key_value);
}

static void	get_dict(t_dictionary *dict, char **contents)
{
	size_t	i;
	char	**key_value;

	i = 0;
	while (i < ELEMENT_SIZE)
	{
		key_value = get_key_value(contents[i]);
		dict->key[i] = key_value[0];
		if (key_value[1][ft_strlen(key_value[1]) - 1] == '\n')
		key_value[1][ft_strlen(key_value[1]) - 1] = '\0';
		dict->value[i] = key_value[1];
		free(contents[i]);
		free(key_value);
		i++;
	}
	dict->key[i] = NULL;
	dict->value[i] = NULL;
}

static void	get_map(t_game *game, char **contents)
{
	size_t	i;

	i = ELEMENT_SIZE;
	while (contents[i])
	{
		if (contents[i][ft_strlen(contents[i]) - 1] == '\n')
			contents[i][ft_strlen(contents[i]) - 1] = '\0';
		game->map[i - ELEMENT_SIZE] = contents[i];
		i++;
	}
	game->map[i - ELEMENT_SIZE] = NULL;
}

static void	set_rgb(t_rgb *st, char **rgb)
{
	st->r = ft_atoi(rgb[0]);
	st->g = ft_atoi(rgb[1]);
	st->b = ft_atoi(rgb[2]);
}

/**
 * @brief rgb構造体に入れる
 * 
 * @param game 
 * @param key 
 * @param value 
 */
static void	get_rgb(t_game *game, char *key, char *value)
{
	char	**rgb;

	rgb = ft_split(value, ',');
	if (rgb == NULL)
		handle_error(NULL, ERR_MALLOC_FAILURE);
	if (ft_strcmp(key, "F") == 0)
		set_rgb(&game->map_info.floor, rgb);
	if (ft_strcmp(key, "C") == 0)
		set_rgb(&game->map_info.ceiling, rgb);
	ft_free_matrix(&rgb);
}

/**
 * @brief path_to_textureとrgbを取る
 * 
 * @param game 
 * @param dict 
 */
static void	get_map_info(t_game *game, t_dictionary *dict)
{
	size_t	i;

	i = 0;
	while (i < ELEMENT_SIZE)
	{
		if (key_to_idx(dict->key[i]) < 4)
			game->map_info.path_to_texture[key_to_idx(dict->key[i])] = dict->value[i];
		else
		{
			get_rgb(game, dict->key[i], dict->value[i]);
			free(dict->value[i]);
		}
		i++;
	}
}

/**
 * @brief ファイルの中身を構造体に入れる
 * 
 * @param game 
 * @param height 
 * @param contents 
 */
void	validate_file_contents(t_game *game, size_t height, char **contents)
{
	t_dictionary	dict;

	dict.key = ft_xmalloc(sizeof(char *) * (ELEMENT_SIZE + 1));
	dict.value = ft_xmalloc(sizeof(char *) * (ELEMENT_SIZE + 1));
	get_dict(&dict, contents);
	if (!is_valid_dict(&dict))
		handle_error(NULL, ERR_INPUT_FILE);
	get_map_info(game, &dict);
	game->map = ft_xmalloc(sizeof(char *) * (height - ELEMENT_SIZE + 1));
	get_map(game, contents);
	ft_free_matrix(&dict.key);
	free(dict.value);
}
