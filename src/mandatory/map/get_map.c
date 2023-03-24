/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 02:17:18 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/24 10:34:08 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief mapの最大の横幅を取る
 * 
 * @param map_info 
 * @param contents 
 */
static void	get_map_width(t_map_info *map_info, char **contents)
{
	size_t	i;

	i = ELEMENT_SIZE;
	map_info->width = 0;
	while (contents[i])
	{
		map_info->width = ft_max_s(map_info->width, ft_strlen(contents[i]));
		i++;
	}
}

/**
 * @brief mapの高さ+スペースの2行+NULL分のchar * をmallocする。　
 * mapの高さ+スペースの2行に　行を代入できるように，map+スペースの2列+NULL文字のcharをmallocをする。
 * 
 * @param game
 */
static void	malloc_map(t_game *game)
{
	size_t	i;

	game->map = ft_xmalloc(sizeof(char *) * (game->map_info.height + SP + 1));
	i = 0;
	while (i < game->map_info.height + SP)
	{
		game->map[i]
			= ft_xmalloc(sizeof(char) * (game->map_info.width + SP + 1));
		i++;
	}
}

/**
 * @brief mapを一度スペースで埋める。
 * +1のところに，null文字，NULLを代入する。
 * @param game 
 */
static void	fill_map_with_spaces(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->map_info.height + SP)
	{
		j = 0;
		while (j < game->map_info.width + SP)
		{
			game->map[i][j] = ' ';
			j++;
		}
		game->map[i][j] = '\0';
		i++;
	}
	game->map[i] = NULL;
}

/**
 * @brief 改行でなければ，mapの中身を代入する。
 * そのため，右の2マスは必ずスペース2つが入る。
 * @param game 
 * @param contents 
 */
static void	set_map(t_game *game, char **contents)
{
	size_t	i;
	size_t	j;

	i = ELEMENT_SIZE;
	while (contents[i])
	{
		j = 0;
		while (contents[i][j])
		{
			if (contents[i][j] != '\n')
				game->map[i - ELEMENT_SIZE + 1][j + 1] = contents[i][j];
			j++;
		}
		i++;
	}
}

/**
 * @brief map構造体に中身を代入する。
 * 横幅を取る。
 * mallocする。
 * スペースで埋める。
 * 中身を入れる。
 * @param game 
 * @param contents 
 */
void	get_map(t_game *game, char **contents)
{
	get_map_width(&game->map_info, contents);
	malloc_map(game);
	fill_map_with_spaces(game);
	set_map(game, contents);
	if (!is_valid_map(game))
		handle_error(ERR_MAP);
}
