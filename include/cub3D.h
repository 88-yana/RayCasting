/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:29:32 by hyanagim          #+#    #+#             */
/*   Updated: 2023/03/21 19:53:19 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include "message.h"

typedef struct s_game {

}	t_game;


//check
void	check_arg(int argc, char **argv);
void	handle_error(t_game *game, char *message);

#endif