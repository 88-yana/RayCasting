#include "cub3D.h"

/**
 * @brief カラー情報の作成
 *
 * @param t 透過度
 * @param r 赤
 * @param g 緑
 * @param b 青
 * @return int
 */
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
