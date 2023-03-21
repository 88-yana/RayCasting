/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:35:57 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/22 03:33:34 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**get_info(char	*elem, char ***key, char ***value, char ***contents)
{
	char	**info;

	info = ft_split(elem, ' ');
	if (!is_valid_info_format(info))
	{
		(void) key;
		(void) value;
		(void) contents;
		free_elements(contents, key, value);
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

void	validate_file_contents(t_game *game, size_t height, char ***contents)
{
	char	**key;
	char	**value;

	key = malloc(sizeof(char *) * (ELEMENT_SIZE + 1));
	value = malloc(sizeof(char *) * (ELEMENT_SIZE + 1));
	if (key == NULL || value == NULL)
	{
		free_elements(contents, &key, &value);
		handle_error(NULL, ERR_MALLOC_FAILURE);
	}
	get_key_value(&key, &value, contents);
	is_valid_key(key);
	game->map = malloc(sizeof(char *) * (height - ELEMENT_SIZE + 1));
	if (game->map == NULL)
	{
		free_elements(contents, &key, &value);
		handle_error(NULL, ERR_MALLOC_FAILURE);
	}
	get_map(game, *contents);

	system("leaks -q cub3D");
	// size_t i = 0;
	// while (game->map[i] != NULL)
	// {
	// 	printf("%s\n", game->map[i]);
	// 	i++;
	// }
}
