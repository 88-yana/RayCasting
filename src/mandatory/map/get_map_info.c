/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:43:22 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/23 05:42:07 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	free(value);
	if (rgb == NULL)
		handle_error(ERR_MALLOC_FAILURE);
	if (ft_strcmp(key, "F") == 0)
		set_rgb(&game->map_info.floor, rgb);
	if (ft_strcmp(key, "C") == 0)
		set_rgb(&game->map_info.ceiling, rgb);
	ft_free_matrix(&rgb);
}

int	key_to_idx(char *key)
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
 * @brief path_to_textureとrgbを取る
 * 
 * @param game 
 * @param dict 
 */
void	get_map_info(t_game *game, t_dictionary *dict)
{
	size_t	i;

	i = 0;
	while (i < ELEMENT_SIZE)
	{
		if (key_to_idx(dict->key[i]) < 4)
			game->map_info.path_to_texture[key_to_idx(dict->key[i])]
				= dict->value[i];
		else
			get_rgb(game, dict->key[i], dict->value[i]);
		i++;
	}
}
