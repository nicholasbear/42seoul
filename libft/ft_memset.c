/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:26:51 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/11 16:34:25 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t count)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	val;

	temp = (unsigned char *)dest;
	i = 0;
	val = (unsigned char)value;
	while (i < count)
	{
		temp[i] = val;
		i++;
	}
	return (temp);
}
