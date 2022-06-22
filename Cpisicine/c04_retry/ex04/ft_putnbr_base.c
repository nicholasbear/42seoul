/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:38:40 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/23 15:25:59 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

void	print(char c)
{
	write(1, &c, 1);
}

int	length(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

int	check_up(char *base)
{
	int	i;
	int	j;

	if (length(base) <= 1)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == 127 || base[i] <= 32)
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_length;
	long	temp;

	if (check_up(base))
		return ;
	temp = nbr;
	base_length = length(base);
	if (temp < 0)
	{
		temp *= -1;
		print('-');
	}
	if (temp < base_length)
		print(base[temp]);
	else
	{
		ft_putnbr_base(temp / base_length, base);
		print(base[temp % base_length]);
	}
}
