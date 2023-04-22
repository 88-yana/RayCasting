#include "cub3D.h"

void	check_map_size(t_game *game)
{
	if (game->map_info.height > 50 || game->map_info.width > 50)
		handle_error(ERR_MAP_SIZE);
}
