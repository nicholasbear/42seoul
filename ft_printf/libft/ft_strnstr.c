/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:42:10 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/25 21:42:44 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_len;
	size_t	little_len;
	size_t	i;
	char	*temp;

	temp = (char *)big;
	if (little[0] == '\0')
		return ((char *)big);
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (big_len < little_len || len < little_len)
		return (0);
	i = 0;
	while (i + little_len <= big_len && i + little_len <= len)
	{
		if (ft_memcmp(&temp[i], little, little_len) == 0)
			return (&temp[i]);
		i++;
	}
	return (0);
}
