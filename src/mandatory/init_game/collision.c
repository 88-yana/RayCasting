#include "cub3D.h"

bool	is_collided_with_wall(t_vec p, char **map)
{
	int	x;
	int	y;

	x = floorf(p.x);
	y = floorf(p.y);
	if (map[y][x] == '1')
		return (true);
	return (false);
}

void	check_collision(t_game *game)
{
	t_vec	p;
	char	**m;

	p = game->player.pos;
	m = game->map;
	if (is_collided_with_wall(p, m))
	{
		game->key_store = 0;
	}
}
