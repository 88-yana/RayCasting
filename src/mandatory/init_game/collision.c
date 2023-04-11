#include "cub3D.h"

bool	is_collided_with_wall(t_vec next_pos, char **map)
{
	if (map[(int)next_pos.y][(int)next_pos.x] == '1')
		return (true);
	return (false);
}

bool	is_in_map(t_vec next_pos, t_game *game)
{
	char	**map;

	map = game->map;
	if (next_pos.x <= 0 || next_pos.x >= game->map_info.width)
		return (false);
	else if (next_pos.y <= 0 || next_pos.y >= game->map_info.height)
		return (false);
	return (true);
}

t_vec	get_next_position(t_vec pos, t_vec move)
{
	t_vec	next_pos;

	move.y = -move.y;
	next_pos = ft_add_vec(pos, ft_mul_vec(move, MOVE_COEF));
	return (next_pos);
}

t_vec	get_vector_slide(t_vec spd, t_vec nor)
{
	float	t;
	t_vec	s;

	t = -(nor.x * spd.x + nor.y * spd.y) / (nor.x * nor.x + nor.y * nor.y);
	s = (t_vec){spd.x + t * nor.x, spd.y + t * nor.y};
	return (s);
}

t_news	detect_collision_direction(t_vec move, t_vec pos, t_vec next_pos, char **map)
{
	if (move.x >= 0 && move.y >= 0)
	{
		if (map[(int)next_pos.y][(int)pos.x] == '1')
			return (SOUTH);
		else if (map[(int)pos.y][(int)next_pos.x] == '1')
			return (WEST);
	}
	else if (move.x < 0 && move.y >= 0)
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
	else if (move.x >= 0 && move.y < 0)
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
		return ((t_vec){0, -1});
	if (wall & EAST)
		return ((t_vec){-1, 0});
	if (wall & WEST)
		return ((t_vec){1, 0});
	if (wall & SOUTH)
		return ((t_vec){0, 1});
	return ((t_vec){0, 0});
}

void	turn_move_along_wall(t_game *game, t_vec move, t_vec pos, t_vec next_pos)
{
	t_news	wall_dir;
	t_vec	nor;

	wall_dir = detect_collision_direction(move, pos, next_pos, game->map);
	if (wall_dir & NONE)
	{
		game->player.move = (t_vec){};
		return ;
	}
	nor = get_normal_vector(wall_dir);
	if (!nor.x && !nor.y)
	{
		game->player.move = (t_vec){};
		return ;
	}
	game->player.move = get_vector_slide(move, nor);
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
		turn_move_along_wall(game, move, pos, next_pos);
		next_pos = get_next_position(game->player.pos, game->player.move);
		if (is_collided_with_wall(next_pos, game->map))
			game->player.move = (t_vec){};
	}
}
