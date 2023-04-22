/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:35:57 by hyanagim          #+#    #+#             */
/*   Updated: 2023/04/23 01:17:17 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief elementをkeyとvalueに分ける
 * 			keyとvalueの2つなかったら，エラー
 * 			最後が改行だったら，null文字に
 * @param element
 * @return char**
 */
static char	**parse_line(char *element)
{
	char	**parsed_line;

	parsed_line = ft_split(element, ' ');
	if (ft_matrixlen(parsed_line) != 2)
		handle_error(ERR_INPUT_FILE);
	if (parsed_line[1][ft_strlen(parsed_line[1]) - 1] == '\n')
		parsed_line[1][ft_strlen(parsed_line[1]) - 1] = '\0';
	return (parsed_line);
}

/**
 * @brief 取得したkeyとvalueを構造体に代入
 *
 * @param dict
 * @param contents
 */
static void	parse_header_lines(t_dictionary *dict, char **contents)
{
	size_t	i;
	char	**parsed_line;

	dict->key = ft_xmalloc(sizeof(char *) * (FILE_HEADER_SIZE + 1));
	dict->value = ft_xmalloc(sizeof(char *) * (FILE_HEADER_SIZE + 1));
	i = 0;
	while (i < FILE_HEADER_SIZE)
	{
		parsed_line = parse_line(contents[i]);
		dict->key[i] = parsed_line[0];
		dict->value[i] = parsed_line[1];
		free(parsed_line);
		i++;
	}
	dict->key[i] = NULL;
	dict->value[i] = NULL;
	if (!is_valid_map_info(dict))
		handle_error(ERR_INPUT_FILE);
}

/**
 * @brief ファイルの中身を構造体に入れる
 *
 * @param game
 * @param height
 * @param contents
 */
void	get_map_info(t_game *game, char **contents)
{
	t_dictionary	dict;

	parse_header_lines(&dict, contents);
	set_map_info(game, &dict);
}
