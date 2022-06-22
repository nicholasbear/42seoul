/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:17:08 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/16 13:57:52 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checkboard(int board[][4], int row, int col)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < col)
	{
		if (board[row][i] == board[row][col])
			return (0);
		i++;
	}
	while (j < row)
	{
		if (board[j][col] == board[row][col])
			return (0);
		j++;
	}
	return (1);
}

int	countview(int*a)
{
	int	i;
	int	j;
	int	num;
	int	check;

	i = 0;
	num = 1;
	while (++i < 4)
	{
		j = -1;
		check = 0;
		while (++j < i)
			if (a[i] > a[j])
				check++;
		if (check == i)
			num++;
	}
	return (num);
}

int	checkview(int board[][4], int*input)
{
	int	a[16][4];
	int	i;
	int	k;

	i = -1;
	while (++i < 16)
	{
		k = -1;
		while (++k < 4)
		{
			if (i <= 3)
				a[i][k] = board[k][i % 4];
			else if (i <= 7)
				a[i][k] = board[3 - k][i % 4];
			else if (i <= 11)
				a[i][k] = board[i % 4][k];
			else
				a[i][k] = board[i % 4][3 - k];
		}
	}
	i = -1;
	while (++i < 16)
		if (countview(a[i]) != input[i])
			return (0);
	return (1);
}

int	fullboard(int board[][4], int*input)
{
	int		i;
	int		j;
	char	c;

	if (checkview(board, input) == 1)
	{
		i = -1;
		while (++i < 4)
		{
			j = 0;
			while (j < 4)
			{
				c = board[i][j] + 49;
				write(1, &c, 1);
				if (j != 3)
					write(1, " ", 1);
				j++;
			}
			write(1, "\n", 1);
		}
		input[16] += 1;
		return (1);
	}
	else
		return (0);
}

void	makeboard(int board[][4], int row, int col, int*input)
{
	int	i;

	if (input[16] != 0)
		return ;
	i = -1;
	while (++i < 4)
	{
		board[row][col] = i;
		if (checkboard(board, row, col) == 1)
		{
			if (row == 3 && col == 3)
			{
				if (fullboard(board, input) == 1)
					return ;
			}
			else
			{
				if (col == 3)
					makeboard(board, row + 1, 0, input);
				else
					makeboard(board, row, col + 1, input);
			}
		}
	}
	return ;
}
