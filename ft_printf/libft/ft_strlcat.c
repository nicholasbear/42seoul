/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:22:44 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/11 15:40:31 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	temp;
	int		i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	temp = dest_len;
	i = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (temp < size - 1 && src[i])
	{
		dest[temp] = src[i];
		temp++;
		i++;
	}
	dest[temp] = '\0';
	return (dest_len + src_len);
}
