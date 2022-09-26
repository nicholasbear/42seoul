/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicholasbear <nicholasbear@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:26:10 by wookim2           #+#    #+#             */
/*   Updated: 2022/09/27 03:49:06 by nicholasbea      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

# define KEY_PRESS   2
# define KEY_EXIT    17

# define ESC         53
# define A           0
# define S           1
# define D           2
# define W           13

typedef struct s_img
{
	void	*empty;
	void	*end;
	void	*item;
	void	*player;
	void	*wall;
}			t_img;

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
	t_img	img;
}	t_game;

void	check_map_name(char *str);
void	game_init(t_game *game);
void	map_read(int fd, t_game *game);
void	get_map_oneline(char *buf, int height, t_game *game);
void    map_error(t_game *game);
void	check(t_game *game);
int 	check_char(char map);
void	counting_char(char c, t_game *game);
t_img	img_init(void *mlx);
void	setting_img(t_game *game);
void	put_img(t_game *g, int w, int h);
void	clear_game(t_game *game);
int		keypress_event(int key, t_game *game);
int		click_redcross(t_game *game);
void	press_key(t_game *game, int move);
int		ft_strlen_without_nl(char *str);
char	*ft_strdup_without_nl(char	*s1);
void	ft_strlcpy_without_nl(char *dest, char *src, int read_len);
char	*ft_strjoin_without_nl(char *s1, char *s2);

#endif