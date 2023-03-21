/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:50:17 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/22 03:32:40 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		handle_error(NULL, ERR_FILE_OPEN);
	return (fd);
}

static size_t	cnt_file_height(int fd)
{
	char	*temp;
	size_t	file_height;

	file_height = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		if (ft_strcmp(temp, "\n") != 0)
			file_height++;
		free(temp);
	}
	return (file_height);
}

static ssize_t	gnl_wrapper(int fd, char **line, char ***file_contents)
{
	errno = 0;
	*line = get_next_line(fd);
	if (errno)
	{
		ft_free_matrix(file_contents);
		handle_error(NULL, ERR_MALLOC_FAILURE);
		return (-1);
	}
	if (*line == NULL)
		return (0);
	return (strlen(*line));
}

static char	**get_file_contents(int fd, size_t file_height)
{
	char	**file_contents;
	char	*temp;
	size_t	i;

	file_contents = malloc(sizeof(char *) * (file_height + 1));
	if (file_contents == NULL)
		handle_error(NULL, ERR_MALLOC_FAILURE);
	i = 0;
	while (gnl_wrapper(fd, &temp, &file_contents))
	{
		if (ft_strcmp(temp, "\n") != 0)
		{
			file_contents[i] = temp;
			i++;
		}
		else
			free(temp);
	}
	file_contents[i] = NULL;
	return (file_contents);
}

void	input_file(t_game *game, const char *filename)
{
	int		fd;
	size_t	file_height;
	char	**file_contents;

	fd = open_file(filename);
	file_height = cnt_file_height(fd);
	fd = open_file(filename);
	file_contents = get_file_contents(fd, file_height);
	close(fd);
	validate_file_contents(game, file_height, &file_contents);
	ft_free_matrix(&file_contents);
	system("leaks -q cub3D");
}
