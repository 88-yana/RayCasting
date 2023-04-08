#include "cub3D.h"

#define COLLISION_MARGIN 0.3

bool	is_collided_with_wall(t_vec p, char **map)
{
	if (map[(int)p.y][(int)p.x] == '1')
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
	t_vec	next_pos;

	dir.y = -dir.y;
	next_pos = ft_add_vec(pos, ft_mul_vec(dir, COLLISION_MARGIN));
	return (next_pos);
}

void	check_collision(t_game *game)
{
	t_vec	next_pos1;
	t_vec	next_pos2;
	t_vec	dir;

	dir = get_current_direction(game);
	ft_rotate_vec(dir, M_PI / 12);
	next_pos1 = get_next_position(game->player.pos, dir);
	ft_rotate_vec(dir, -M_PI / 12);
	next_pos2 = get_next_position(game->player.pos, dir);
	if (is_collided_with_wall(next_pos1, game->map)
		&& is_collided_with_wall(next_pos2, game->map))
	{
		game->key_store &= ~MOVE;
	}
}

/*
t_vec	get_normal_vector(t_game *game)
{
	t_vec	dir;
	t_vec	nor;

	dir = game->player.dir;
	nor = (t_vec){0, 0};
	if (dir.x > 0 && dir.y > 0)
		nor = (t_vec){0, 1};
	return (dir);
}

t_vec	get_vector_slide(t_vec spd, t_vec nor)
{
	int		t;
	t_vec	s;

	t = -(nor.x * spd.x + nor.y * spd.y) / (nor.x * nor.x + nor.y * nor.y);
	s = (t_vec){spd.x + t * nor.x, spd.y + t * nor.y};
	return (s);
}

void	calc_slide_vector(t_game *game)
{
	t_vec	nor;
	t_vec	s;

	nor = get_normal_vector(game);
	s = get_vector_slide(game->player.dir, nor);
	s = ft_mul_vec(s, MOVE_COEF);
	game->player.pos.x += s.x;
	game->player.pos.y -= s.y;
}
*/