/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:29:32 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/21 23:44:13 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h> //NULL
# include <fcntl.h> //O_RDONLY
# include <stdbool.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include "message.h"
# include "config.h"

typedef struct s_map_info {
	char	**path_to_texture[4];
	int		floor[3];
	int		ceiling[3];
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
bool	is_valid_info_format(char **info);
bool	is_valid_key(char **key);

//map
void	input_file(t_game *game, const char *filename);
void	validate_file_contents(t_game *game, char **contents, size_t height);

//error
void	free_char_array(char **array);
void	free_elements(char **contents, char **key, char **value);

#endif