/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:16:23 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/22 11:28:57 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

int	ft_strlen(char*str)
{
	int	temp;

	temp = 0;
	while (str[temp])
	{
		temp++;
	}
	return (temp);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + 48);
	}
}

void	ft_show_tab(struct s_stock_str*par)
{
	int	i;
	int	j;

	i = -1;
	while (par[++i].str != NULL)
	{
		j = -1;
		write(1, par[i].str, ft_strlen(par[i].str));
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		write(1, par[i].copy, ft_strlen(par[i].copy));
		ft_putchar('\n');
	}
}
