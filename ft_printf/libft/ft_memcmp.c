/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:41:06 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/24 01:41:13 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			n;

	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	n = 0;
	while (n < num)
	{
		if (p1[n] != p2[n])
			return (p1[n] - p2[n]);
		n++;
	}
	return (0);
}
