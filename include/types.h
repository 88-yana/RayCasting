#ifndef TYPES_H
# define TYPES_H

# include "libft.h"

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

typedef struct s_texture {
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_texture;

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
	size_t				e;
}	t_map_info;

typedef struct s_player_info {
	t_vec	pos;
	t_vec	dir;
	float	distance_to_wall; //FIXME: 要らないかも
	float	wall_height;
	int		x_wall_on_minimap;
	int		y_wall_on_minimap;
	int		near_x;
	int		near_y;
	bool	n_wall;
	bool	s_wall;
	bool	w_wall;
	bool	e_wall;
}	t_player_info;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_game {
	char			**map;
	t_map_info		map_info;
	t_texture		images;
	t_player_info	player;
	int				key_code;
	void			*mlx;
	void			*win;
	t_image			img;
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

typedef struct s_raycasting {
	float	dx;
	float	dy;
	t_vec	ray_dir;
	t_vec	x_pos_on_grid;
	t_vec	y_pos_on_grid;
	float	x_step_on_y_axis;
	float	y_step_on_x_axis;
	float	x_tile_step;
	float	y_tile_step;
	float	x_distance_to_wall;
	float	y_distance_to_wall;

}	t_raycasting;

#endif