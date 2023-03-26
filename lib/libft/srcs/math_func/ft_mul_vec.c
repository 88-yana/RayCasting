/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_mul.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:20:21 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 15:20:21 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_mul_vec(t_vec v1, float t)
{
	t_vec	ret;

	ret.x = (float)v1.x * t;
	ret.y = (float)v1.y * t;
	return (ret);
}
