#include "cub3D.h"

void	move_player(t_game *game)
{
	t_player_info	*player;

	player = &game->player;
	if (game->key_code == MOVE_FORWARD)
		ft_add_vec(player->pos, (t_vec){0, -1});
	else if (game->key_code == MOVE_BACKWARD)
		ft_add_vec(player->pos, (t_vec){0, 1});
	else if (game->key_code == MOVE_LEFT)
		ft_add_vec(player->pos, (t_vec){-1, 0});
	else if (game->key_code == MOVE_RIGHT)
		ft_add_vec(player->pos, (t_vec){1, 0});
}
