/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 03:34:58 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/07 03:34:58 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qsort(void *base, size_t n, size_t size,
			int (*cmp)(const void *, const void *))
{
	size_t			lo;
	size_t			hi;
	size_t			pt;
	unsigned char	*v;

	if (n <= 1)
		return ;
	lo = 0;
	hi = n - 1;
	pt = (lo + hi) / 2;
	v = (unsigned char *)base;
	while (true)
	{
		while (cmp(&v[lo * size], &v[pt * size]) < 0)
			lo++;
		while (cmp(&v[hi * size], &v[pt * size]) > 0)
			hi--;
		if (lo >= hi)
			break ;
		ft_memswap(&v[lo * size], &v[hi * size], size);
		lo++;
		hi--;
	}
	qsort(&v[0], hi + 1, size, cmp);
	qsort(&v[lo * size], n - lo, size, cmp);
}
