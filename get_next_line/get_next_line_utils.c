/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wookim2 <wookim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:56:26 by wookim2           #+#    #+#             */
/*   Updated: 2022/08/22 16:42:50 by wookim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	temp;

	temp = 0;
	while (str[temp])
	{
		temp++;
	}
	return (temp);
}

char	*ft_strdup(char *src)
{
	int		length;
	char	*copy;
	int		i;

	if (!src)
		return (NULL);
	length = ft_strlen(src);
	copy = (char *)malloc(sizeof(char) * (length + 1));
	if (!(copy))
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!temp)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(temp, s1, s1_len + 1);
	ft_strlcpy(temp + s1_len, s2, s2_len + 1);
	free(s1);
	return (temp);
}

void	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	temp;

	temp = 0;
	while (temp < size - 1 && src[temp])
	{
		dest[temp] = src[temp];
		temp++;
	}
	dest[temp] = '\0';
}
