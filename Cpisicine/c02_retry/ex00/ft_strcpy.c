/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:53:45 by wookim2           #+#    #+#             */
/*   Updated: 2022/01/08 16:11:32 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	temp;

	temp = 0;
	while (src[temp])
	{
		dest[temp] = src[temp];
		temp++;
	}
	dest[temp] = '\0';
	return (dest);
}
