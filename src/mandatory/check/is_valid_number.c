/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 04:30:34 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/22 05:23:58 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_number(char *str)
{
	size_t	i;

	if (str == NULL)
		return (false);
	i = 0;
	if (str[i] == '+')
		i++;
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_int(char *str)
{
	int	ans;
	int	sign;

	if (str == NULL)
		return (false);
	ans = 0;
	sign = -1;
	if (*str == '+')
		sign = *str++ - 44;
	while (ft_isdigit(*str))
	{
		if (sign * ans > (255 - (int)(*str - '0')) / 10)
			return (false);
		ans = ans * 10 - (int)(*str++ - '0');
	}
	return (true);
}

bool	is_valid_number(char **array, int i)
{
	while (array[i])
	{
		if (is_number(array[i]) == false)
			return (false);
		if (is_int(array[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
