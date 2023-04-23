/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_lerp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:19:20 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 15:19:20 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_lerp_vec(t_vec v1, t_vec v2, float t)
{
	t_vec	ret;

	ret.x = (1.0f - t) * (float)v1.x + t * (float)v2.x;
	ret.y = (1.0f - t) * (float)v1.y + t * (float)v2.y;
	return (ret);
}
