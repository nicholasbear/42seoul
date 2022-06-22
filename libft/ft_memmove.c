/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 02:00:37 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/24 02:04:07 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*ndest;
	unsigned char		*nsrc;
	size_t				n;

	ndest = (unsigned char *)dest;
	nsrc = (unsigned char *)src;
	if (ndest == nsrc || num == 0)
		return (dest);
	if (dest < src)
	{
		n = -1;
		while (++n < num)
			ndest[n] = nsrc[n];
	}
	else
	{
		n = num;
		while (--n > 0)
			ndest[n] = nsrc[n];
		ndest[0] = nsrc[0];
	}
	return (dest);
}
