/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojjung <hojjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:53:23 by hojjung           #+#    #+#             */
/*   Updated: 2022/01/23 16:00:39 by hojjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilstr.h"

int	ft_is_str_same(char *str1, char *str2)
{
	while ((*str1 && *str2) && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return (1);
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	iter;

	iter = 0;
	while (str[iter])
	{
		iter++;
	}
	return (iter);
}

void	ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}
