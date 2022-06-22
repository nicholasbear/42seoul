/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:04:50 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/08 15:34:56 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char*str)
{
	int	temp;

	temp = 0;
	while (str[temp])
	{
		ft_putchar(str[temp]);
		temp++;
	}
}
