/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:50:17 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/23 06:54:47 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static size_t	calc_line_count(int fd)
{
	char	*temp;
	size_t	line_count;

	line_count = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		if (ft_strcmp(temp, "\n") != 0)
			line_count++;
		free(temp);
	}
	if (line_count <= ELEMENT_SIZE)
		handle_error(ERR_INPUT_FILE);
	return (line_count);
}

static char	**get_file_contents(int fd, size_t line_count)
{
	char	**file_contents;
	char	*line;
	size_t	i;

	file_contents = ft_xmalloc(sizeof(char *) * (line_count + 1));
	i = 0;
	while (gnl_wrapper(fd, &line))
	{
		if (ft_strcmp(line, "\n") == 0)
		{
			free(line);
			continue ;
		}
		file_contents[i] = line;
		i++;
	}
	file_contents[i] = NULL;
	return (file_contents);
}

static size_t	get_line_count(const char *filename)
{
	int		fd;
	size_t	line_count;

	fd = ft_xopen(filename, O_RDONLY);
	line_count = calc_line_count(fd);
	close(fd);
	return (line_count);
}

static char	**read_file(const char *filename, size_t line_count)
{
	int		fd;
	char	**file_contents;

	fd = ft_xopen(filename, O_RDONLY);
	file_contents = get_file_contents(fd, line_count);
	close(fd);
	return (file_contents);
}

void	input_file(t_game *game, const char *filename)
{
	size_t	line_count;
	char	**file_contents;

	line_count = get_line_count(filename);
	file_contents = read_file(filename, line_count);
	validate_file_contents(game, line_count, file_contents);
	free(file_contents);
}
