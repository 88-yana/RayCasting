#include "cub3D.h"

bool	finish_x_wall(t_game *game, t_ray *ray_info)
{
	int		map_x;
	int		map_y;

	if (except_x_error(game, ray_info))
		return (true);
	map_x = ray_info->x_pos_on_grid.x;
	map_y = floor(ray_info->x_pos_on_grid.y);
	if (ray_info->ray_dir.x > 0)
		if (game->map[map_y][map_x] == '1')
			return (true);
	if (ray_info->ray_dir.x < 0)
		if (game->map[map_y][map_x - 1] == '1')
			return (true);
	return (false);
}

bool	finish_y_wall(t_game *game, t_ray *ray_info)
{
	int		map_x;
	int		map_y;

	if (except_y_error(game, ray_info))
		return (true);
	map_x = floor(ray_info->y_pos_on_grid.x);
	map_y = ray_info->y_pos_on_grid.y;
	if (ray_info->ray_dir.y > 0)
		if (game->map[map_y - 1][map_x] == '1')
			return (true);
	if (ray_info->ray_dir.y < 0)
		if (game->map[map_y][map_x] == '1')
			return (true);
	return (false);
}

void	walk_to_x_wall(t_game *game, t_ray *ray_info)
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

void	walk_to_y_wall(t_game *game, t_ray *ray_info)
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

void	walk_to_wall(t_game *game, t_ray *ray_info)
{
	walk_to_x_wall(game, ray_info);
	walk_to_y_wall(game, ray_info);
}
