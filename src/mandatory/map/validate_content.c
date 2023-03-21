/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:35:57 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/21 23:52:56 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**get_info(char *element, char **contents, char **key, char **value)
{
	char	**info;

	info = ft_split(element, ' ');
	if (!is_valid_info_format(info))
	{
		free_elements(contents, key, value);
		handle_error(NULL, ERR_INPUT_FILE);
	}
	return (info);
}

static void	get_key_value(char **key[ELEMENT_SIZE], char **value[ELEMENT_SIZE], char **contents)
{
	size_t	i;
	char	**info;

	i = 0;
	while (i < ELEMENT_SIZE)
	{
		info = get_info(contents[i], contents, *key, *value);
		*key[i] = info[0];
		*value[i] = info[1];
		free(info);
		i++;
	}
	*key[i] = NULL;
	*value[i] = NULL;
}

static char	**get_map(t_game *game, char **contents)
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

void	validate_file_contents(t_game *game, char **contents, size_t height)
{
	size_t	i;
	size_t	line_after_elements;
	char	**key;
	char	**value;
	//TODO: char **にする
	key 
	get_key_value(&key, &value, contents);
	is_valid_key(key, value);
	game->map = malloc(sizeof(char *) * (height - ELEMENT_SIZE + 1));
	if (game->map == NULL)
		free_elements(contents, key, value);
	get_map(game, contents);
}
