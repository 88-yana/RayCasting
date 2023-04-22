#include "cub3D.h"

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
