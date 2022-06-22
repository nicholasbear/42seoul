/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:58:07 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/15 12:02:46 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	find_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	find_minus(char c)
{
	if (c == '-')
		return (1);
	else if (c == '+')
		return (2);
	else
		return (0);
}

int	isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	temp;
	int	minus;
	int	num;

	temp = 0;
	minus = 0;
	num = 0;
	while (find_space(str[temp]))
		temp++;
	while (find_minus(str[temp]))
	{
		if (find_minus(str[temp]) == 1)
			minus++;
		temp++;
	}
	while (isnum(str[temp]))
	{
		num = 10 * num +(int)str[temp++] - 48;
	}
	if (minus % 2 == 1)
		num = -num;
	return (num);
}
