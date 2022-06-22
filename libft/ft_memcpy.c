/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:52:42 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/25 20:35:50 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	size_t			i;
	unsigned char	*ndest;
	unsigned char	*nsrc;

	ndest = (unsigned char *)dest;
	nsrc = (unsigned char *)source;
	if (ndest == NULL || source == NULL)
		return (0);
	i = 0;
	while (i < num)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (ndest);
}
