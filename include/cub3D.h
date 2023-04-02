#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h> //NULL
# include <unistd.h> //close
# include <fcntl.h> //O_RDONLY
# include <stdbool.h>
# include <errno.h>
# include <math.h>
# include "get_next_line.h"
# include "ft_printf.h"
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

typedef struct s_image {
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_image;

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

typedef struct s_player_info {
	t_vec	pos;
	t_vec	dir;
	float	distance_to_wall; //FIXME: 要らないかも
	float	wall_height;
	int		x_wall_on_minimap;
	int		y_wall_on_minimap;
	bool	n_wall;
	bool	s_wall;
	bool	w_wall;
	bool	e_wall;
}	t_player_info;

typedef struct s_game {
	char			**map;
	t_map_info		map_info;
	t_image			images;
	t_player_info	player;
	int				key_code;
	void			*mlx;
	void			*win;
}	t_game;

typedef enum e_input_key {
	MOVE_NONE = 0,
	MOVE_FORWARD = 1 << 0,
	MOVE_BACKWARD = 1 << 1,
	MOVE_RIGHT = 1 << 2,
	MOVE_LEFT = 1 << 3,
	ROTATE_RIGHT = 1 << 4,
	ROTATE_LEFT = 1 << 5,
	GAME_EXIT = 1 << 6,
	MOVE = MOVE_FORWARD | MOVE_BACKWARD | MOVE_RIGHT | MOVE_LEFT,
	ROTATE = ROTATE_RIGHT | ROTATE_LEFT,
	CONFIG = GAME_EXIT,
	ALL = ~0,
}	t_input_key;

//check
void	check_arg(int argc, char **argv);
void	handle_error(char *message);

//map
void	set_map_info(t_game *game, t_dictionary *dict);
void	input_file(t_game *game, const char *filename);
void	check_map_surrounded(t_game *game);
bool	is_valid_map_info(t_dictionary *dict);
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
void	draw_circle(t_image *img, t_vec *p, int r, int color);

//debug
void	print_debug_info(t_game *game);
#endif