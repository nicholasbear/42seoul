/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:17:08 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/16 18:00:17 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checkboard(int board[][9], int row, int col)
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

int	countview(int*a, int n)
{
	int	i;
	int	j;
	int	num;
	int	check;
	
	i = 0;
	num = 1;
	while (++i < n)
	{
		j = -1;
		check = 0;
		while (++j < i)
		{
			if (a[i] > a[j])
				check++;
		}
		if (check == i)
			num++;
	}
	return (num);
}

int	checkview(int board[][9], int*input, int n)
{
	int	a[36][9];
	int	i;
	int	k;

	i = -1;
	while (++i < 4 * n)
	{
		k = -1;
		while (++k < n)
		{
			if (i < n)
				a[i][k] = board[k][i % n];
			else if (i < 2 * n)
				a[i][k] = board[n - 1 - k][i % n];
			else if (i < 3 * n)
				a[i][k] = board[i % n][k];
			else
				a[i][k] = board[i % n][n - 1 - k];
		}
	}
	i = -1;
	while (++i < 4 * n)
		if (countview(a[i], n) != input[i])
			return (0);
	return (1);
}

int	fullboard(int board[][9], int*input, int n)
{
	int		i;
	int		j;
	char	c;

	if (checkview(board, input, n) == 1)
	{
		i = -1;
		while (++i < n)
		{
			j = 0;
			while (j < n)
			{
				c = board[i][j] + 49;
				write(1, &c, 1);
				if (j != n - 1)
					write(1, " ", 1);
				j++;
			}
			write(1, "\n", 1);
		}
		input[4 * n] += 1;
		return (1);
	}
	else
		return (0);
}

void	makeboard(int board[][9], int point, int*input, int n)
{
	int	i;
	if (input[4 * n] != 0)
		return ;
	i = -1;
	while (++i < n)
	{
		board[point / 10][point % 10] = i;
		if (checkboard(board, point / 10, point % 10) == 1)
		{
			if (point / 10 == n - 1 && point % 10 == n - 1)
			{
				if (fullboard(board, input, n) == 1)
					return ;
			}
			else
			{
				if (point % 10 == n - 1)
					makeboard(board, point + 11 - n, input, n);
				else
					makeboard(board, point + 1, input, n);
			}
		}
	}
	return ;
}
