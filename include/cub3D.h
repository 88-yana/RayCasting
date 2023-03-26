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

typedef struct s_dictionary
{
	char	**key;
	char	**value;
}	t_dictionary;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_path_to_texture {
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_path_to_texture;
typedef struct s_map_info {
	t_path_to_texture	path;
	t_rgb				floor;
	t_rgb				ceiling;
	size_t				height;
	size_t				width;
	size_t				nswt[4];
	size_t				n;
	size_t				s;
	size_t				w;
	size_t				t;
}	t_map_info;

typedef struct s_game {
	char		**map;
	t_map_info	map_info;
}	t_game;

//check
void	check_arg(int argc, char **argv);
void	handle_error(char *message);

//map
void	set_map_info(t_game *game, t_dictionary *dict);
void	input_file(t_game *game, const char *filename);
void	check_map_surrounded(t_game *game);
bool	is_valid_dict(t_dictionary *dict);
bool	check_valid_map(t_game *game);
bool	is_valid_rgb_number(char **array, int i);
void	get_map_info(t_game *game, char **contents);
void	get_map(t_game *game, char **contents);

//error

//utils
ssize_t	gnl_wrapper(int fd, char **line);

#endif