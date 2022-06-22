/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:17:01 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/16 14:36:52 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	makeboard(int board[][4], int row, int col, int*input);

int	countnum(char*arr)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (arr[i])
	{
		if (arr[i] >= '1' && arr[i] <= '4')
			num++;
		i++;
	}
	if (num != 16)
		return (0);
	return (1);
}

int	(*initboard(int board[][4]))[4]
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}

int	checkinput(char*arr)
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
			if (arr[i] >= '1' && arr[i] <= '4')
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
	int	input[17];
	int	board[4][4];
	int	i;
	int	j;

	if (argc != 2 || checkinput(argv[1]) == 0 || countnum(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = -1;
	j = -1;
	while (argv[1][++i])
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			input[++j] = argv[1][i] - 48;
		}
	}
	input[16] = 0;
	makeboard(initboard(board), 0, 0, input);
	if (input[16] == 0)
		write(1, "Error\n", 6);
	return (0);
}
