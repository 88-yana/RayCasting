/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_wrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:01:37 by hyanagim          #+#    #+#             */
/*   Updated: 2023/04/23 01:17:38 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

ssize_t	gnl_wrapper(int fd, char **line)
{
	errno = 0;
	*line = get_next_line(fd);
	if (errno)
		exit(EXIT_FAILURE);
	if (*line == NULL)
		return (0);
	return (ft_strlen(*line));
}
