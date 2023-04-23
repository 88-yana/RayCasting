/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:16:53 by tmuramat          #+#    #+#             */
/*   Updated: 2023/04/23 13:30:00 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 押下されたキーをストアに一時格納する。
 *
 * @param keycode
 * @param game
 * @return int
 */
int	store_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		game->key_store |= MOVE_FORWARD;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->key_store |= MOVE_BACKWARD;
	if (keycode == KEY_A)
		game->key_store |= MOVE_LEFT;
	if (keycode == KEY_D)
		game->key_store |= MOVE_RIGHT;
	if (keycode == KEY_LEFT)
		game->key_store |= ROTATE_LEFT;
	if (keycode == KEY_RIGHT)
		game->key_store |= ROTATE_RIGHT;
	if (keycode == KEY_M)
		game->key_store |= SWITCH_MINIMAP;
	return (0);
}

/**
 * @brief キー入力のストアをクリアする。
 *
 * @param keycode
 * @param game
 * @return int
 */
int	store_key_release(int keycode, t_game *game)
{
	(void)keycode;
	if (keycode == KEY_Q || keycode == KEY_ESC)
		game->key_store = GAME_EXIT;
	if (keycode == KEY_W || keycode == KEY_UP)
		game->key_store &= ~MOVE_FORWARD;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->key_store &= ~MOVE_BACKWARD;
	if (keycode == KEY_A)
		game->key_store &= ~MOVE_LEFT;
	if (keycode == KEY_D)
		game->key_store &= ~MOVE_RIGHT;
	if (keycode == KEY_LEFT)
		game->key_store &= ~ROTATE_LEFT;
	if (keycode == KEY_RIGHT)
		game->key_store &= ~ROTATE_RIGHT;
	if (keycode == KEY_M)
		game->key_store &= ~SWITCH_MINIMAP;
	return (0);
}

int	store_mouse_position(int x, int y, t_game *game)
{
	(void)y;
	game->mouse_pos_x = -(WIN_WIDTH / 2) + x;
	return (0);
}

void	player_move(t_game *game)
{
	game->player.move = ft_mul_vec(game->player.move, MOVE_COEF);
	game->player.pos.x += game->player.move.x;
	game->player.pos.y -= game->player.move.y;
}

int	update_game(t_game *game)
{
	fetch_key_input(game);
	fetch_mouse_position(game);
	check_collision(game);
	print_debug_info(game);
	player_move(game);
	render(game);
	return (0);
}
