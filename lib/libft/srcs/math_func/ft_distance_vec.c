/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_vec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:56:20 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/26 16:04:58 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math.h"

float	ft_distance_vec(t_vec v1, t_vec v2)
{
	float	x;
	float	y;
	float	distance;

	x = v1.x - v2.x;
	y = v1.y - v2.y;
	distance = sqrt(x * x + y * y);
	return (distance);
}
