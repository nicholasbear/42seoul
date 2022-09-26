/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:26:10 by wookim2           #+#    #+#             */
/*   Updated: 2022/09/25 17:26:12 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		e_count;
	int		p_count;
	int		c_count;
	int		point_count;
	int		walk_count;
	char	*map;
	t_img	*img;
}	t_game;

typedef struct s_img
{
	void	*empty;
	void	*end;
	void	*item;
	void	*player;
	void	*wall;
}			t_img;


void	check_map_name(char *str);
void	game_init(t_game *game, char *map);
void	map_read(int fd, t_game *game);




#endif