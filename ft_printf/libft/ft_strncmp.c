/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:05:39 by wookim2           #+#    #+#             */
/*   Updated: 2022/03/11 15:39:05 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	temp;

	temp = 0;
	while (temp < n && s1[temp] && s2[temp])
	{
		if (s1[temp] < s2[temp])
			return (-1);
		if (s1[temp] > s2[temp])
			return (1);
		temp++;
	}
	if (temp == n)
		return (0);
	if (s1[temp] == '\0')
	{
		if (s2[temp] == '\0')
			return (0);
		else
			return (-1);
	}
	return (1);
}
