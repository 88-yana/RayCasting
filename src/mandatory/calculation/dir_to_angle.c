#include "cub3D.h"

float	dir_to_angle(t_vec dir)
{
	if (dir.x > 0 && dir.y > 0)
		return (atan(dir.y / dir.x));
	if (dir.x < 0 && dir.y > 0)
		return (atan(-dir.x / dir.y) + M_PI_2);
	if (dir.x < 0 && dir.y < 0)
		return (atan(dir.y / dir.x) + M_PI);
	if (dir.x > 0 && dir.y < 0)
		return (atan(dir.x / -dir.y) + 3 * M_PI_2);
	if (dir.x == 0)
	{
		if (dir.y == 1)
			return (M_PI_2);
		else if (dir.y == -1)
			return (3 * M_PI_2);
	}
	if (dir.y == 0)
	{
		if (dir.x == 1)
			return (0);
		else if (dir.x == -1)
			return (M_PI);
	}
	return (0);
}
