/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:32:57 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/24 01:39:01 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*ptr1;
	size_t			n;

	ptr1 = (unsigned char *)ptr;
	n = 0;
	while (n < num)
	{
		if (ptr1[n] == (unsigned char)value)
			return (&ptr1[n]);
		n++;
	}
	return (0);
}
