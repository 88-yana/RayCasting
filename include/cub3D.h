/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:29:32 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/23 03:12:25 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h> //NULL
# include <unistd.h> //close
# include <fcntl.h> //O_RDONLY
# include <stdbool.h>
# include <errno.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include "message.h"
# include "config.h"
# include "map.h"

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;
typedef struct s_map_info {
	char	*path_to_texture[4];
	t_rgb	floor;
	t_rgb	ceiling;
	int		height;
	int		width;
}	t_map_info;

typedef struct s_game {
	char		**map;
	t_map_info	map_info;
}	t_game;

//check
void	check_arg(int argc, char **argv);
void	handle_error(t_game *game, char *message);
bool	is_valid_key_value_format(char ***info);
int		key_to_idx(char *key);
bool	is_valid_rgb(char *value);
bool	is_valid_number(char **array, int i);

//map
void	input_file(t_game *game, const char *filename);
void	validate_file_contents(t_game *game, size_t height, char **contents);
bool	is_valid_dict(t_dictionary *dict);

//error
void	free_char_array(char **array);
void	free_elements(char ***contents, char ***key, char ***value);

//utils
ssize_t	gnl_wrapper(int fd, char **line);

#endif