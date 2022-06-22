/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:06:01 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/11 10:09:30 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char*str)
{
	int		temp;
	int		num;
	char	*arr;

	arr = "0123456789abcdef";
	temp = 0;
	while (str[temp])
	{
		if (str[temp] < 127 && str[temp] >= 32)
			ft_putchar(str[temp]);
		else
		{
			ft_putchar('\\');
			num = str[temp];
			if (str[temp] < 0)
				num = str[temp] + 256;
			ft_putchar(arr[num / 16]);
			ft_putchar(arr[num % 16]);
		}			
		temp++;
	}
}
