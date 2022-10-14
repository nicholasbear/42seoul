/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:36:59 by wookim2           #+#    #+#             */
/*   Updated: 2022/07/03 19:15:04 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static int	find_format(char const *s, va_list ap)
{
	int	len;

	len = 0;
	if (*s == 'c')
		len += printf_c(ap);
	else if (*s == 's')
		len += printf_s(ap);
	else if (*s == 'p')
		len += printf_p(ap);
	else if (*s == 'd')
		len += printf_di(ap);
	else if (*s == 'i')
		len += printf_di(ap);
	else if (*s == 'u')
		len += printf_u(ap);
	else if (*s == 'x')
		len += printf_x(ap);
	else if (*s == 'X')
		len += printf_bigx(ap);
	else if (*s == '%')
		len += printf_obelus();
	return (len);
}

static int	find_obelus(char const *s, va_list ap)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			len += find_format(s, ap);
			s++;
		}
		else
		{
			len += write(1, s, 1);
			s++;
		}
	}
	return (len);
}

int	ft_printf(char const *s, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, s);
	len = find_obelus(s, ap);
	va_end(ap);
	return (len);
}
