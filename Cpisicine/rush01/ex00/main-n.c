/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:17:01 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/16 17:37:38 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	makeboard(int board[][9], int point, int*input, int n);

int	cn(char*arr)
{
	int	i;
	int	num;
	int	res;

	i = 0;
	num = 0;
	while (arr[i])
	{
		if (arr[i] >= '1' && arr[i] <= '9')
			num++;
		i++;
	}
	res = num / 4;
	if (num % 4 == 0)
		return (res);
	else
		return (0);
}

int	(*initboard(int board[][9]))[9]
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}

int	checkinput(char*arr, int n)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (arr[++i])
	{
		if (flag == 1)
		{
			if (arr[i] != ' ' && arr[i] != '\n' )
				return (0);
			else
				flag = 0;
		}
		else
		{
			if (arr[i] >= '1' && arr[i] <= n + 48)
				flag = 1;
			else if (arr[i] == ' ' || arr[i] == '\n')
				flag = 0;
			else
				return (0);
		}
	}
	return (1);
}

int	main(int argc, char**argv)
{
	int	input[37];
	int	board[9][9];
	int	i;
	int	j;
	int	point;

	if (argc != 2 || cn(argv[1]) == 0 || checkinput(argv[1], cn(argv[1])) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = -1;
	j = -1;
	while (argv[1][++i])
		if (argv[1][i] >= '1' && argv[1][i] <= cn(argv[1]) + 48)
			input[++j] = argv[1][i] - 48;
	input[cn(argv[1]) * 4] = 0;
	point = 0;
	makeboard(initboard(board), point, input, cn(argv[1]));
	if (input[cn(argv[1]) * 4] == 0)
		write(1, "Error\n", 6);
	return (0);
}
