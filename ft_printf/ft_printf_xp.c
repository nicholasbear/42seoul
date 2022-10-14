/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xXp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:36:27 by wookim2           #+#    #+#             */
/*   Updated: 2022/07/03 16:45:37 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_check_len(unsigned long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static char	*convert_hex_lower(unsigned long long arg, int flag)
{
	int		len;
	char	*temp;

	if (arg == 0)
		return (ft_strdup("0"));
	if (flag == 8 && arg > 4294967295)
		len = 8;
	else
		len = hex_check_len(arg);
	temp = malloc(sizeof(char) * len + 1);
	temp[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		temp[len] = "0123456789abcdef"[arg % 16];
		arg /= 16;
		len--;
	}
	return (temp);
}

int	printf_p(va_list ap)
{
	unsigned long long	arg;
	int					len;
	char				*temp;

	len = 0;
	arg = va_arg(ap, unsigned long long);
	len += write(1, "0x", 2);
	temp = convert_hex_lower(arg, 16);
	len += ft_strlen(temp);
	write(1, temp, len - 2);
	free(temp);
	return (len);
}

int	printf_x(va_list ap)
{
	unsigned int	arg;
	int				len;
	char			*temp;

	arg = va_arg(ap, size_t);
	temp = convert_hex_lower(arg, 8);
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	return (len);
}

int	printf_bigx(va_list ap)
{
	unsigned int	arg;
	int				len;
	char			*temp;

	arg = va_arg(ap, size_t);
	temp = convert_hex_lower(arg, 8);
	len = 0;
	while (temp[len])
	{
		temp[len] = ft_toupper(temp[len]);
		len++;
	}
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	return (len);
}
