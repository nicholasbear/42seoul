/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:06:13 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/18 10:56:01 by wookim2          ###   ########.fr       */
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

void	ft_rev_int_tab(int*tab, int size)
{
	int	temp;

	temp = 0;
	while (temp < size / 2)
	{
		ft_swap(&tab[temp], &tab[size - 1 - temp]);
		temp++;
	}
}
#include <stdio.h>
int main(){
	int a[10];

	for(int i =0; i<10 ; i++)
{
	a[i] = i;
}

ft_rev_int_tab(a,10);

for(int i=0; i<10; i++)
{
	printf("%d\n",a[i]);
}
}
