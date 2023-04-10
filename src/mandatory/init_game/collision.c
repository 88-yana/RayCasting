#include "cub3D.h"

#define COLLISION_MARGIN 0.3

bool	is_collided_with_wall(t_vec next_pos, char **map)
{
	if (map[(int)next_pos.y][(int)next_pos.x] == '1')
		return (true);
	return (false);
}

t_vec	get_next_position(t_vec pos, t_vec move)
{
	t_vec	next_pos;

	move.y = -move.y;
	next_pos = ft_add_vec(pos, ft_mul_vec(move, COLLISION_MARGIN));
	return (next_pos);
}

t_vec	get_vector_slide(t_vec spd, t_vec nor)
{
	int		t;
	t_vec	s;

	t = -(nor.x * spd.x + nor.y * spd.y) / (nor.x * nor.x + nor.y * nor.y);
	s = (t_vec){spd.x + t * nor.x, spd.y + t * nor.y};
	return (s);
}

t_news	detect_collision_direction(t_vec move, t_vec pos, t_vec next_pos, char **map)
{
	if (move.x > 0 && move.y > 0)
	{
		if (map[(int)next_pos.y][(int)pos.x] == '1')
			return (SOUTH);
		else if (map[(int)pos.y][(int)next_pos.x] == '1')
			return (WEST);
	}
	else if (move.x < 0 && move.y > 0)
	{
		if (map[(int)next_pos.y][(int)pos.x] == '1')
			return (SOUTH);
		else if (map[(int)pos.y][(int)next_pos.x] == '1')
			return (EAST);
	}
	else if (move.x < 0 && move.y < 0)
	{
		if (map[(int)next_pos.y][(int)pos.x] == '1')
			return (NORTH);
		else if (map[(int)pos.y][(int)next_pos.x] == '1')
			return (EAST);
	}
	else if (move.x > 0 && move.y < 0)
	{
		if (map[(int)next_pos.y][(int)pos.x] == '1')
			return (NORTH);
		else if (map[(int)pos.y][(int)next_pos.x] == '1')
			return (WEST);
	}
	return (NONE);
}

t_vec	get_normal_vector(t_news wall)
{
	if (wall & NORTH)
		return ((t_vec){0, 1});
	if (wall & EAST)
		return ((t_vec){-1, 0});
	if (wall & WEST)
		return ((t_vec){1, 0});
	if (wall & SOUTH)
		return ((t_vec){0, -1});
	return ((t_vec){0, 0});
}

void	check_collision(t_game *game)
{
	t_vec	move;
	t_vec	pos;
	t_vec	next_pos;

	move = game->player.move;
	pos = game->player.pos;
	next_pos = get_next_position(game->player.pos, game->player.move);
	if (is_collided_with_wall(next_pos, game->map))
	{
		t_news wall = detect_collision_direction(move, pos, next_pos, game->map);
		if (wall & NORTH)
			puts("N");
		if (wall & SOUTH)
			puts("S");
		if (wall & WEST)
			puts("W");
		if (wall & EAST)
			puts("E");
		t_vec nor = get_normal_vector(wall);
		game->player.move = get_vector_slide(ft_mul_vec(move, 5), nor);
		game->key_store &= ~MOVE;
	}
}
