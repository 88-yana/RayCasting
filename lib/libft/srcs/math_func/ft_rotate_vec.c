/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:23:27 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/24 11:29:33 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math.h"

t_vec	ft_rotate_vec(t_vec v, float rad)
{
	t_vec	ret;

	ret.x = cos(rad) * v.x - sin(rad) * v.y;
	ret.y = sin(rad) * v.x + cos(rad) * v.y;
	return (ret);
}
