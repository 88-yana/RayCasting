/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:02:17 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 15:02:18 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "libft.h"

typedef struct s_dictionary
{
	char	**key;
	char	**value;
}	t_dictionary;
//
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

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		width;
	int		height;
}	t_image;
typedef struct s_image_data {
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
}	t_image_data;

typedef struct s_map_info {
	t_path_to_texture	path;
	t_rgb				floor;
	t_rgb				ceiling;
	size_t				height;
	size_t				width;
	size_t				nswt[4];
	size_t				cnt_n;
	size_t				cnt_s;
	size_t				cnt_w;
	size_t				cnt_e;
}	t_map_info;

typedef enum e_news
{
	NONE = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 4,
	NORTH = 8,
}	t_news;

typedef struct s_draw_info {
	float		x_wall[WIN_WIDTH];
	float		y_wall[WIN_WIDTH];
	float		wall_height[WIN_WIDTH];
	float		distance_to_wall[WIN_WIDTH];
	int			news[WIN_WIDTH];
}	t_draw_info;
typedef struct s_player_info {
	t_vec		pos;
	t_vec		dir;
	t_vec		move;
	t_draw_info	draw;
	float		distance_to_wall;
	float		wall_height;
	float		x_wall;
	float		y_wall;
	int			news;
}	t_player_info;

typedef struct s_game {
	char			**map;
	t_map_info		map_info;
	t_image_data	images;
	t_player_info	player;
	t_draw_info		draw;
	int				key_store;
	int				mouse_pos_x;
	void			*mlx;
	void			*win;
	t_image			img;
	bool			is_minimap;
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
	SWITCH_MINIMAP = 1 << 7,
	MOVE = MOVE_FORWARD | MOVE_BACKWARD | MOVE_RIGHT | MOVE_LEFT,
	ROTATE = ROTATE_RIGHT | ROTATE_LEFT,
	CONFIG = GAME_EXIT | SWITCH_MINIMAP,
	ALL = ~0,
}	t_input_key;

typedef struct s_ray {
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
}	t_ray;

#endif