/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:57:19 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/25 20:54:08 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*nstr;

	i = 0;
	nstr = (char *)str;
	c = (unsigned char)c;
	while (nstr[i])
	{
		if (nstr[i] == c)
			return (nstr + i);
		i++;
	}
	if (nstr[i] == c)
		return (nstr + i);
	return (0);
}
