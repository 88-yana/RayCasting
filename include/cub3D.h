/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:12:07 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 14:42:33 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "types.h"

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
void	draw_wall_collision_point(t_game *game);
void	draw_minimap(t_game *game);
bool	is_start_position(char tile);
void	draw_wall_intersection(t_game *game);
void	check_map_size(t_game *game);

//key_mouse_input
void	fetch_key_input(t_game *game);
void	fetch_mouse_position(t_game *game);

//collision
void	check_collision(t_game *game);
t_vec	get_normal_vector(t_news wall);
t_news	get_collision_dir(t_vec move, t_vec pos, t_vec next_pos, char **map);

//utils
ssize_t	gnl_wrapper(int fd, char **line);
int		create_trgb(int t, int r, int g, int b);
void	draw_player_pos(t_game *game);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	draw_pixel(t_image *img, int x, int y, int color);

int		render(t_game *game);
int		update_game(t_game *game);
void	player_move(t_game *game);
int		store_mouse_position(int x, int y, t_game *game);
int		store_key_press(int keycode, t_game *game);
int		store_key_release(int keycode, t_game *game);

//raycasting
void	walk_to_wall(t_game *game, t_ray *ray_info);
void	emit_ray(t_game *game);
bool	is_out_of_map_height(t_game *game, double y);
bool	is_out_of_map_width(t_game *game, double x);
void	ray_casting(t_game *game);
float	dir_to_angle(t_vec dir);
void	get_wall_height(t_game *game, t_vec ray_dir, float theta);
void	calc_dx_dy(t_player_info *player, t_ray *ray_info);
void	calc_tile_step(t_ray *ray_info);
void	calc_digital_difference(t_ray *ray_info, float theta);
float	calc_distance_to_wall(
			t_player_info *player, t_ray *ray_info, t_vec wall_vec);
float	calc_wall_height(float distance_to_wall);
bool	set_inf(float *x, float *y);
bool	except_x_error(t_game *game, t_ray *ray_info);
bool	except_y_error(t_game *game, t_ray *ray_info);
void	draw_pixel(t_image *img, int x, int y, int color);
void	draw_rectangle(t_image *img, t_vec *p, int size, int color);
void	draw_screen(t_game *game, int x_axis);
void	draw_back(t_game *game);
void	draw_rays_on_screen(t_game *game);
void	draw_rays_on_minimap(t_game *game);
void	draw_player_on_minimap(t_game *game);
void	measure_distance_to_wall(t_game *game, t_ray *ray_info, float theta);

//minimap
void	draw_line(t_game *game, t_vec v0, t_vec v1, int color);
void	draw_player_position(t_game *game);
void	draw_player_pos(t_game *game);
void	switch_display_minimap(t_game *game);

//debug
void	print_debug_info(t_game *game);
void	draw_ray_on_near_grid(t_game *game);
#endif