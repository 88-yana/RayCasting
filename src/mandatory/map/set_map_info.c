/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:43:22 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/26 15:20:37 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief rgbを構造体に入れる。rgbはひとつ上の構造体でfreeされる
 * 
 * @param st 
 * @param rgb 
 */
static void	set_rgb(t_rgb *st, char **rgb)
{
	st->r = ft_atoi(rgb[0]);
	st->g = ft_atoi(rgb[1]);
	st->b = ft_atoi(rgb[2]);
}

/**
 * @brief rgb構造体に入れる.この時点で，rgbは正しいformatであることが保証されている
 * 
 * @param game 
 * @param key 
 * @param value 
 */
static void	get_rgb(t_game *game, char *key, char *value)
{
	char	**rgb;

	rgb = ft_split(value, ',');
	free(value);
	if (rgb == NULL)
		handle_error(ERR_MALLOC_FAILURE);
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
void	set_map_info(t_game *game, t_dictionary *dict)
{
	size_t	i;

	i = 0;
	while (i < FILE_HEADER_SIZE)
	{
		if (ft_strcmp(dict->key[i], "NO") == 0)
			game->map_info.path.north = dict->value[i];
		else if (ft_strcmp(dict->key[i], "SO") == 0)
			game->map_info.path.south = dict->value[i];
		else if (ft_strcmp(dict->key[i], "WE") == 0)
			game->map_info.path.west = dict->value[i];
		else if (ft_strcmp(dict->key[i], "EA") == 0)
			game->map_info.path.east = dict->value[i];
		else
			get_rgb(game, dict->key[i], dict->value[i]);
		i++;
	}
	ft_free_matrix(&dict->key);
	free(dict->value);
}
