/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:54:23 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/23 00:57:07 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_xopen(const char *filename, int flag)
{
	int	fd;

	fd = open(filename, flag);
	if (fd == -1)
		exit(EXIT_FAILURE);
	return (fd);
}
