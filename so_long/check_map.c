#include "so_long.h"

void	get_map_oneline(char *buf, int height, t_game *game)
{
	int	width;

	width = ft_strlen_without_nl(buf);
	if (height == 1)
		game->width = width;
	else if (game->width != width)
		print_errors("it's not a rectangular\n");
	game->height = height;
	game->map = ft_strjoin_without_nl(game->map, buf);
	free(buf);
}

void    map_error(t_game *game)
{
    check_wall(game);
    if (game->c_count < 1 || game->p_count != 1 || game->e_count < 1)
		print_errors("map error\n");
}

void	check(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
        if (check_char(game->map[i]))
				print_errors("invalid charaters\n");
		if (i >= 0 && i < game->width)
            if(game->map[i] != '1')
			    print_errors("first line must be fill with a wall\n");
        if (i >= game->width * (game->height - 1) && i < game->width * game->height)
            if(game->map[i] != '1')
                print_errors("last line must be fill with a wall\n");
		if (i % game->width == 0 || i % game->width == game->width - 1)
            if(game->map[i] != '1')
                print_errors("first and last one must be a wall\n");
		counting_char(game->map[i], game);
		i++;
	}
}

int check_char(char map)
{
	if (map != '1' && map != '0' && map != 'E' && map != 'P' && map != 'C')
		return (0);
	return (1);
}

void	counting_char(char c, t_game *game)
{
	if (c == 'E')
		game->e_count += 1;
	if (c == 'P')
		game->p_count += 1;
	if (c == 'C')
		game->c_count += 1;
}