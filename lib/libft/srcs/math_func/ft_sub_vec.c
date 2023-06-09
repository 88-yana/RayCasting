/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:20:55 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/09 15:20:55 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	ft_sub_vec(t_vec v1, t_vec v2)
{
	t_vec	ret;

	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	return (ret);
}
