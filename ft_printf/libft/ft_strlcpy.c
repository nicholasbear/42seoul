/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:00:30 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/11 15:37:35 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char*dest, const char*src, size_t size)
{
	size_t	temp;

	temp = 0;
	if (size < 1)
		return (ft_strlen(src));
	while (temp < size - 1 && src[temp])
	{
		dest[temp] = src[temp];
		temp++;
	}
	dest[temp] = '\0';
	return (ft_strlen(src));
}
