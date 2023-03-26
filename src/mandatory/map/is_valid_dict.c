/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:24:19 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/26 16:29:28 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief keyが規定のうちのどれかに当てはまるかを調べる
 * 			TODO: refactor，globalな配列を使う
 * @param key 
 * @return true 
 * @return false 
 */
static bool	is_valid_key(char **key)
{
	size_t	i;

	i = 0;
	while (i < FILE_HEADER_SIZE)
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

// static const char *valid_keys[] = {"NO", "SO", "WE", "EA", "F", "C"};

// static bool is_valid_key(char **key)
// {
// 	for (size_t i = 0; i < ELEMENT_SIZE; i++) {
// 		bool is_valid = false;
// 		for (size_t j = 0; j < sizeof(valid_keys) / sizeof(valid_keys[0]); j++) {
// 			if (ft_strcmp(key[i], valid_keys[j]) == 0) {
// 				is_valid = true;
// 				break;
// 			}
// 		}
// 		if (!is_valid) {
// 			return false;
// 		}
// 	}
// 	return true;
// }

//どっちの方がいいか

/**
 * @brief 一回，rgbの数が正しいか，rgbの数値に収まっているかを調べる
 * 
 * @param value 
 */
static void	check_rgb(char *value)
{
	char	**rgb;

	rgb = ft_split(value, ',');
	if (ft_matrixlen(rgb) != 3)
		handle_error(ERR_INPUT_FILE);
	if (!is_valid_rgb_number(rgb, 0))
		handle_error(ERR_INPUT_FILE);
	ft_free_matrix(&rgb);
}

/**
 * @brief TODO:NO,SO,WEの配列を定義して，うまくやりたい
 * 
 * @param key 
 * @return int 
 */
static int	key_to_idx(char *key)
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

/**
 * @brief path_to_textureが利用可能なファイルかどうか，rgbのフォーマットがちゃんとしているかを調べる　
 * 			key_to_idxで変換したときに，NO,SOなどを意味するインデックスであれば，一度ファイルが開けるかを調べる
 * 			F,Cであれば，rgbのフォーマットをcheck
 * 			FIXME:refactorが必要
 * 
 * @param key 
 * @param value 
 * @return true 
 * @return false 
 */
static bool	is_valid_value(char **key, char **value)
{
	size_t	i;
	int		fd;

	i = 0;
	while (i < FILE_HEADER_SIZE)
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
			check_rgb(value[i]);
		i++;
	}
	return (true);
}

/**
 * @brief keyとvalueを調べるwrap関数
 * 
 * @param dict 
 * @return true 
 * @return false 
 */
bool	is_valid_dict(t_dictionary *dict)
{
	if (!is_valid_key(dict->key))
		return (false);
	if (!is_valid_value(dict->key, dict->value))
		return (false);
	return (true);
}
