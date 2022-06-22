/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:48:35 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/08 13:49:34 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int checknum[], int n)
{
	int	i;
	int	display;

	display = 1;
	i = 0;
	while (++i < n)
		if (checknum[i - 1] >= checknum[i])
			display = 0;
	if (!display)
		return ;
	i = -1;
	while (++i < n)
		ft_putchar(checknum[i] + 48);
	if (checknum[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	checknum[10];
	int	temp;
	int	i;

	i = -1;
	while (++i <= 9 )
	{
		checknum[i] = i;
	}
	while (checknum[0] <= 10 - n)
	{
		temp = n - 1;
		print(checknum, n);
		checknum[n - 1] = checknum[n - 1] + 1;
		while (temp >= 1)
		{
			if (checknum[temp] > 9)
			{
				checknum[temp] = 0;
				checknum[temp - 1]++;
			}
			temp--;
		}
	}
}
