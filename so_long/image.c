#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	img;
	int		w;
	int		h;

	img.empty = mlx_xpm_file_to_image(mlx, "./img/empty.xpm", &w, &h);
	img.wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &w, &h);
	img.end = mlx_xpm_file_to_image(mlx, "./img/end.xpm", &w, &h);
	img.item = mlx_xpm_file_to_image(mlx, "./img/item.xpm", &w, &h);
	img.player = mlx_xpm_file_to_image(mlx, "./img/player.xpm", &w, &h);
	return (img);
}

void	setting_img(t_game *game)
{
	int		current_h;
	int		current_w;

	current_h = 0;
	while (current_h < game->height)
	{
		current_w = 0;
		while (current_w < game->width)
		{
			put_img(game, current_w, current_h);
			current_w++;
		}
		current_h++;
	}
}

void	put_img(t_game *g, int w, int h)
{
	if (g->map[h * g->width + w] == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.wall, \
			w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.item, \
			w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'P')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player, \
			w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.end, \
			w * 64, h * 64);
	else
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.empty, \
			w * 64, h * 64);
}