/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:00:09 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/21 23:44:12 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_valid_info_format(char **info)
{
	size_t	i;

	if (info == NULL)
		return (false);
	if (info[0] == NULL)
	{
		free(info);
		return (false);
	}
	if (info[1] == NULL)
	{
		free(info[0]);
		free(info);
		return (false);
	}
	if (info[2])
	{
		i = 0;
		while (info[i])
			free(info[i++]);
		free(info);
	}
	return (true);
}

//TODO:keyがNO,SO,WE,EAであるか
bool	is_valid_key(char **key)
{
	(void) key;
	return (true);
}
