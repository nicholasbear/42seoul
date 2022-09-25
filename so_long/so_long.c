/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:22:57 by wookim2           #+#    #+#             */
/*   Updated: 2022/09/25 17:23:00 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(int ac, char *av[])
{
	int			fd;
	
	if (ac != 2)
		print_errors("not one map");
	check_map_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_errors("dosent exist a file\n");
	init_game_info(fd, game);
	init_game(game);
	mlx_hook(game->mlx_win, KEY_PRESS, 0, &keypress_event, game);
	mlx_hook(game->mlx_win, KEY_EXIT, 0, &click_redcross, game);
	mlx_loop(game->mlx);
	return (0);
}