#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h> //NULL
# include <unistd.h> //close
# include <fcntl.h> //O_RDONLY
# include <stdbool.h>
# include <errno.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"
# include "message.h"
# include "config.h"
# include "types.h"

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

//init
void	init_game(t_game *game);
void	load_images(t_game *game);
void	set_event_hooks(t_game *game);
int		exit_game(char *msg);
void	load_player(t_game *game);

//key_input
void	fetch_key_input(t_game *game);

//utils
ssize_t	gnl_wrapper(int fd, char **line);
int		create_trgb(int t, int r, int g, int b);

//debug
void	print_debug_info(t_game *game);
#endif