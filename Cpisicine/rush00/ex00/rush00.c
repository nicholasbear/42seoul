/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:19:44 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/09 19:53:43 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	print_start(int column)
{
	int	a;

	a = column;
	while (column >= 1)
	{
		if (column == a)
		{
			ft_putchar('o');
		}
		else if (column == 1)
		{
			ft_putchar('o');
			ft_putchar('\n');
		}
		else
		{
			ft_putchar('-');
		}
		column--;
	}
}

void	print_end(int column)
{	
	int	a;

	a = column;
	while (column >= 1)
	{
		if (column == a)
		{
			ft_putchar('o');
		}
		else if (column == 1)
		{
			ft_putchar('o');
			ft_putchar('\n');
		}
		else
		{
			ft_putchar('-');
		}
		column--;
	}
}

void	print_middle(int column)
{
	int	a;

	a = column;
	while (column >= 1)
	{
		if (column == a)
		{
			ft_putchar('|');
		}
		else if (column == 1)
		{
			ft_putchar('|');
			ft_putchar('\n');
		}
		else
		{
			ft_putchar(' ');
		}
		column--;
	}
}

void	rush(int a, int b)
{	
	int	row;
	int	column;

	if (a < 1 || b < 1)
	{
		ft_putchar('0');
		return ;
	}
	row = b + 1;
	while (--row >= 1)
	{
		column = a;
		if (row == b)
		{
			print_start(column);
		}
		else if (row == 1)
		{
			print_end(column);
		}
		else
		{
			print_middle(column);
		}
	}
}
