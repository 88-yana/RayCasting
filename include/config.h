#ifndef CONFIG_H
# define CONFIG_H

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

# define WALL '1'
# define ROAD '0'
# define OUT ' '
# define MARK '2'

# define R 0
# define G 1
# define B 2

# define SP 2

# define FILE_HEADER_SIZE 6

/** Screen settings */
# define WIN_WIDTH 1280
# define WIN_HEIGHT 960
# define WIN_TITLE "Cub3D -- Mandatory"

/***** Key settings for Mac. *****/
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_Q 12
# define KEY_ESC 53

/* Key settings for Linux.
 * # define KEY_A 97
 * # define KEY_D 100
 * # define KEY_W 119
 * # define KEY_S 115
 * # define KEY_Q 113
 * # define KEY_LEFT 65361
 * # define KEY_RIGHT 65363
 * # define KEY_UP 65362
 * # define KEY_DOWN 65364
 * # define KEY_ESC 65307
*/

#endif