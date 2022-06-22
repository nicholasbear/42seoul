/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:26:14 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/24 01:26:18 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	get_length(int nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
		return (length); 
	if (nbr < 0)
		length = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		length;
	long	temp;
	char	*res;

	length = get_length(n);
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (res == NULL)
		return (0);
	res[length] = '\0';
	length--;
	temp = n;
	if (temp < 0)
	{
		res[0] = '-';
		temp = -temp;
	}
	if (temp == 0)
		res[0] = '0';
	while (temp > 0)
	{
		res[length] = '0' + (temp % 10);
		temp = temp / 10;
		length--;
	}
	return (res);
}
