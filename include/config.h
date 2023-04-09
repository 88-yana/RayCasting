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
# define WALL_HEIGHT 150
# define VIEWING_ANGLE 30
# define INF 3000

# define TIP_SIZE 10
# define MOVE_COEF 0.1f

/** Color Settings */
# define COLOR_BLACK  0x0000000
# define COLOR_RED  0x0f15b5b
# define COLOR_GREEN 0x000FF00
# define COLOR_GRAY 0x0eae8e1
# define COLOR_LGRAY 0x0afafb0
# define COLOR_YELLOW 0x0FFFF00

/** Screen settings */
# define WIN_WIDTH 800
# define WIN_HEIGHT 640
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
# define KEY_M 46
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