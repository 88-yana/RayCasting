#include "cub3D.h"

#define COLLISION_MARGIN 0.5

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

t_vec	get_current_direction(t_game *game)
{
	t_vec	dir;

	dir = game->player.dir;
	if (game->key_store & MOVE_FORWARD)
		;
	if (game->key_store & MOVE_BACKWARD)
		dir = ft_rotate_vec(dir, M_PI);
	if (game->key_store & MOVE_LEFT)
		dir = ft_rotate_vec(dir, M_PI_2);
	if (game->key_store & MOVE_RIGHT)
		dir = ft_rotate_vec(dir, -M_PI_2);
	return (dir);
}

t_vec	get_next_position(t_vec pos, t_vec dir)
{
	t_vec	next;

	dir.y = -dir.y;
	next = ft_add_vec(pos, ft_mul_vec(dir, COLLISION_MARGIN));
	return (next);
}

void	check_collision(t_game *game)
{
	t_vec	pos;
	t_vec	dir;

	dir = get_current_direction(game);
	pos = get_next_position(game->player.pos, dir);
	if (is_collided_with_wall(pos, game->map))
	{
		game->key_store &= ~MOVE;
	}
}
