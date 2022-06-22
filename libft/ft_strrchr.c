/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:15:30 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/26 02:07:13 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ret;
	size_t	i;

	ret = (char *)str;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (ret[i] == (char)c)
			return (ret + i);
		i--;
	}
	if (ret[i] == (char)c)
		return (ret);
	return (0);
}
