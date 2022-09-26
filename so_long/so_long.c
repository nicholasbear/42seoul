/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicholasbear <nicholasbear@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:22:57 by wookim2           #+#    #+#             */
/*   Updated: 2022/09/27 03:48:07 by nicholasbea      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_game	*game;
	
	if (argc != 2)
		printf("Error not one map\n");
	check_map_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		printf("Error no file\n");
	game = (t_game *)malloc(sizeof(t_game));
	map_read(fd, game);
	game_init(game);
	map_error(game);
	mlx_hook(game->mlx_win, KEY_PRESS, 0, &keypress_event, game);
	mlx_hook(game->mlx_win, KEY_EXIT, 0, &click_redcross, game);
	mlx_loop(game->mlx);
	return (0);
}

void	check_map_name(char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		i--;
		j++;
	}
	i = ft_strlen(str);
	if (str[i - 3] != 'b' || str[i - 2] != 'e' || str[i - 1] != 'r' || j != 3)
		printf("not a ber file\n");
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	game->walk_count = 0;
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64, \
					game->height * 64, "so_long");
	setting_img(game);
}

void	map_read(int fd, t_game *game)
{
	char	*buf;
	int		height;

	height = 1;
	buf = get_next_line(fd);
	get_map_oneline(buf, height, game);
	while (buf)
	{
		height++;
		buf = get_next_line(fd);
		if (!buf)
			break ;
		get_map_oneline(buf, height, game);
	}
	close(fd);
}