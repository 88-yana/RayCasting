#include "cub3D.h"

#define GREEN "\033[92m"
#define DEFAULT "\033[m"

int	exit_game(char *msg)
{
	ft_putendl_fd(GREEN, 2);
	ft_putendl_fd(msg, 2);
	ft_putendl_fd(DEFAULT, 2);
	exit(0);
}
