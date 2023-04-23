/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:16:57 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 13:34:10 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 壁の衝突判定
 *
 * @detail 念のためマップ外（'2'）の要素でも検証を行っている
 * @param next_pos
 * @param map
 * @return true
 * @return false
 */
static bool	is_collided(t_vec next_pos, char **map)
{
	if (map[(int)next_pos.y][(int)next_pos.x] == '1')
		return (true);
	if (map[(int)next_pos.y][(int)next_pos.x] == '2')
		return (true);
	return (false);
}

/**
 * @brief 移動方向の点を取得する
 *
 * @param pos
 * @param move
 * @return t_vec
 */
static t_vec	get_next_position(t_vec pos, t_vec move, float coef)
{
	t_vec	next_pos;

	move.y = -move.y;
	next_pos = ft_add_vec(pos, ft_mul_vec(move, coef));
	return (next_pos);
}

/**
 * @brief 内積を用いて壁に沿ったベクトルを取得
 *
 * @param move 移動ベクトル
 * @param nor　法線ベクトル
 * @return t_vec
 */
static t_vec	get_vector_slide(t_vec move, t_vec nor)
{
	float	t;
	t_vec	s;

	t = -(nor.x * move.x + nor.y * move.y) / (nor.x * nor.x + nor.y * nor.y);
	s = (t_vec){move.x + t * nor.x, move.y + t * nor.y};
	return (s);
}

/**
 * @brief プレーヤーの移動ベクトルを壁に沿うように変更する
 *
 * @param game
 * @param move
 * @param pos
 * @param next_pos
 */
void
	turn_move_along_wall(t_game *game, t_vec move, t_vec pos, t_vec next_pos)
{
	t_news	wall_dir;
	t_vec	nor;

	wall_dir = get_collision_dir(move, pos, next_pos, game->map);
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
	p2 = get_next_position(game->player.pos, \
		ft_rotate_vec(game->player.move, M_PI / 5), 0.05);
	p3 = get_next_position(game->player.pos, \
		ft_rotate_vec(game->player.move, -M_PI / 5), 0.05);
	if (is_collided(p1, game->map) || is_collided(p2, game->map)
		|| is_collided(p3, game->map))
	{
		turn_move_along_wall(game, game->player.move, game->player.pos, p1);
		p1 = get_next_position(game->player.pos, game->player.move, MOVE_COEF);
		if (is_collided(p1, game->map))
			game->player.move = (t_vec){};
	}
}
