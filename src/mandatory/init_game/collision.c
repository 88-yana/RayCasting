#include "cub3D.h"

/**
 * @brief 壁の衝突判定
 *
 * @param next_pos
 * @param map
 * @return true
 * @return false
 */
bool	is_collided_with_wall(t_vec next_pos, char **map)
{

	if (map[(int)next_pos.y][(int)next_pos.x] == '1')
		return (true);
	return (false);
}

/**
 * @brief マップの内外判定
 *
 * @detail 壁判定が先立つためtrueになることは考えにくいが、SEGV対策として実装
 * @param next_pos
 * @param game
 * @return true　プレーヤーがマップ内にいる
 * @return false
 */
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

/**
 * @brief 移動方向の点を取得する
 *
 * @param pos
 * @param move
 * @return t_vec
 */
t_vec	get_next_position(t_vec pos, t_vec move, float coef)
{
	t_vec	next_pos;

	move.y = -move.y;
	next_pos = ft_add_vec(pos, ft_mul_vec(move, coef));
	return (next_pos);
}

/**
 * @brief 内積を用いて壁に沿ったベクトルを取得
 *
 * @param spd
 * @param nor
 * @return t_vec
 */
t_vec	get_vector_slide(t_vec spd, t_vec nor)
{
	float	t;
	t_vec	s;

	t = -(nor.x * spd.x + nor.y * spd.y) / (nor.x * nor.x + nor.y * nor.y);
	s = (t_vec){spd.x + t * nor.x, spd.y + t * nor.y};
	return (s);
}

/**
 * @brief 衝突した壁の向きを判定
 *
 * @param move
 * @param pos
 * @param next_pos
 * @param map
 * @return t_news
 */
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

/**
 * @brief 壁の向きから法線ベクトルを決定する
 *
 * @param wall
 * @return t_vec
 */
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


/**
 * @brief プレーヤーの移動ベクトルを壁に沿うように変更する
 *
 * @param game
 * @param move
 * @param pos
 * @param next_pos
 */
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

/**
 * @brief プレーヤーの衝突判定
 *
 * @param game
 */
void	check_collision(t_game *game)
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;

	p1 = get_next_position(game->player.pos, game->player.move, 0.3);
	p2 = get_next_position(game->player.pos, ft_rotate_vec(game->player.move, M_PI / 5), 0.1);
	p3 = get_next_position(game->player.pos, ft_rotate_vec(game->player.move, -M_PI / 5), 0.1);
	if (is_collided_with_wall(p1, game->map) || is_collided_with_wall(p2, game->map)
		|| is_collided_with_wall(p3, game->map) || !is_in_map(p1, game))
	{
		turn_move_along_wall(game, game->player.move, game->player.pos, p1);
		p1 = get_next_position(game->player.pos, game->player.move, MOVE_COEF);
		if (is_collided_with_wall(p1, game->map))
			game->player.move = (t_vec){};
	}
}
