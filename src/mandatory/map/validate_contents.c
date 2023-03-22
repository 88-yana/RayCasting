/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:35:57 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/23 06:18:06 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "map.h"

static char	**get_key_value(char *element)
{
	char	**key_value;

	key_value = ft_split(element, ' ');
	free(element);
	if (ft_matrixlen(key_value) != 2)
		handle_error(ERR_INPUT_FILE);
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
		free(key_value);
		i++;
	}
	dict->key[i] = NULL;
	dict->value[i] = NULL;
	if (!is_valid_dict(dict))
		handle_error(ERR_INPUT_FILE);
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
	get_map_info(game, &dict);
	ft_free_matrix(&dict.key);
	free(dict.value);
	game->map = ft_xmalloc(sizeof(char *) * (height - ELEMENT_SIZE + 1));
	get_map(game, contents);
}
