/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:06:43 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/08 15:38:01 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int*a, int*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int*tab, int size)
{
	int	temp;
	int	start;
	int	change;

	temp = 0;
	while (++temp < size)
	{
		start = -1;
		change = tab[temp];
		while (++start < temp)
		{
			if (tab[start] > tab[temp])
			{
				ft_swap(&tab[start], &tab[temp]);
			}
		}
	}
}
