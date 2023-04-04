#include "cub3D.h"

bool	set_inf(float *x, float *y)
{
	*x = INF;
	*y = INF;
	return (true);
}

bool	is_out_of_map_height(t_game *game, double y)
{
	if (y < 0 || game->map_info.height + SP <= y)
		return (true);
	return (false);
}

bool	is_out_of_map_width(t_game *game, double x)
{
	if (x < 0 || game->map_info.width + SP <= x)
		return (true);
	return (false);
}



bool	finish_x_wall(t_game *game, t_raycasting *ray_info)
{
	float	*x = &ray_info->x_pos_on_grid.x;
	float	*y = &ray_info->x_pos_on_grid.y;
	int		map_x = *x;
	int		map_y = floor(*y);

	if (is_out_of_map_height(game, map_y))
			return (set_inf(x, y));
	if (ray_info->ray_dir.x > 0 && is_out_of_map_width(game, map_x))
			return (set_inf(x, y));
	if (ray_info->ray_dir.x < 0 && is_out_of_map_width(game, map_x - 1))
			return (set_inf(x, y));
	if (ray_info->ray_dir.x == 0)
		return (set_inf(x, y));
	if (ray_info->ray_dir.x > 0)
		if (game->map[map_y][map_x] == '1')
			return (true);
	if (ray_info->ray_dir.x < 0)
		if (game->map[map_y][map_x - 1] == '1')
			return (true);
	return (false);
}

bool	finish_y_wall(t_game *game, t_raycasting *ray_info)
{
	float	*x = &ray_info->y_pos_on_grid.x;
	float	*y = &ray_info->y_pos_on_grid.y;
	int		map_x = floor(*x);
	int		map_y = *y;

	if (ray_info->ray_dir.y > 0 && is_out_of_map_height(game, map_y - 1))
		return (set_inf(x, y));
	if (ray_info->ray_dir.y < 0 && is_out_of_map_height(game, map_y))
		return (set_inf(x, y));
	if (is_out_of_map_width(game, map_x))
		return (set_inf(x, y));
	if (ray_info->ray_dir.y == 0)
		return (set_inf(x, y));
	if (ray_info->ray_dir.y > 0)
		if (game->map[map_y - 1][map_x] == '1')
			return (true);
	if (ray_info->ray_dir.y < 0)
		if (game->map[map_y][map_x] == '1')
			return (true);
	return (false);
}

void	walk_to_x_wall(t_game *game, t_raycasting *ray_info)
{
	if (ray_info->x_tile_step == 0 && ray_info->x_step_on_y_axis == 0)
	{
		set_inf(&ray_info->x_pos_on_grid.x, &ray_info->x_pos_on_grid.y);
		return ;
	}
	while (1)
	{
		if (finish_x_wall(game, ray_info))
			break ;
		ray_info->x_pos_on_grid.x += ray_info->x_tile_step;
		ray_info->x_pos_on_grid.y += ray_info->x_step_on_y_axis;
	}
}

void	walk_to_y_wall(t_game *game, t_raycasting *ray_info)
{
	if (ray_info->y_tile_step == 0 && ray_info->y_step_on_x_axis == 0)
	{
		set_inf(&ray_info->y_pos_on_grid.x, &ray_info->y_pos_on_grid.y);
		return ;
	}
	while (1)
	{
		if (finish_y_wall(game, ray_info))
			break ;
		ray_info->y_pos_on_grid.x += ray_info->y_step_on_x_axis;
		ray_info->y_pos_on_grid.y += ray_info->y_tile_step;
	}
}

void	walk_to_wall(t_game *game, t_player_info *player, t_raycasting *ray_info)
{
	(void) player;
	walk_to_x_wall(game, ray_info);
	walk_to_y_wall(game, ray_info);
}
