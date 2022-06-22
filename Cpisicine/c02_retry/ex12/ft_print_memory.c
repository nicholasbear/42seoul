/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:39:56 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/22 10:57:17 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_str(char*str, int num)
{
	int	temp;

	temp = 0;
	if (num > 16)
		num = 16;
	write(1, " ", 1);
	while (temp < num)
	{
		if (str[temp] >= 32 && str[temp] < 127)
			write(1, &str[temp], 1);
		else
			write(1, ".", 1);
		temp++;
	}
	write(1, "\n", 1);
}

void	chartohex(char c)
{
	char	*hex;
	int		num;
	int		temp;

	hex = "0123456789abcdef";
	temp = 0;
	if (c < 0)
	{
		num = c + 256;
		write(1, &hex[num / 16], 1);
		write(1, &hex[num % 16], 1);
	}
	else
	{
		write(1, &hex[c / 16], 1);
		write(1, &hex[c % 16], 1);
	}
}

void	print_add(void*str)
{
	int					temp;
	unsigned long long	addr;
	char				address[16];
	char				*hex;

	addr = (long)str;
	hex = "0123456789abcdef";
	temp = 16;
	while (--temp >= 0)
	{
		address[temp] = hex[addr % 16];
		addr = addr / 16;
	}
	while (++temp < 16)
	{
		write(1, &address[temp], 1);
	}
	write(1, ":", 1);
}

void	lastline(int temp, int start, int size, char*address)
{
	while (temp % 16 != 0)
	{
		write(1, " ", 1);
		write(1, " ", 1);
		if (temp % 2 == 0)
			write(1, " ", 1);
		temp++;
	}
	print_str(&address[start], size - start);
}

void	*ft_print_memory(void*addr, unsigned int size)
{
	unsigned int	temp;
	int				start;
	char			*address;

	temp = -1;
	address = addr;
	start = 0;
	if (size == 0)
		return (addr);
	while (++temp < size)
	{
		if (temp % 16 == 0)
			print_add(address + start);
		if (temp % 2 == 0)
			write(1, " ", 1);
		chartohex(address[temp]);
		if (temp % 16 == 15)
		{
			print_str(&address[start], size - start);
			start = temp + 1;
		}
	}
	lastline(temp, start, size, address);
	return (addr);
}
