/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicholasbear <nicholasbear@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:13:51 by wookim2           #+#    #+#             */
/*   Updated: 2022/06/23 00:47:13 by nicholasbea      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	calculate(long num, int fd)
{
	char	s[10];
	char	i;
	int		j;

	i = '0';
	j = 0;
	while (j <= 9)
	{
		s[j] = i;
		i++;
		j++;
	}
	if (num >= 10)
		calculate(num / 10, fd);
	write(fd, &s[num % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	if (fd < 0)
		return ;
	num = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	calculate(num, fd);
}
