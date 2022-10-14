/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:36:00 by wookim2           #+#    #+#             */
/*   Updated: 2022/07/03 16:41:41 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_length(unsigned int a)
{
	int	i;

	i = 0;
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

static int	convert_str(unsigned int a)
{
	char	*temp;
	int		len;
	int		full_len;

	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = check_length(a);
	full_len = len;
	temp = malloc(sizeof(char) * len + 1);
	temp[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		temp[len] = "0123456789"[a % 10];
		a /= 10;
		len--;
	}
	write(1, temp, full_len);
	free(temp);
	return (full_len);
}

int	printf_u(va_list ap)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(ap, size_t);
	len = convert_str(arg);
	return (len);
}
