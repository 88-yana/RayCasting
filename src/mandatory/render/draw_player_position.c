#include "cub3D.h"

/**
 * @brief 三角形を囲む矩形の範囲を算出
 *
 * @param v
 * @param min
 * @param max
 */
void	get_boundaries(t_vec v[3], t_vec *min, t_vec *max)
{
	min->x = ft_min(v[0].x, ft_min(v[1].x, v[2].x));
	min->y = ft_min(v[0].y, ft_min(v[1].y, v[2].y));
	max->x = ft_max(v[0].x, ft_max(v[1].x, v[2].x));
	max->y = ft_max(v[0].y, ft_max(v[1].y, v[2].y));
}

/**
 * @brief 三角形の内外判定
 *
 * @param v
 * @param p
 * @return true
 * @return false
 */
bool	is_inside_triangle(t_vec v[3], t_vec p)
{
	float	a[3];

	a[0] = ((v[1].x - v[0].x) * (p.y - v[0].y) \
		- (p.x - v[0].x) * (v[1].y - v[0].y)) / 2.0f;
	a[1] = ((v[2].x - v[1].x) * (p.y - v[1].y) \
		- (p.x - v[1].x) * (v[2].y - v[1].y)) / 2.0f;
	a[2] = ((v[0].x - v[2].x) * (p.y - v[2].y) \
		- (p.x - v[2].x) * (v[0].y - v[2].y)) / 2.0f;
	if (a[0] >= 0.0f && a[1] >= 0.0f && a[2] >= 0.0f)
		return (true);
	return (false);
}

/**
 * @brief 三角形を塗りつぶして描画
 *
 * @param img
 * @param v
 * @param color
 */
void	draw_triangle(t_image *img, t_vec v[3], int color)
{
	t_vec	min;
	t_vec	max;
	int		y;
	int		x;

	get_boundaries(v, &min, &max);
	y = min.y;
	while (y <= max.y)
	{
		x = min.x;
		while (x <= max.x)
		{
			if (is_inside_triangle(v, (t_vec){x, y}) == true)
				draw_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_player_position(t_game *game)
{
	t_vec	p;
	t_vec	d;
	t_vec	v[3];

	p = game->player.pos;
	d = game->player.dir;
	d = (t_vec){d.x, -d.y};
	v[0] = ft_add_vec(p, d);
	v[1] = ft_add_vec(p, ft_mul_vec(ft_rotate_vec(d, M_PI * 2.0 / 3.0), 0.5));
	v[2] = ft_add_vec(p, ft_mul_vec(ft_rotate_vec(d, -M_PI * 2.0 / 3.0), 0.5));
	v[0] = ft_mul_vec(v[0], TIP_SIZE);
	v[1] = ft_mul_vec(v[1], TIP_SIZE);
	v[2] = ft_mul_vec(v[2], TIP_SIZE);
	draw_triangle(&game->img, v, COLOR_RED);
}
