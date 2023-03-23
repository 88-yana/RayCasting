/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:29:32 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/23 07:01:11 by hyanagim         ###   ########.fr       */
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
void	handle_error(char *message);

//map
void	get_map_info(t_game *game, t_dictionary *dict);
void	input_file(t_game *game, const char *filename);
bool	is_valid_rgb_number(char **array, int i);
bool	is_valid_dict(t_dictionary *dict);
int		key_to_idx(char *key);
void	validate_file_contents(t_game *game, size_t height, char **contents);

//error

//utils
ssize_t	gnl_wrapper(int fd, char **line);

#endif